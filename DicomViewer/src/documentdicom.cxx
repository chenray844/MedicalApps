//qt
#include <QDebug>
#include <QString>
#include <QFileDialog>

#include "documentdicom.h"

//vtk
#include <vtkVolume16Reader.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkContourFilter.h>
#include <vtkPolyDataNormals.h>
#include <vtkImageReader2.h>
#include <vtkStreamingDemandDrivenPipeline.h>
#include <vtkMatrix4x4.h>
#include <vtkImageReslice.h>
#include <vtkLookupTable.h>
#include <vtkImageMapToColors.h>
#include <vtkImageActor.h>
#include <vtkImageData.h>
#include <vtkImageMapper3D.h>
#include <vtkInformation.h>
#include <vtkOutlineFilter.h>
#include <vtkProperty.h>
#include <vtkDICOMImageReader.h>
#include <vtkBMPReader.h>
#include <vtkPNGReader.h>
#include <vtkJPEGReader.h>
#include <vtkPolyDataNormals.h>
#include <vtkContourFilter.h>
#include <vtkSmartPointer.h>
#include <vtkStripper.h>

DocDicom::DocDicom(QObject *parent)
    :QObject(parent)
{

    this->createActions();

}

void DocDicom::createActions()
{
    myActions.resize(actCount);

    myActions[actNHDR] = new QAction("Load .nhdr",this);
    myActions[actBMP] = new QAction("Load .bmp",this);
    myActions[actJPG] = new QAction("Load .jpg",this);
    myActions[actPNG] = new QAction("Load .png",this);
    myActions[actDicom] = new QAction("Load Dicom",this);
    myActions[actMHA] = new QAction("Load .mha",this);
    myActions[actMHD] = new QAction("Load .mhd",this);
    myActions[actData] = new QAction("Show Dicom Data",this);

}

QAction *DocDicom::getAction(int id)
{
    return myActions.at(id);
}

//slot
//Load Dicom
void DocDicom::slotLoadDicom()
{
    //qDebug()<<"Load Dicom";
    QString filename = QFileDialog::getOpenFileName(new QWidget(),tr("Load Dicom File"),"","DICOM(*.nhdr *.dcm)");
    QString filePrefix = filename.left( filename.lastIndexOf("."));
    //qDebug()<<filePrefix;

    // Start by loading some data
    vtkSmartPointer<vtkImageReader2> reader = vtkSmartPointer<vtkImageReader2>::New();
    reader->SetFilePrefix(qPrintable(filePrefix));
    reader->SetDataExtent(0,63,0,63,1,93);
    reader->SetDataSpacing(3.2,3.2,1.5);
    reader->SetDataOrigin(0.0,0.0,0.0);
    reader->SetDataScalarTypeToUnsignedShort();
    reader->SetDataByteOrderToLittleEndian();
    reader->UpdateWholeExtent();

    // Calculate the center of the volume
    reader->Update();
    int extent[6];
    double spacing[3];
    double origin[3];

    reader->GetOutputInformation(0)->Get(vtkStreamingDemandDrivenPipeline::WHOLE_EXTENT(), extent);
    reader->GetOutput()->GetSpacing(spacing);
    reader->GetOutput()->GetOrigin(origin);

    double center[3];
    center[0] = origin[0] + spacing[0] * 0.5 * (extent[0] + extent[1]);
    center[1] = origin[1] + spacing[1] * 0.5 * (extent[2] + extent[3]);
    center[2] = origin[2] + spacing[2] * 0.5 * (extent[4] + extent[5]);

    // Matrices for axial, coronal, sagittal, oblique view orientations
    static double axialElements[16] = {
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,1
    };

    static double coronalElements[16] = {
      1,0,0,0,
      0,0,1,0,
      0,-1,0,0,
      0,0,0,1
    };

    static double sagittalElements[16] = {
      0,0,-1,0,
      1,0,0,0,
      0,-1,0,0,
      0,0,0,1
    };

    static double obliqueElements[16] = {
        1,0,0,0,
        0,0.866025,-0.5,0,
        0,0.5,0.866025,0,
        0,0,0,1
    };

    //Set the slice orientation
    //sagittal
    vtkSmartPointer<vtkMatrix4x4> resliceAxes = vtkSmartPointer<vtkMatrix4x4>::New();
    resliceAxes->DeepCopy(sagittalElements);
    // Set the point throught which to slice
    resliceAxes->SetElement(0,3,center[0]);
    resliceAxes->SetElement(1,3,center[1]);
    resliceAxes->SetElement(2,3,center[2]);

    //axial
    vtkSmartPointer<vtkMatrix4x4> resliceAxial = vtkSmartPointer<vtkMatrix4x4>::New();
    resliceAxial->DeepCopy(axialElements);
    resliceAxial->SetElement(0,3,center[0]);
    resliceAxial->SetElement(1,3,center[1]);
    resliceAxial->SetElement(2,3,center[2]);

    //coronal
    vtkSmartPointer<vtkMatrix4x4> resliceCoronal = vtkSmartPointer<vtkMatrix4x4>::New();
    resliceCoronal->DeepCopy(coronalElements);
    resliceCoronal->SetElement(0,3,center[0]);
    resliceCoronal->SetElement(1,3,center[1]);
    resliceCoronal->SetElement(2,3,center[2]);

    //Extract a slice in the desired orientation
    //sagittal
    vtkSmartPointer<vtkImageReslice> reslice = vtkSmartPointer<vtkImageReslice>::New();
    reslice->SetInputConnection(reader->GetOutputPort());
    reslice->SetOutputDimensionality(2);
    reslice->SetResliceAxes(resliceAxes);
    reslice->SetInterpolationModeToLinear();

    //axial
    vtkSmartPointer<vtkImageReslice> resliceAxialData = vtkSmartPointer<vtkImageReslice>::New();
    resliceAxialData->SetInputConnection(reader->GetOutputPort());
    resliceAxialData->SetOutputDimensionality(2);
    resliceAxialData->SetResliceAxes(resliceAxial);
    resliceAxialData->SetInterpolationModeToLinear();

    //coronal
    vtkSmartPointer<vtkImageReslice> resliceCoronalData = vtkSmartPointer<vtkImageReslice>::New();
    resliceCoronalData->SetInputConnection(reader->GetOutputPort());
    resliceCoronalData->SetOutputDimensionality(2);
    resliceCoronalData->SetResliceAxes(resliceCoronal);
    resliceCoronalData->SetInterpolationModeToLinear();

    //Create a greyscale lookup table
    vtkSmartPointer<vtkLookupTable> table = vtkSmartPointer<vtkLookupTable>::New();
    table->SetRange(0,2000);
    table->SetValueRange(0.0,1.0);
    table->SetSaturationRange(0.0,0.0);
    table->SetRampToLinear();
    table->Build();

    //Map the image through the lookup table
    //sagittal
    vtkSmartPointer<vtkImageMapToColors> color = vtkSmartPointer<vtkImageMapToColors>::New();
    color->SetLookupTable(table);
    color->SetInputConnection(reslice->GetOutputPort());

    //axial
    vtkSmartPointer<vtkImageMapToColors> colorAxial = vtkSmartPointer<vtkImageMapToColors>::New();
    colorAxial->SetLookupTable(table);
    colorAxial->SetInputConnection(resliceAxialData->GetOutputPort());

    //coronal
    vtkSmartPointer<vtkImageMapToColors> colorCoronal = vtkSmartPointer<vtkImageMapToColors>::New();
    colorCoronal->SetLookupTable(table);
    colorCoronal->SetInputConnection(resliceCoronalData->GetOutputPort());

    //Display the image
    //sagittal
    vtkSmartPointer<vtkImageActor> actor = vtkSmartPointer<vtkImageActor>::New();
    actor->GetMapper()->SetInputConnection(color->GetOutputPort());
    vtkSmartPointer<vtkRenderer> sagittalRenderer = vtkSmartPointer<vtkRenderer>::New();
    sagittalRenderer->AddActor(actor);

    //axial
    vtkSmartPointer<vtkImageActor> actorAxial = vtkSmartPointer<vtkImageActor>::New();
    actorAxial->GetMapper()->SetInputConnection(colorAxial->GetOutputPort());
    vtkSmartPointer<vtkRenderer> axialRenderer = vtkSmartPointer<vtkRenderer>::New();
    axialRenderer->AddActor(actorAxial);

    //coronal
    vtkSmartPointer<vtkImageActor> actorCoronal = vtkSmartPointer<vtkImageActor>::New();
    actorCoronal->GetMapper()->SetInputConnection(colorCoronal->GetOutputPort());
    vtkSmartPointer<vtkRenderer> coronalRenderer = vtkSmartPointer<vtkRenderer>::New();
    coronalRenderer->AddActor(actorCoronal);

    myRenderersMap.insert("sagittal",sagittalRenderer);
    myRenderersMap.insert("axial",axialRenderer);
    myRenderersMap.insert("coronal",coronalRenderer);

    myResliceMap.insert("sagittal",reslice);
    myResliceMap.insert("axial",resliceAxialData);
    myResliceMap.insert("coronal",resliceCoronalData);

    //using vtkVolume16Reader to read a series of 2D slices that compose the volume
    vtkSmartPointer<vtkVolume16Reader> v16 = vtkSmartPointer<vtkVolume16Reader>::New();
    v16->SetDataDimensions(64,64);
    v16->SetImageRange(1,93);
    v16->SetDataByteOrderToLittleEndian();
    v16->SetFilePrefix(qPrintable(filePrefix));
    v16->SetDataSpacing(3.2,3.2,1.5);
    v16->Update();

    myReaderV16 = v16;

    // an outline provides context around the data
    vtkSmartPointer<vtkOutlineFilter> outlineData = vtkSmartPointer<vtkOutlineFilter>::New();
    outlineData->SetInputConnection(v16->GetOutputPort());
    outlineData->Update();

    // mapper outline data
    vtkSmartPointer<vtkPolyDataMapper> mapOutline = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapOutline->SetInputConnection(outlineData->GetOutputPort());

    // actor of outline data
    vtkSmartPointer<vtkActor> outline = vtkSmartPointer<vtkActor>::New();
    outline->SetMapper(mapOutline);
    outline->GetProperty()->SetColor(0,0,0);

    // renderer to show the outline and three reslice image data plane
    vtkSmartPointer<vtkRenderer> mainRenderer = vtkSmartPointer<vtkRenderer>::New();
    mainRenderer->SetBackground(0.2,0.3,0.4);
    mainRenderer->AddActor(outline);

    // create black/white lookup table
    vtkSmartPointer<vtkLookupTable> bwLut = vtkSmartPointer<vtkLookupTable>::New();
    bwLut->SetTableRange(0,2000);
    bwLut->SetSaturationRange(0,0);
    bwLut->SetHueRange(0,0);
    bwLut->SetValueRange(0,1);
    bwLut->Build();

    // create full hue circle lookup table
    vtkSmartPointer<vtkLookupTable> hueLut = vtkSmartPointer<vtkLookupTable>::New();
    hueLut->SetTableRange(0,2000);
    hueLut->SetHueRange(0,1);
    hueLut->SetSaturationRange(1,1);
    hueLut->SetValueRange(1,1);
    hueLut->Build();

    //create a single hue but having a range lookup table
    vtkSmartPointer<vtkLookupTable> satLut = vtkSmartPointer<vtkLookupTable>::New();
    satLut->SetTableRange(0,2000);
    satLut->SetHueRange(0.6,0.6);
    satLut->SetSaturationRange(0,1);
    satLut->SetValueRange(1,1);
    satLut->Build();

    //color volume
    vtkSmartPointer<vtkImageMapToColors> bwVolume = vtkSmartPointer<vtkImageMapToColors>::New();
    bwVolume->SetInputConnection(v16->GetOutputPort());
    bwVolume->SetLookupTable(bwLut);
    bwVolume->Update();

    //create three plane
    //sagittal
    vtkSmartPointer<vtkImageActor> sagittalActor = vtkSmartPointer<vtkImageActor>::New();
    sagittalActor->GetMapper()->SetInputConnection(bwVolume->GetOutputPort());
    sagittalActor->SetDisplayExtent(32,32,0,63,0,92);

    //axial
    vtkSmartPointer<vtkImageActor> axialActor = vtkSmartPointer<vtkImageActor>::New();
    axialActor->GetMapper()->SetInputConnection(bwVolume->GetOutputPort());
    axialActor->SetDisplayExtent(0,63,0,63,46,46);

    //coronal
    vtkSmartPointer<vtkImageActor> coronalActor = vtkSmartPointer<vtkImageActor>::New();
    coronalActor->GetMapper()->SetInputConnection(bwVolume->GetOutputPort());
    coronalActor->SetDisplayExtent(0,63,32,32,0,93);

    //add actors to the main renderer
    mainRenderer->AddActor(sagittalActor);
    mainRenderer->AddActor(axialActor);
    mainRenderer->AddActor(coronalActor);

    myRenderersMap.insert("main",mainRenderer);
    //image actors
    myActorMap.insert("sagittal",sagittalActor);
    myActorMap.insert("axial",axialActor);
    myActorMap.insert("coronal",coronalActor);

    //send signals to slots, to realize update widgets
    emit this->signalUpdateReslice(myResliceMap);
    emit this->signalUpdateImageActor(myActorMap);
    emit this->signalUpdateRenderer(myRenderersMap);

    //update dicom property
    QMap<QString, QString> property;
    QString filenameProperty = filename.split("/").at(filename.split("/").size()-1);
    property.insert("filename",filenameProperty);

    emit this->signalUpdateDicomProperty(property);

}

void DocDicom::slotShowDicomProperty()
{

    //property
    QMap<QString, QString> property;

    emit this->signalUpdateDicomProperty(property);
}

void DocDicom::slotExtractSkin(bool state)
{
    //extract skin
    vtkSmartPointer<vtkContourFilter> skinExtractor = vtkSmartPointer<vtkContourFilter>::New();
    skinExtractor->SetInputConnection(myReaderV16->GetOutputPort());
    skinExtractor->SetValue(0,500);

    vtkSmartPointer<vtkPolyDataNormals> skinNormals = vtkSmartPointer<vtkPolyDataNormals>::New();
    skinNormals->SetInputConnection(skinExtractor->GetOutputPort());
    skinNormals->SetFeatureAngle(60.0);

    vtkSmartPointer<vtkStripper> skinStripper = vtkSmartPointer<vtkStripper>::New();
    skinStripper->SetInputConnection(skinNormals->GetOutputPort());

    vtkSmartPointer<vtkPolyDataMapper> skinMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    skinMapper->SetInputConnection(skinStripper->GetOutputPort());
    skinMapper->ScalarVisibilityOff();

    vtkSmartPointer<vtkActor> skin = vtkSmartPointer<vtkActor>::New();
    skin->SetMapper(skinMapper);
    skin->GetProperty()->SetDiffuseColor(1.0,0.49,0.25);
    skin->GetProperty()->SetSpecular(0.3);
    skin->GetProperty()->SetSpecularPower(20.0);
    skin->GetProperty()->SetOpacity(0.5);

    vtkSmartPointer<vtkRenderer> mainRenderer = myRenderersMap.value("main");

    emit this->signalUpdateSkinVisual(state,skin,mainRenderer);

}

void DocDicom::slotExtractBone(bool state)
{
    //Extract bone
    vtkSmartPointer<vtkContourFilter> boneExtractor = vtkSmartPointer<vtkContourFilter>::New();
    boneExtractor->SetInputConnection(myReaderV16->GetOutputPort());
    boneExtractor->SetValue(0,1150);

    vtkSmartPointer<vtkPolyDataNormals> boneNormals = vtkSmartPointer<vtkPolyDataNormals>::New();
    boneNormals->SetInputConnection(boneExtractor->GetOutputPort());
    boneNormals->SetFeatureAngle(60.0);

    vtkSmartPointer<vtkStripper> boneStripper = vtkSmartPointer<vtkStripper>::New();
    boneStripper->SetInputConnection(boneNormals->GetOutputPort());

    vtkSmartPointer<vtkPolyDataMapper> boneMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    boneMapper->SetInputConnection(boneStripper->GetOutputPort());
    boneMapper->ScalarVisibilityOff();

    vtkSmartPointer<vtkActor> bone = vtkSmartPointer<vtkActor>::New();
    bone->SetMapper(boneMapper);
    bone->GetProperty()->SetDiffuseColor(1.0,1.0,0.9412);

    vtkSmartPointer<vtkRenderer> mainRenderer = myRenderersMap.value("main");

    emit this->signalUpdateBoneVisual(state,bone,mainRenderer);
}

/*


*/

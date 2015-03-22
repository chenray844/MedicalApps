//qt
#include <QDockWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QSlider>
#include <QVBoxLayout>
#include <QDebug>

#include "mainwindow.h"
#include "dockwidget.h"
#include "documentdicom.h"

//commands
#include "vtkimagestylecommand.h"

//vtk
#include <QVTKWidget.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkImageActor.h>
#include <vtkImageViewer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderWindow.h>
#include <vtkInteractorStyleImage.h>
#include <vtkRenderer.h>
#include <vtkImageData.h>
#include <vtkInformation.h>
#include <vtkMatrix4x4.h>


MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
{
    setWindowTitle("Dicom Viewer");

    DocDicom *doc = new DocDicom;
    myDoc = doc;

    QDockWidget *dockWgt = new QDockWidget();
    dockWgt->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dockWgt->setFeatures(QDockWidget::NoDockWidgetFeatures);
    addDockWidget(Qt::LeftDockWidgetArea,dockWgt);

    DockWidget *dwgt = new DockWidget(doc);
    dockWgt->setWidget(dwgt);

    //center widget
    QWidget *wgt = new QWidget();
    wgt->setLayout(this->createViewWidget());
    this->setCentralWidget(wgt);

    //build menu
    this->buildMenu();
    //build tool bar
    this->buildToolBar();

    //showShpere();

    setMinimumSize(800,600);

    //connect signals and slots
    connect(myDoc,SIGNAL(signalUpdateDicomProperty(QMap<QString,QString>)),
            dwgt,SLOT(slotUpdateDicomProperty(QMap<QString,QString>)));

    //initialize slider value
    myAxialValue = 46;
    myCoronalValue = 32;
    mySagittalValue = 32;
}

QGridLayout *MainWindow::createViewWidget()
{
    QGridLayout *layout = new QGridLayout();
    //3D View
    QVTKWidget *mainWgt = new QVTKWidget();
    mainWgt->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    //2D View
    QVTKWidget *axialWgt = new QVTKWidget();
    axialWgt->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QVTKWidget *coronalWgt = new QVTKWidget();
    coronalWgt->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QVTKWidget *sagittalWgt = new QVTKWidget();
    sagittalWgt->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    //slider
    QSlider *axialSlider = new QSlider();
    QSlider *coronalSlider = new QSlider();
    QSlider *sagittalSlider = new QSlider();

    axialSlider->setOrientation(Qt::Horizontal);
    coronalSlider->setOrientation(Qt::Horizontal);
    sagittalSlider->setOrientation(Qt::Horizontal);

    //vertical layout
    QVBoxLayout *lva = new QVBoxLayout();
    lva->addWidget(axialSlider);
    lva->addWidget(axialWgt);

    QVBoxLayout *lvc = new QVBoxLayout();
    lvc->addWidget(coronalSlider);
    lvc->addWidget(coronalWgt);

    QVBoxLayout *lvs = new QVBoxLayout();
    lvs->addWidget(sagittalSlider);
    lvs->addWidget(sagittalWgt);

    layout->addLayout(lva,0,0);
    layout->addWidget(mainWgt,0,1);
    layout->addLayout(lvc,1,0);
    layout->addLayout(lvs,1,1);

    myMainWgt = mainWgt;
    myAxialWgt = axialWgt;
    myCornalWgt = coronalWgt;
    mySagittalWgt = sagittalWgt;

    myAxialSlider = axialSlider;
    myCoronalSlider = coronalSlider;
    mySagittalSlider = sagittalSlider;

    //connect
    //value changed
    connect(myAxialSlider,SIGNAL(valueChanged(int)),
            this,SLOT(slotAxialSliderValueChanged(int)));
    connect(myCoronalSlider,SIGNAL(valueChanged(int)),
            this,SLOT(slotCoronalSliderValueChanged(int)));
    connect(mySagittalSlider,SIGNAL(valueChanged(int)),
            this,SLOT(slotSagittalSliderValueChanged(int)));

    //press
    connect(myAxialSlider,SIGNAL(sliderPressed()),
            this,SLOT(slotAxialSliderPressed()));
    connect(myCoronalSlider,SIGNAL(sliderPressed()),
            this,SLOT(slotCoronalSliderPressed()));
    connect(mySagittalSlider,SIGNAL(sliderPressed()),
            this,SLOT(slotSagittalSliderPressed()));

    connect(myAxialSlider,SIGNAL(sliderMoved(int)),
            this,SLOT(slotAxialSliderMoved(int)));

    return layout;
}

void MainWindow::showShpere()
{
    vtkSmartPointer<vtkSphereSource> sphereSource = vtkSmartPointer<vtkSphereSource>::New();
    sphereSource->Update();

    vtkSmartPointer<vtkPolyDataMapper> sphereMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    sphereMapper->SetInputConnection(sphereSource->GetOutputPort());

    vtkSmartPointer<vtkActor> sphereActor = vtkSmartPointer<vtkActor>::New();
    sphereActor->SetMapper(sphereMapper);

    //setup window
    vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();

    //setup renderer
    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    renderWindow->AddRenderer(renderer);

    renderer->AddActor(sphereActor);
    renderer->ResetCamera();

    //myVTKWgt->SetRenderWindow(renderWindow);

}

//build menu
void MainWindow::buildMenu()
{
    //menu
    myFileMenu = this->menuBar()->addMenu(tr("&File"));
    myDataMenu = this->menuBar()->addMenu(tr("Data"));

    //add actions to file menu
    myFileMenu->addAction(myDoc->getAction(myDoc->actNHDR));
    myFileMenu->addAction(myDoc->getAction(myDoc->actBMP));
    myFileMenu->addAction(myDoc->getAction(myDoc->actJPG));
    myFileMenu->addAction(myDoc->getAction(myDoc->actPNG));
    myFileMenu->addAction(myDoc->getAction(myDoc->actDicom));
    myFileMenu->addAction(myDoc->getAction(myDoc->actMHA));
    myFileMenu->addAction(myDoc->getAction(myDoc->actMHD));

    //add actions to data menu
    myDataMenu->addAction(myDoc->getAction(myDoc->actData));

    //actions
    connect(myDoc->getAction(myDoc->actNHDR),SIGNAL(triggered()),
            myDoc,SLOT(slotLoadDicom()));
    connect(myDoc->getAction(myDoc->actData),SIGNAL(triggered()),
            myDoc,SLOT(slotShowDicomProperty()));

    //slot update renderwindow
    connect(myDoc,SIGNAL(signalUpdateRenderer(QMap<QString, vtkSmartPointer<vtkRenderer> >)),
            this,SLOT(slotUpdateRenderer(QMap<QString, vtkSmartPointer<vtkRenderer> >)));

    connect(myDoc,SIGNAL(signalUpdateReslice(QMap<QString,vtkSmartPointer<vtkImageReslice> >)),
            this,SLOT(slotUpdateReslice(QMap<QString,vtkSmartPointer<vtkImageReslice> >)));

    connect(myDoc,SIGNAL(signalUpdateImageActor(QMap<QString,vtkSmartPointer<vtkImageActor> >)),
            this,SLOT(slotUpdateImageActor(QMap<QString,vtkSmartPointer<vtkImageActor> >)));

    connect(myDoc,SIGNAL(signalUpdateSkinVisual(bool,vtkSmartPointer<vtkActor>,vtkSmartPointer<vtkRenderer>)),
            this,SLOT(slotUpdateSkinVisual(bool,vtkSmartPointer<vtkActor>,vtkSmartPointer<vtkRenderer>)));

    connect(myDoc,SIGNAL(signalUpdateBoneVisual(bool,vtkSmartPointer<vtkActor>,vtkSmartPointer<vtkRenderer>)),
            this,SLOT(slotUpdateBoneVisual(bool,vtkSmartPointer<vtkActor>,vtkSmartPointer<vtkRenderer>)));



}

//build toolbar
void MainWindow::buildToolBar()
{
    QToolBar *toolBar = new QToolBar(tr("Load data"));
    toolBar->setAllowedAreas(Qt::TopToolBarArea);
    toolBar->setOrientation(Qt::Horizontal);

    //add action
    toolBar->addAction(myDoc->getAction(myDoc->actNHDR));
    toolBar->addAction(myDoc->getAction(myDoc->actBMP));
    toolBar->addAction(myDoc->getAction(myDoc->actJPG));
    toolBar->addAction(myDoc->getAction(myDoc->actPNG));
    toolBar->addAction(myDoc->getAction(myDoc->actDicom));
    toolBar->addAction(myDoc->getAction(myDoc->actMHA));
    toolBar->addAction(myDoc->getAction(myDoc->actMHD));
    //toolBar->addAction(myDoc->getAction(myDoc->actData));

    //show data
    QToolBar *showToolBar = new QToolBar(tr("Show data"));
    showToolBar->setAllowedAreas(Qt::TopToolBarArea);
    showToolBar->setOrientation(Qt::Horizontal);

    //add actions
    showToolBar->addAction(myDoc->getAction(myDoc->actData));

    this->addToolBar(toolBar);
    this->addToolBar(showToolBar);
}

//slots
void MainWindow::slotUpdateRenderer(QMap<QString, vtkSmartPointer<vtkRenderer> > renderers)
{
    //renderer
    vtkSmartPointer<vtkRenderer> mainRenderer = renderers.value("main");
    vtkSmartPointer<vtkRenderer> sagRenderer = renderers.value("sagittal");
    vtkSmartPointer<vtkRenderer> axialRenderer = renderers.value("axial");
    vtkSmartPointer<vtkRenderer> coronalRenderer = renderers.value("coronal");

    //render windows
    //main window
    vtkSmartPointer<vtkRenderWindow> mainWin = vtkSmartPointer<vtkRenderWindow>::New();
    mainWin->AddRenderer(mainRenderer);

    //sagittal window
    vtkSmartPointer<vtkRenderWindow> sagWin = vtkSmartPointer<vtkRenderWindow>::New();
    sagWin->AddRenderer(sagRenderer);

    //axial window
    vtkSmartPointer<vtkRenderWindow> axialWin = vtkSmartPointer<vtkRenderWindow>::New();
    axialWin->AddRenderer(axialRenderer);

    //coronal window
    vtkSmartPointer<vtkRenderWindow> coronalWin = vtkSmartPointer<vtkRenderWindow>::New();
    coronalWin->AddRenderer(coronalRenderer);


    // Set up the interaction
    //sagittal
    vtkSmartPointer<vtkInteractorStyleImage> imageStyle = vtkSmartPointer<vtkInteractorStyleImage>::New();
    vtkSmartPointer<vtkRenderWindowInteractor> interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    interactor->SetInteractorStyle(imageStyle);
    sagWin->SetInteractor(interactor);

    //axial
    vtkSmartPointer<vtkInteractorStyleImage> imageStyleAxial = vtkSmartPointer<vtkInteractorStyleImage>::New();
    vtkSmartPointer<vtkRenderWindowInteractor> interactorAxial = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    interactorAxial->SetInteractorStyle(imageStyleAxial);
    axialWin->SetInteractor(interactorAxial);

    //coronal
    vtkSmartPointer<vtkInteractorStyleImage> imageStyleCoronal = vtkSmartPointer<vtkInteractorStyleImage>::New();
    vtkSmartPointer<vtkRenderWindowInteractor> interactorCoronal = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    interactorCoronal->SetInteractorStyle(imageStyleCoronal);
    coronalWin->SetInteractor(interactorCoronal);

    myMainWgt->SetRenderWindow(mainWin);
    mySagittalWgt->SetRenderWindow(sagWin);
    myAxialWgt->SetRenderWindow(axialWin);
    myCornalWgt->SetRenderWindow(coronalWin);

    mainWin->Render();
    sagWin->Render();
    axialWin->Render();
    coronalWin->Render();

    myAxialSlider->setValue(46);
    myCoronalSlider->setValue(32);
    mySagittalSlider->setValue(32);

    myAxialSlider->setRange(0,98);
    myCoronalSlider->setRange(0,63);
    mySagittalSlider->setRange(0,63);

    // Command
    //sagittal
    //vtkSmartPointer<vtkImageStyleCommand> command = vtkSmartPointer<vtkImageStyleCommand>::New();
    //command->setImageActor(mySagittalActor);
    //command->setImageReslice(mySagittalReslice);
    //command->setInteractor(interactor);

    //axial
    //vtkSmartPointer<vtkImageStyleCommand> commandAxial = vtkSmartPointer<vtkImageStyleCommand>::New();
    //commandAxial->setImageActor(myAxialActor);
    //commandAxial->setImageReslice(myAxialReslice);
    //commandAxial->setInteractor(interactorAxial);

    //coronal
    //vtkSmartPointer<vtkImageStyleCommand> commandCoronal = vtkSmartPointer<vtkImageStyleCommand>::New();
    //commandCoronal->setImageActor(myCoronalActor);
    //commandCoronal->setImageReslice(myCoronalReslice);
    //commandCoronal->setInteractor(interactorCoronal);

    // Observer
    //sagittal
    //imageStyle->AddObserver(vtkCommand::MouseMoveEvent,command);
    //imageStyle->AddObserver(vtkCommand::LeftButtonPressEvent,command);
    //imageStyle->AddObserver(vtkCommand::LeftButtonReleaseEvent,command);

    //axial
    //imageStyleAxial->AddObserver(vtkCommand::MouseMoveEvent,commandAxial);
    //imageStyleAxial->AddObserver(vtkCommand::LeftButtonPressEvent,commandAxial);
    //imageStyleAxial->AddObserver(vtkCommand::LeftButtonReleaseEvent,commandAxial);

    //coronal
    //imageStyleCoronal->AddObserver(vtkCommand::MouseMoveEvent,commandCoronal);
    //imageStyleCoronal->AddObserver(vtkCommand::LeftButtonPressEvent,commandCoronal);
    //imageStyleCoronal->AddObserver(vtkCommand::LeftButtonReleaseEvent,commandCoronal);

    //myMainWgt->update();

}

void MainWindow::slotUpdateReslice(QMap<QString, vtkSmartPointer<vtkImageReslice> > reslice)
{
    mySagittalReslice = reslice.value("sagittal");
    myAxialReslice = reslice.value("axial");
    myCoronalReslice = reslice.value("coronal");
}

void MainWindow::slotUpdateImageActor(QMap<QString, vtkSmartPointer<vtkImageActor> > actor)
{
    mySagittalActor = actor.value("sagittal");
    myAxialActor = actor.value("axial");
    myCoronalActor = actor.value("coronal");
}

//slider
void MainWindow::slotAxialSliderValueChanged(int value)
{
    myAxialActor->SetDisplayExtent(0,63,0,63,value,value);
    
    myAxialReslice->Update();
    int deltaY = value-myAxialValue;
    //qDebug()<<"valueChanged"<<value;
    //qDebug()<<"Delta"<<deltaY;

    double sliceSpacing = myAxialReslice->GetOutput()->GetSpacing()[2];
    vtkSmartPointer<vtkMatrix4x4> matrix = myAxialReslice->GetResliceAxes();

    double point[4];
    double center[4];
    point[0] = 0.0;
    point[1] = 0.0;
    point[2] = sliceSpacing * deltaY;
    point[3] = 1.0;

    matrix->MultiplyPoint(point,center);
    matrix->SetElement(0,3,center[0]);
    matrix->SetElement(1,3,center[1]);
    matrix->SetElement(2,3,center[2]);

    matrix->SetElement(2,3,sliceSpacing*value);


    myAxialWgt->GetRenderWindow()->Render();
    myMainWgt->GetRenderWindow()->Render();

}

void MainWindow::slotCoronalSliderValueChanged(int value)
{
    myCoronalActor->SetDisplayExtent(0,63,value,value,0,96);

    myCoronalReslice->Update();
    int deltaY = value - myCoronalValue;
    double sliceSpacing = myCoronalReslice->GetOutput()->GetSpacing()[2];
    vtkSmartPointer<vtkMatrix4x4> matrix = myCoronalReslice->GetResliceAxes();
    double point[4];
    double center[4];
    point[0] = 0.0;
    point[1] = 0.0;
    point[2] = sliceSpacing * deltaY;
    point[3] = 1.0;
    matrix->MultiplyPoint(point,center);
    matrix->SetElement(0,3,center[0]);
    matrix->SetElement(1,3,center[1]);
    matrix->SetElement(2,3,center[2]);

    matrix->SetElement(1,3,sliceSpacing*value);

    myCornalWgt->GetRenderWindow()->Render();
    myMainWgt->GetRenderWindow()->Render();
}

void MainWindow::slotSagittalSliderValueChanged(int value)
{
    mySagittalActor->SetDisplayExtent(value,value,0,63,0,96);

    mySagittalReslice->Update();
    int deltaY = value - mySagittalValue;
    double sliceSpacing = mySagittalReslice->GetOutput()->GetSpacing()[2];
    vtkSmartPointer<vtkMatrix4x4> matrix = mySagittalReslice->GetResliceAxes();
    double point[4];
    double center[4];
    point[0] = 0.0;
    point[1] = 0.0;
    point[2] = sliceSpacing * deltaY;
    point[3] = 1.0;
    matrix->MultiplyPoint(point,center);
    matrix->SetElement(0,3,center[0]);
    matrix->SetElement(1,3,center[1]);
    matrix->SetElement(2,3,center[2]);

    matrix->SetElement(0,3,sliceSpacing*value);

    mySagittalWgt->GetRenderWindow()->Render();
    myMainWgt->GetRenderWindow()->Render();
}

void MainWindow::slotAxialSliderPressed()
{
    myAxialValue = myAxialSlider->value();
    //qDebug()<<"Press"<<myAxialValue;

}

void MainWindow::slotCoronalSliderPressed()
{
    myCoronalValue = myCoronalSlider->value();
}

void MainWindow::slotSagittalSliderPressed()
{
    mySagittalValue = mySagittalSlider->value();
}

void MainWindow::slotAxialSliderMoved(int value)
{
    //qDebug()<<"Move"<<value;
}

void MainWindow::slotUpdateSkinVisual(bool state, vtkSmartPointer<vtkActor> actor, vtkSmartPointer<vtkRenderer> renderer)
{
    if(state)
    {
        renderer->AddActor(actor);
        //myMainWgt->GetRenderWindow()->AddRenderer(renderer);
        myMainWgt->GetRenderWindow()->Render();
    }
    else
    {
        //remove functions, TODO......
        renderer->RemoveActor(actor);
        //myMainWgt->GetRenderWindow()->AddRenderer(renderer);
        myMainWgt->GetRenderWindow()->Render();
    }
}

void MainWindow::slotUpdateBoneVisual(bool state, vtkSmartPointer<vtkActor> actor, vtkSmartPointer<vtkRenderer> renderer)
{
    if(state)
    {
        renderer->AddActor(actor);
        myMainWgt->GetRenderWindow()->Render();
    }
    else
    {
        //remove ..........
        //TODO .......
    }
}














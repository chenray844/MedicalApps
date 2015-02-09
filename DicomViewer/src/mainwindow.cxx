//qt
#include <QDockWidget>

#include "mainwindow.h"
#include "dockwidget.h"
#include "documentdicom.h"

//vtk
#include <QVTKWidget.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkImageActor.h>
#include <vtkImageViewer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>
#include <vtkRenderer.h>

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
{
    setWindowTitle("Dicom Viewer");
    //setWindowIcon(QIcon(QString("/Users/Raymond/Documents/Ray/MedicalApps/MedicalApps/DicomViewer/res/Icon.png")));

    DocDicom *doc = new DocDicom;

    QDockWidget *dockWgt = new QDockWidget();
    dockWgt->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dockWgt->setFeatures(QDockWidget::NoDockWidgetFeatures);
    addDockWidget(Qt::LeftDockWidgetArea,dockWgt);

    DockWidget *dwgt = new DockWidget(doc);
    dockWgt->setWidget(dwgt);

    //center widget
    QVTKWidget *wgt = new QVTKWidget(parent);
    myVTKWgt = wgt;
    setCentralWidget(wgt);
    //setCentralWidget(myVTKWgt);

    showShpere();

    setMinimumSize(800,600);
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

    myVTKWgt->SetRenderWindow(renderWindow);

}

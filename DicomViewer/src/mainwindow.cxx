#include "mainwindow.h"

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

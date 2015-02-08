//qt
#include <QApplication>
#include <QLabel>

//vtk
#include <vtkVersion.h>
#include <vtkImageViewer.h>
#include <vtkImageMapper3D.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkImageActor.h>
#include <vtkImageViewer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>
#include <vtkRenderer.h>
#include <vtkJPEGReader.h>

#include <QVTKWidget.h>

int main(int argc, char **argv)
{
    QApplication *app = new QApplication(argc,argv);

    QVTKWidget widget;
    widget.resize(256,256);

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

    widget.SetRenderWindow(renderWindow);
    widget.show();

    int rc = app->exec();
    return rc;
}


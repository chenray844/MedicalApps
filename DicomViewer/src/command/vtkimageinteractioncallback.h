#ifndef VTKIMAGEINTERACTIONCALLBACK_H
#define VTKIMAGEINTERACTIONCALLBACK_H

//vtk
#include <vtkCommand.h>
#include <vtkImageReslice.h>
#include <vtkRenderWindowInteractor.h>

class vtkImageInteractionCallback : public vtkCommand
{
public:
    static vtkImageInteractionCallback *New(){
        return new vtkImageInteractionCallback;
    }
    vtkImageInteractionCallback();

    void setImageReslice(vtkImageReslice *reslice);
    vtkImageReslice *getImageReslice();

    void setInteractor(vtkRenderWindowInteractor *interactor);
    vtkRenderWindowInteractor *getInteractor();

    virtual void Execute(vtkObject *, unsigned long event, void *);

private:
    int slicing;
    vtkImageReslice *imageReslice;
    vtkRenderWindowInteractor *interactor;
};


#endif // VTKIMAGEINTERACTIONCALLBACK_H


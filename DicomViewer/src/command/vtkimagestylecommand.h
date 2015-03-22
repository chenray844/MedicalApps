#ifndef VTKIMAGESTYLECOMMAND_H
#define VTKIMAGESTYLECOMMAND_H

//vtk
#include <vtkCommand.h>
#include <vtkImageReslice.h>
#include <vtkRenderWindowInteractor.h>

class vtkImageStyleCommand : public vtkCommand
{
public:
    static vtkImageStyleCommand *New();
    vtkImageStyleCommand();

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

#endif // VTKIMAGESTYLECOMMAND_H


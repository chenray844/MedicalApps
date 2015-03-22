#include "vtkimageinteractioncallback.h"

//vtk
#include <vtkMatrix4x4.h>
#include <vtkInteractorStyle.h>

vtkImageInteractionCallback::vtkImageInteractionCallback()
{
    this->slicing = 0;
    this->imageReslice = 0;
    this->interactor = 0;

}

void vtkImageInteractionCallback::setImageReslice(vtkImageReslice *reslice)
{
    this->imageReslice = reslice;

}

vtkImageReslice *vtkImageInteractionCallback::getImageReslice()
{
    return this->imageReslice;
}

void vtkImageInteractionCallback::setInteractor(vtkRenderWindowInteractor *interactor)
{
    this->interactor = interactor;
}

vtkRenderWindowInteractor *vtkImageInteractionCallback::getInteractor()
{

    return this->interactor;
}

virtual void vtkImageInteractionCallback::Execute(vtkObject *, unsigned long event, void *)
{
    vtkRenderWindowInteractor *interactor = this->getInteractor();

    int lastPos[2];
    interactor->GetLastEventPosition(lastPos);
    int currPos[2];
    interactor->GetEventPosition(currPos);

    if(event == vtkCommand::LeftButtonPressEvent)
    {
        this->slicing = 1;
    }
    else if(event == vtkCommand::LeftButtonReleaseEvent)
    {
        this->slicing = 0;
    }
    else if(event == vtkCommand::MouseMoveEvent)
    {

        if(this->slicing)
        {
            vtkImageReslice *reslice = this->imageReslice;

            int deltaY = lastPos[1] - currPos[1];

            reslice->Update();
            double sliceSpacing = reslice->GetOutput()->GetSpacing()[2];
            vtkMatrix4x4 *matrix = reslice->GetResliceAxes();

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
            interactor->Render();

        }
        else
        {
            vtkInteractorStyle *style = vtkInteractorStyle::SafeDownCast(interactor->GetInteractorStyle());
            if(style)
            {
                style->OnMouseMove();
            }
        }
    }

}

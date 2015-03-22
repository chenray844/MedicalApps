#ifndef VTKIMAGESTYLECOMMAND_H
#define VTKIMAGESTYLECOMMAND_H

//vtk
#include <vtkCommand.h>
#include <vtkImageReslice.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkMatrix4x4.h>
#include <vtkInteractorStyle.h>
#include <vtkImageData.h>
#include <vtkInformation.h>
#include <vtkImageActor.h>

class vtkImageStyleCommand : public vtkCommand
{
public:
    static vtkImageStyleCommand *New()
    {
        return new vtkImageStyleCommand;
    }
    vtkImageStyleCommand()
    {
        this->slicing = 0;
        this->imageActor = 0;
        this->imageReslice = 0;
        this->interactor = 0;
    }

    void setImageReslice(vtkImageReslice *reslice)
    {
        this->imageReslice = reslice;
    }
    vtkImageReslice *getImageReslice()
    {
        return this->imageReslice;
    }

    void setImageActor(vtkImageActor *actor)
    {
        this->imageActor = actor;
    }
    vtkImageActor *getImageActor()
    {
        return this->imageActor;
    }

    void setInteractor(vtkRenderWindowInteractor *interactor)
    {
        this->interactor = interactor;
    }
    vtkRenderWindowInteractor *getInteractor()
    {
        return this->interactor;
    }

    virtual void Execute(vtkObject *, unsigned long event, void *)
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
        else if(event == vtkCommand::MouseWheelForwardEvent)
        {}
        else if(event == vtkCommand::MouseWheelBackwardEvent)
        {}
        else if(event == vtkCommand::MouseMoveEvent)
        {
            if(this->slicing)
            {
                vtkImageReslice *reslice = this->imageReslice;
                //vtkImageActor *actor = this->imageActor;

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

                //actor->SetUserMatrix(matrix);
                //actor->SetDisplayExtent(center[0],center[0],0,63,0,96);

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

private:
    int slicing;
    vtkImageReslice *imageReslice;
    vtkImageActor *imageActor;
    vtkRenderWindowInteractor *interactor;
};

#endif // VTKIMAGESTYLECOMMAND_H


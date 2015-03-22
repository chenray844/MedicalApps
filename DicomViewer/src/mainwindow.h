#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//qt
#include <QMainWindow>
#include <QMenu>
#include <QMap>
#include <QString>
#include <QGridLayout>
#include <QSlider>

//vtk
#include <QVTKWidget.h>
#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkImageReslice.h>
#include <vtkImageActor.h>

class DocDicom;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent=0);

public slots:
    void slotUpdateRenderer(QMap<QString, vtkSmartPointer<vtkRenderer> > renderer);
    void slotUpdateReslice(QMap<QString, vtkSmartPointer<vtkImageReslice> > reslice);
    void slotUpdateImageActor(QMap<QString, vtkSmartPointer<vtkImageActor> > actor);

    void slotUpdateSkinVisual(bool state, vtkSmartPointer<vtkActor> actor, vtkSmartPointer<vtkRenderer> renderer);
    void slotUpdateBoneVisual(bool state, vtkSmartPointer<vtkActor> actor, vtkSmartPointer<vtkRenderer> renderer);

    //slider
    void slotAxialSliderValueChanged(int value);
    void slotCoronalSliderValueChanged(int value);
    void slotSagittalSliderValueChanged(int value);

    void slotAxialSliderPressed();
    void slotCoronalSliderPressed();
    void slotSagittalSliderPressed();

    void slotAxialSliderMoved(int value);

protected:
    void buildMenu();
    void buildToolBar();
    QGridLayout *createViewWidget();

private:
    void showShpere();

    //widget
    QVTKWidget *myMainWgt;
    QVTKWidget *myAxialWgt;
    QVTKWidget *myCornalWgt;
    QVTKWidget *mySagittalWgt;

    //slider
    QSlider *myAxialSlider;
    QSlider *myCoronalSlider;
    QSlider *mySagittalSlider;

    //slider value
    int myAxialValue;
    int myCoronalValue;
    int mySagittalValue;

    // Image reslice data
    vtkSmartPointer<vtkImageReslice> mySagittalReslice;
    vtkSmartPointer<vtkImageReslice> myAxialReslice;
    vtkSmartPointer<vtkImageReslice> myCoronalReslice;

    // Image Actor
    vtkSmartPointer<vtkImageActor> mySagittalActor;
    vtkSmartPointer<vtkImageActor> myAxialActor;
    vtkSmartPointer<vtkImageActor> myCoronalActor;

    //Doc
    DocDicom *myDoc;
    //menus
    QMenu *myFileMenu;
    QMenu *myDataMenu;

};


#endif // MAINWINDOW_H



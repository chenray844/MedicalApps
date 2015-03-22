#ifndef DOCUMENTDICOM_H
#define DOCUMENTDICOM_H
//qt
#include <QAction>
#include <QVector>
#include <QMap>
#include <QObject>

//vtk
#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkImageReslice.h>
#include <vtkImageActor.h>
#include <vtkVolume16Reader.h>


class DocDicom : public QObject
{
    Q_OBJECT
public:
    DocDicom(QObject *parent=0);

    enum Actions{actNHDR,actBMP,actJPG,actPNG,actDicom,actMHA,actMHD,actData,actCount};

    QAction *getAction(int id);

signals:
    void signalUpdateRenderer(QMap<QString, vtkSmartPointer<vtkRenderer> >  renderer);
    void signalUpdateReslice(QMap<QString, vtkSmartPointer<vtkImageReslice> > reslice);
    void signalUpdateImageActor(QMap<QString, vtkSmartPointer<vtkImageActor> > actor);
    void signalUpdateDicomProperty(QMap<QString, QString> property);

    void signalUpdateSkinVisual(bool state, vtkSmartPointer<vtkActor> actor, vtkSmartPointer<vtkRenderer> renderer);
    void signalUpdateBoneVisual(bool state, vtkSmartPointer<vtkActor> actor, vtkSmartPointer<vtkRenderer> renderer);

public slots:
    void slotLoadDicom();
    void slotShowDicomProperty();
    void slotExtractSkin(bool state);
    void slotExtractBone(bool state);

protected:
    void createActions();

private:
    QVector<QAction*> myActions;
    QMap<QString, vtkSmartPointer<vtkRenderer> > myRenderersMap;
    QMap<QString, vtkSmartPointer<vtkImageReslice> > myResliceMap;
    QMap<QString, vtkSmartPointer<vtkImageActor> > myActorMap;

    //reader
    vtkSmartPointer<vtkVolume16Reader> myReaderV16;

};

#endif // DOCUMENTDICOM_H


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//qt
#include <QMainWindow>

//vtk
#include <QVTKWidget.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent=0);

private:
    void showShpere();

    QVTKWidget *myVTKWgt;

};


#endif // MAINWINDOW_H



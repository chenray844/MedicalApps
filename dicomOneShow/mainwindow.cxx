//qt
#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <QDockWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>

#include <mainwindow.h>


MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
{
    //qDebug()<<"Hello Main Window";
    this->setWindowTitle(tr("DicomShower"));
    this->resize(QSize(800,600));

    QDockWidget *dockWgt = new QDockWidget(tr("Dock Widget"));
    QWidget *dWgt = new QWidget();
    //dWgt->resize(QSize(100,600));
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(new QLineEdit(tr("Hello Dock Widget")));
    dWgt->setLayout(layout);
    dockWgt->setWidget(dWgt);

    this->addDockWidget(Qt::LeftDockWidgetArea,dockWgt);

    QWidget *centerWgt = new QWidget();

    this->setCentralWidget(centerWgt);

}


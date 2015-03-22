//qt
#include <QApplication>

#include "mainwindow.h"

int main(int argc, char **argv)
{
    //QApplication app(argc,argv);
    QApplication *app = new QApplication(argc,argv);
    MainWindow *mw = new MainWindow();
    mw->show();

    int res = app->exec();

    delete mw;
    delete app;

    return res;

}



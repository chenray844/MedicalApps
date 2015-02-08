//qt
#include <QApplication>

#include "mainwindow.h"

int main(int argc, char **argv)
{
    QApplication *app = new QApplication(argc,argv);

    MainWindow *wm = new MainWindow();
    wm->show();

    int rc = app->exec();
    return rc;
}


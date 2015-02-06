//qt
#include <QApplication>
#include <QLabel>

int main(int argc, char **argv)
{
    QApplication *app = new QApplication(argc,argv);
    QLabel *label = new QLabel("Hello, Dicom Viewer");
    label->show();
    int rc = app->exec();
    return rc;
}


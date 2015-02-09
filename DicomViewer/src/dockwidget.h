#ifndef DOCKWIDGET_H
#define DOCKWIDGET_H

//qt
#include <QWidget>

#include "documentdicom.h"

class DockWidget : public QWidget
{
    Q_OBJECT
public:
    DockWidget(DocDicom *doc, QWidget *parent=0);

private:
    DocDicom *myDoc;

};

#endif // DOCKWIDGET_H


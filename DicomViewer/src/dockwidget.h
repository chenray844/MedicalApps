#ifndef DOCKWIDGET_H
#define DOCKWIDGET_H

//qt
#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QMap>
#include <QString>

#include "documentdicom.h"

class DockWidget : public QWidget
{
    Q_OBJECT
public:
    DockWidget(DocDicom *doc, QWidget *parent=0);

public slots:
    void slotUpdateDicomProperty(QMap<QString, QString> property);

protected:
    //widget
    QGroupBox *createDicomFileProperty();
    QGroupBox *createExtractWidget();

private:
    //doc
    DocDicom *myDoc;

    //Dicom file property
    QLineEdit *myFileName;

};

#endif // DOCKWIDGET_H


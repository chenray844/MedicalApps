//qt
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QToolButton>
#include <QAction>
#include <QGroupBox>
#include <QFormLayout>
#include <QLabel>
#include <QFrame>
#include <QLineEdit>
#include <QCheckBox>

#include "dockwidget.h"

DockWidget::DockWidget(DocDicom *doc, QWidget *parent)
    :QWidget(parent),myDoc(doc)
{
    //setWindowTitle("Hello");
    QVBoxLayout *layout = new QVBoxLayout();

    //add widget
    layout->addWidget(this->createDicomFileProperty());
    layout->addWidget(this->createExtractWidget());

    layout->addStretch(1);
    setLayout(layout);
    setMinimumWidth(280);
}

//widget
QGroupBox *DockWidget::createDicomFileProperty()
{
    QGroupBox *box = new QGroupBox(this);
    box->setTitle(tr("Dicom File Property"));

    QVBoxLayout *layout = new QVBoxLayout();
    QFormLayout *form = new QFormLayout();

    //file name
    myFileName = new QLineEdit();
    myFileName->setReadOnly(true);
    form->addRow(tr("FileName"),myFileName);
    //myFileName->setText(tr("Hello"));

    layout->addLayout(form);
    layout->addStretch(1);
    box->setLayout(layout);
    return box;
}

QGroupBox *DockWidget::createExtractWidget()
{
    QGroupBox *box = new QGroupBox();
    box->setTitle(tr("Extraction"));

    QVBoxLayout *layout = new QVBoxLayout();
    QCheckBox *skinBox = new QCheckBox();
    skinBox->setText(tr("Skin"));

    QCheckBox *boneBox = new QCheckBox();
    boneBox->setText(tr("Bone"));

    //connect
    connect(skinBox,SIGNAL(toggled(bool)),
            myDoc,SLOT(slotExtractSkin(bool)));
    connect(boneBox,SIGNAL(toggled(bool)),myDoc,SLOT(slotExtractBone(bool)));

    layout->addWidget(skinBox);
    layout->addWidget(boneBox);

    box->setLayout(layout);
    return box;
}

//slots
//show dicom property
void DockWidget::slotUpdateDicomProperty(QMap<QString, QString> property)
{
    QString filename = property.value("filename");
    myFileName->setText(filename);
}


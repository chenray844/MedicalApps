//qt
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>

#include "dockwidget.h"

DockWidget::DockWidget(DocDicom *doc, QWidget *parent)
    :QWidget(parent),myDoc(doc)
{
    //setWindowTitle("Hello");
    QVBoxLayout *layout = new QVBoxLayout();

    QPushButton *btn = new QPushButton("Hello");
    layout->addWidget(btn);

    layout->addStretch();
    setLayout(layout);
    setMinimumWidth(280);
}

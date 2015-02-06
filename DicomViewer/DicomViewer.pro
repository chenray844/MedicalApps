#--------------------------------------------------------------
#
# Project created by Ray Chen 2015-02-06 : 22:40:00
#
#
#--------------------------------------------------------------

QT += core gui

CONFIG += qt release

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET = DicomViewer
TEMPLATE = app

SOURCES += src/main.cxx

HEADERS +=

RESOURCES +=

ICON = res/Arcana.icns ## app icon

RCC_DIR += ./MacOSX/rcc

DESTDIR += ./MacOSX/bin

MOC_DIR += ./MacOSX/moc

OBJECTS_DIR += ./MacOSX/obj


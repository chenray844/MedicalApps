#----------------------------------------------------------------
#
# Project created by Ray Chen 2015-03-22 : 08:38:04
#
#
#----------------------------------------------------------------

QT += core gui

CONFIG += qt release

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET = DicomOneShow
TEMPLATE = app

SOURCES += \
    mainwindow.cxx \
    main.cxx

HEADERS += \
    mainwindow.h

RCC_DIR += ./MacOSX/rcc

DESTDIR += ./MacOSX/bin

MOC_DIR += ./MacOSX/moc

OBJECTS_DIR += ./MacOSX/obj


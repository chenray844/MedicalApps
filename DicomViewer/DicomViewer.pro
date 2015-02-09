#--------------------------------------------------------------
#
# Project created by Ray Chen 2015-02-06 : 22:40:00
#
#
#--------------------------------------------------------------

QT += core gui

CONFIG += qt release USE_VTK

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET = DicomViewer
TEMPLATE = app

SOURCES += src/main.cxx \
    src/mainwindow.cxx \
    src/dockwidget.cxx \
    src/documentdicom.cxx

HEADERS += \
    src/mainwindow.h \
    src/dockwidget.h \
    src/documentdicom.h

RESOURCES +=

ICON = res/Arcana.icns ## app icon

RCC_DIR += ./MacOSX/rcc

DESTDIR += ./MacOSX/bin

MOC_DIR += ./MacOSX/moc

OBJECTS_DIR += ./MacOSX/obj

INCLUDEPATH += /Users/Raymond/Documents/VTK/Install/include/vtk-6.1
#INCLUDEPATH += /Users/Raymond/Documents/ITK/Build/Install/include/ITK-4.7

LIBS += -L/Users/Raymond/Documents/VTK/Install/lib

LIBS += -lvtkChartsCore-6.1 \
-lvtkCommonColor-6.1 \
-lvtkCommonComputationalGeometry-6.1 \
-lvtkCommonCore-6.1 \
-lvtkCommonDataModel-6.1 \
-lvtkCommonExecutionModel-6.1 \
-lvtkCommonMath-6.1 \
-lvtkCommonMisc-6.1 \
-lvtkCommonSystem-6.1 \
-lvtkCommonTransforms-6.1 \
-lvtkDICOMParser-6.1 \
-lvtkDomainsChemistry-6.1 \
-lvtkFiltersAMR-6.1 \
-lvtkFiltersCore-6.1 \
-lvtkFiltersExtraction-6.1 \
-lvtkFiltersFlowPaths-6.1 \
-lvtkFiltersGeneral-6.1 \
-lvtkFiltersGeneric-6.1 \
-lvtkFiltersGeometry-6.1 \
-lvtkFiltersHybrid-6.1 \
-lvtkFiltersHyperTree-6.1 \
-lvtkFiltersImaging-6.1 \
-lvtkFiltersModeling-6.1 \
-lvtkFiltersParallel-6.1 \
-lvtkFiltersParallelImaging-6.1 \
-lvtkFiltersProgrammable-6.1 \
-lvtkFiltersSMP-6.1 \
-lvtkFiltersSelection-6.1 \
-lvtkFiltersSources-6.1 \
-lvtkFiltersStatistics-6.1 \
-lvtkFiltersTexture-6.1 \
-lvtkFiltersVerdict-6.1 \
-lvtkGUISupportQt-6.1 \
-lvtkGUISupportQtOpenGL-6.1 \
-lvtkGUISupportQtSQL-6.1 \
-lvtkGUISupportQtWebkit-6.1 \
-lvtkGeovisCore-6.1 \
-lvtkIOAMR-6.1 \
-lvtkIOCore-6.1 \
-lvtkIOEnSight-6.1 \
-lvtkIOExodus-6.1 \
-lvtkIOExport-6.1 \
-lvtkIOGeometry-6.1 \
-lvtkIOImage-6.1 \
-lvtkIOImport-6.1 \
-lvtkIOInfovis-6.1 \
-lvtkIOLSDyna-6.1 \
-lvtkIOLegacy-6.1 \
-lvtkIOMINC-6.1 \
-lvtkIOMovie-6.1 \
-lvtkIONetCDF-6.1 \
-lvtkIOPLY-6.1 \
-lvtkIOParallel-6.1 \
-lvtkIOSQL-6.1 \
-lvtkIOVideo-6.1 \
-lvtkIOXML-6.1 \
-lvtkIOXMLParser-6.1 \
-lvtkImagingColor-6.1 \
-lvtkImagingCore-6.1 \
-lvtkImagingFourier-6.1 \
-lvtkImagingGeneral-6.1 \
-lvtkImagingHybrid-6.1 \
-lvtkImagingMath-6.1 \
-lvtkImagingMorphological-6.1 \
-lvtkImagingSources-6.1 \
-lvtkImagingStatistics-6.1 \
-lvtkImagingStencil-6.1 \
-lvtkInfovisCore-6.1 \
-lvtkInfovisLayout-6.1 \
-lvtkInteractionImage-6.1 \
-lvtkInteractionStyle-6.1 \
-lvtkInteractionWidgets-6.1 \
-lvtkNetCDF-6.1 \
-lvtkNetCDF_cxx-6.1 \
-lvtkParallelCore-6.1 \
-lvtkRenderingAnnotation-6.1 \
-lvtkRenderingContext2D-6.1 \
-lvtkRenderingCore-6.1 \
-lvtkRenderingFreeType-6.1 \
-lvtkRenderingFreeTypeOpenGL-6.1 \
-lvtkRenderingGL2PS-6.1 \
-lvtkRenderingImage-6.1 \
-lvtkRenderingLIC-6.1 \
-lvtkRenderingLOD-6.1 \
-lvtkRenderingLabel-6.1 \
-lvtkRenderingOpenGL-6.1 \
-lvtkRenderingQt-6.1 \
-lvtkRenderingVolume-6.1 \
-lvtkRenderingVolumeAMR-6.1 \
-lvtkRenderingVolumeOpenGL-6.1 \
-lvtkViewsContext2D-6.1 \
-lvtkViewsCore-6.1 \
-lvtkViewsGeovis-6.1 \
-lvtkViewsInfovis-6.1 \
-lvtkViewsQt-6.1 \
-lvtkalglib-6.1 \
-lvtkexoIIc-6.1 \
-lvtkexpat-6.1 \
-lvtkfreetype-6.1 \
-lvtkftgl-6.1 \
-lvtkgl2ps-6.1 \
-lvtkhdf5-6.1 \
-lvtkhdf5_hl-6.1 \
-lvtkjpeg-6.1 \
-lvtkjsoncpp-6.1 \
-lvtklibxml2-6.1 \
-lvtkmetaio-6.1 \
-lvtkoggtheora-6.1 \
-lvtkpng-6.1 \
-lvtkproj4-6.1 \
-lvtksqlite-6.1 \
-lvtksys-6.1 \
-lvtktiff-6.1 \
-lvtkverdict-6.1 \
-lvtkzlib-6.1

DISTFILES += \
    CMakeLists.txt



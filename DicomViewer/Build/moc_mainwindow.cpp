/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[24];
    char stringdata[524];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 18), // "slotUpdateRenderer"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 43), // "QMap<QString,vtkSmartPointer<..."
QT_MOC_LITERAL(4, 75, 8), // "renderer"
QT_MOC_LITERAL(5, 84, 17), // "slotUpdateReslice"
QT_MOC_LITERAL(6, 102, 47), // "QMap<QString,vtkSmartPointer<..."
QT_MOC_LITERAL(7, 150, 7), // "reslice"
QT_MOC_LITERAL(8, 158, 20), // "slotUpdateImageActor"
QT_MOC_LITERAL(9, 179, 45), // "QMap<QString,vtkSmartPointer<..."
QT_MOC_LITERAL(10, 225, 5), // "actor"
QT_MOC_LITERAL(11, 231, 20), // "slotUpdateSkinVisual"
QT_MOC_LITERAL(12, 252, 5), // "state"
QT_MOC_LITERAL(13, 258, 25), // "vtkSmartPointer<vtkActor>"
QT_MOC_LITERAL(14, 284, 28), // "vtkSmartPointer<vtkRenderer>"
QT_MOC_LITERAL(15, 313, 20), // "slotUpdateBoneVisual"
QT_MOC_LITERAL(16, 334, 27), // "slotAxialSliderValueChanged"
QT_MOC_LITERAL(17, 362, 5), // "value"
QT_MOC_LITERAL(18, 368, 29), // "slotCoronalSliderValueChanged"
QT_MOC_LITERAL(19, 398, 30), // "slotSagittalSliderValueChanged"
QT_MOC_LITERAL(20, 429, 22), // "slotAxialSliderPressed"
QT_MOC_LITERAL(21, 452, 24), // "slotCoronalSliderPressed"
QT_MOC_LITERAL(22, 477, 25), // "slotSagittalSliderPressed"
QT_MOC_LITERAL(23, 503, 20) // "slotAxialSliderMoved"

    },
    "MainWindow\0slotUpdateRenderer\0\0"
    "QMap<QString,vtkSmartPointer<vtkRenderer> >\0"
    "renderer\0slotUpdateReslice\0"
    "QMap<QString,vtkSmartPointer<vtkImageReslice> >\0"
    "reslice\0slotUpdateImageActor\0"
    "QMap<QString,vtkSmartPointer<vtkImageActor> >\0"
    "actor\0slotUpdateSkinVisual\0state\0"
    "vtkSmartPointer<vtkActor>\0"
    "vtkSmartPointer<vtkRenderer>\0"
    "slotUpdateBoneVisual\0slotAxialSliderValueChanged\0"
    "value\0slotCoronalSliderValueChanged\0"
    "slotSagittalSliderValueChanged\0"
    "slotAxialSliderPressed\0slotCoronalSliderPressed\0"
    "slotSagittalSliderPressed\0"
    "slotAxialSliderMoved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x0a /* Public */,
       5,    1,   77,    2, 0x0a /* Public */,
       8,    1,   80,    2, 0x0a /* Public */,
      11,    3,   83,    2, 0x0a /* Public */,
      15,    3,   90,    2, 0x0a /* Public */,
      16,    1,   97,    2, 0x0a /* Public */,
      18,    1,  100,    2, 0x0a /* Public */,
      19,    1,  103,    2, 0x0a /* Public */,
      20,    0,  106,    2, 0x0a /* Public */,
      21,    0,  107,    2, 0x0a /* Public */,
      22,    0,  108,    2, 0x0a /* Public */,
      23,    1,  109,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 13, 0x80000000 | 14,   12,   10,    4,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 13, 0x80000000 | 14,   12,   10,    4,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->slotUpdateRenderer((*reinterpret_cast< QMap<QString,vtkSmartPointer<vtkRenderer> >(*)>(_a[1]))); break;
        case 1: _t->slotUpdateReslice((*reinterpret_cast< QMap<QString,vtkSmartPointer<vtkImageReslice> >(*)>(_a[1]))); break;
        case 2: _t->slotUpdateImageActor((*reinterpret_cast< QMap<QString,vtkSmartPointer<vtkImageActor> >(*)>(_a[1]))); break;
        case 3: _t->slotUpdateSkinVisual((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< vtkSmartPointer<vtkActor>(*)>(_a[2])),(*reinterpret_cast< vtkSmartPointer<vtkRenderer>(*)>(_a[3]))); break;
        case 4: _t->slotUpdateBoneVisual((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< vtkSmartPointer<vtkActor>(*)>(_a[2])),(*reinterpret_cast< vtkSmartPointer<vtkRenderer>(*)>(_a[3]))); break;
        case 5: _t->slotAxialSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->slotCoronalSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->slotSagittalSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slotAxialSliderPressed(); break;
        case 9: _t->slotCoronalSliderPressed(); break;
        case 10: _t->slotSagittalSliderPressed(); break;
        case 11: _t->slotAxialSliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'documentdicom.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/documentdicom.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'documentdicom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DocDicom_t {
    QByteArrayData data[23];
    char stringdata[467];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DocDicom_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DocDicom_t qt_meta_stringdata_DocDicom = {
    {
QT_MOC_LITERAL(0, 0, 8), // "DocDicom"
QT_MOC_LITERAL(1, 9, 20), // "signalUpdateRenderer"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 43), // "QMap<QString,vtkSmartPointer<..."
QT_MOC_LITERAL(4, 75, 8), // "renderer"
QT_MOC_LITERAL(5, 84, 19), // "signalUpdateReslice"
QT_MOC_LITERAL(6, 104, 47), // "QMap<QString,vtkSmartPointer<..."
QT_MOC_LITERAL(7, 152, 7), // "reslice"
QT_MOC_LITERAL(8, 160, 22), // "signalUpdateImageActor"
QT_MOC_LITERAL(9, 183, 45), // "QMap<QString,vtkSmartPointer<..."
QT_MOC_LITERAL(10, 229, 5), // "actor"
QT_MOC_LITERAL(11, 235, 25), // "signalUpdateDicomProperty"
QT_MOC_LITERAL(12, 261, 21), // "QMap<QString,QString>"
QT_MOC_LITERAL(13, 283, 8), // "property"
QT_MOC_LITERAL(14, 292, 22), // "signalUpdateSkinVisual"
QT_MOC_LITERAL(15, 315, 5), // "state"
QT_MOC_LITERAL(16, 321, 25), // "vtkSmartPointer<vtkActor>"
QT_MOC_LITERAL(17, 347, 28), // "vtkSmartPointer<vtkRenderer>"
QT_MOC_LITERAL(18, 376, 22), // "signalUpdateBoneVisual"
QT_MOC_LITERAL(19, 399, 13), // "slotLoadDicom"
QT_MOC_LITERAL(20, 413, 21), // "slotShowDicomProperty"
QT_MOC_LITERAL(21, 435, 15), // "slotExtractSkin"
QT_MOC_LITERAL(22, 451, 15) // "slotExtractBone"

    },
    "DocDicom\0signalUpdateRenderer\0\0"
    "QMap<QString,vtkSmartPointer<vtkRenderer> >\0"
    "renderer\0signalUpdateReslice\0"
    "QMap<QString,vtkSmartPointer<vtkImageReslice> >\0"
    "reslice\0signalUpdateImageActor\0"
    "QMap<QString,vtkSmartPointer<vtkImageActor> >\0"
    "actor\0signalUpdateDicomProperty\0"
    "QMap<QString,QString>\0property\0"
    "signalUpdateSkinVisual\0state\0"
    "vtkSmartPointer<vtkActor>\0"
    "vtkSmartPointer<vtkRenderer>\0"
    "signalUpdateBoneVisual\0slotLoadDicom\0"
    "slotShowDicomProperty\0slotExtractSkin\0"
    "slotExtractBone"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DocDicom[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       5,    1,   67,    2, 0x06 /* Public */,
       8,    1,   70,    2, 0x06 /* Public */,
      11,    1,   73,    2, 0x06 /* Public */,
      14,    3,   76,    2, 0x06 /* Public */,
      18,    3,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    0,   90,    2, 0x0a /* Public */,
      20,    0,   91,    2, 0x0a /* Public */,
      21,    1,   92,    2, 0x0a /* Public */,
      22,    1,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 16, 0x80000000 | 17,   15,   10,    4,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 16, 0x80000000 | 17,   15,   10,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,

       0        // eod
};

void DocDicom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DocDicom *_t = static_cast<DocDicom *>(_o);
        switch (_id) {
        case 0: _t->signalUpdateRenderer((*reinterpret_cast< QMap<QString,vtkSmartPointer<vtkRenderer> >(*)>(_a[1]))); break;
        case 1: _t->signalUpdateReslice((*reinterpret_cast< QMap<QString,vtkSmartPointer<vtkImageReslice> >(*)>(_a[1]))); break;
        case 2: _t->signalUpdateImageActor((*reinterpret_cast< QMap<QString,vtkSmartPointer<vtkImageActor> >(*)>(_a[1]))); break;
        case 3: _t->signalUpdateDicomProperty((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1]))); break;
        case 4: _t->signalUpdateSkinVisual((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< vtkSmartPointer<vtkActor>(*)>(_a[2])),(*reinterpret_cast< vtkSmartPointer<vtkRenderer>(*)>(_a[3]))); break;
        case 5: _t->signalUpdateBoneVisual((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< vtkSmartPointer<vtkActor>(*)>(_a[2])),(*reinterpret_cast< vtkSmartPointer<vtkRenderer>(*)>(_a[3]))); break;
        case 6: _t->slotLoadDicom(); break;
        case 7: _t->slotShowDicomProperty(); break;
        case 8: _t->slotExtractSkin((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->slotExtractBone((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DocDicom::*_t)(QMap<QString,vtkSmartPointer<vtkRenderer> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DocDicom::signalUpdateRenderer)) {
                *result = 0;
            }
        }
        {
            typedef void (DocDicom::*_t)(QMap<QString,vtkSmartPointer<vtkImageReslice> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DocDicom::signalUpdateReslice)) {
                *result = 1;
            }
        }
        {
            typedef void (DocDicom::*_t)(QMap<QString,vtkSmartPointer<vtkImageActor> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DocDicom::signalUpdateImageActor)) {
                *result = 2;
            }
        }
        {
            typedef void (DocDicom::*_t)(QMap<QString,QString> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DocDicom::signalUpdateDicomProperty)) {
                *result = 3;
            }
        }
        {
            typedef void (DocDicom::*_t)(bool , vtkSmartPointer<vtkActor> , vtkSmartPointer<vtkRenderer> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DocDicom::signalUpdateSkinVisual)) {
                *result = 4;
            }
        }
        {
            typedef void (DocDicom::*_t)(bool , vtkSmartPointer<vtkActor> , vtkSmartPointer<vtkRenderer> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DocDicom::signalUpdateBoneVisual)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject DocDicom::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DocDicom.data,
      qt_meta_data_DocDicom,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DocDicom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DocDicom::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DocDicom.stringdata))
        return static_cast<void*>(const_cast< DocDicom*>(this));
    return QObject::qt_metacast(_clname);
}

int DocDicom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void DocDicom::signalUpdateRenderer(QMap<QString,vtkSmartPointer<vtkRenderer> > _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DocDicom::signalUpdateReslice(QMap<QString,vtkSmartPointer<vtkImageReslice> > _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DocDicom::signalUpdateImageActor(QMap<QString,vtkSmartPointer<vtkImageActor> > _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DocDicom::signalUpdateDicomProperty(QMap<QString,QString> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DocDicom::signalUpdateSkinVisual(bool _t1, vtkSmartPointer<vtkActor> _t2, vtkSmartPointer<vtkRenderer> _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DocDicom::signalUpdateBoneVisual(bool _t1, vtkSmartPointer<vtkActor> _t2, vtkSmartPointer<vtkRenderer> _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'spectrmaster.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../source/spectrmaster.h"
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spectrmaster.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SpectrMaster_t {
    const uint offsetsAndSize[14];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SpectrMaster_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SpectrMaster_t qt_meta_stringdata_SpectrMaster = {
    {
QT_MOC_LITERAL(0, 12), // "SpectrMaster"
QT_MOC_LITERAL(13, 9), // "setStatus"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 12), // "DeviceStatus"
QT_MOC_LITERAL(37, 6), // "status"
QT_MOC_LITERAL(44, 14), // "getSlaveIdList"
QT_MOC_LITERAL(59, 10) // "QList<int>"

    },
    "SpectrMaster\0setStatus\0\0DeviceStatus\0"
    "status\0getSlaveIdList\0QList<int>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpectrMaster[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x0a,    1 /* Public */,
       5,    0,   29,    2, 0x0a,    3 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    0x80000000 | 6,

       0        // eod
};

void SpectrMaster::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SpectrMaster *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setStatus((*reinterpret_cast< std::add_pointer_t<DeviceStatus>>(_a[1]))); break;
        case 1: { QList<int> _r = _t->getSlaveIdList();
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject SpectrMaster::staticMetaObject = { {
    QMetaObject::SuperData::link<SpectrAbstract::staticMetaObject>(),
    qt_meta_stringdata_SpectrMaster.offsetsAndSize,
    qt_meta_data_SpectrMaster,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SpectrMaster_t
, QtPrivate::TypeAndForceComplete<SpectrMaster, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const DeviceStatus, std::false_type>, QtPrivate::TypeAndForceComplete<const QList<int>, std::false_type>


>,
    nullptr
} };


const QMetaObject *SpectrMaster::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpectrMaster::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SpectrMaster.stringdata0))
        return static_cast<void*>(this);
    return SpectrAbstract::qt_metacast(_clname);
}

int SpectrMaster::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SpectrAbstract::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

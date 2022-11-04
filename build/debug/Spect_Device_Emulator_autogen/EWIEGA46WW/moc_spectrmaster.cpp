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
#include <QtCore/QList>
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
    const uint offsetsAndSize[30];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SpectrMaster_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SpectrMaster_t qt_meta_stringdata_SpectrMaster = {
    {
QT_MOC_LITERAL(0, 12), // "SpectrMaster"
QT_MOC_LITERAL(13, 11), // "cmdReceived"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 2), // "id"
QT_MOC_LITERAL(29, 9), // "setStatus"
QT_MOC_LITERAL(39, 12), // "DeviceStatus"
QT_MOC_LITERAL(52, 6), // "status"
QT_MOC_LITERAL(59, 13), // "initSlaveList"
QT_MOC_LITERAL(73, 10), // "QList<int>"
QT_MOC_LITERAL(84, 12), // "list_slaveId"
QT_MOC_LITERAL(97, 8), // "addSlave"
QT_MOC_LITERAL(106, 11), // "removeSlave"
QT_MOC_LITERAL(118, 9), // "findSlave"
QT_MOC_LITERAL(128, 26), // "std::optional<SpectrSlave>"
QT_MOC_LITERAL(155, 11) // "countSlaves"

    },
    "SpectrMaster\0cmdReceived\0\0id\0setStatus\0"
    "DeviceStatus\0status\0initSlaveList\0"
    "QList<int>\0list_slaveId\0addSlave\0"
    "removeSlave\0findSlave\0std::optional<SpectrSlave>\0"
    "countSlaves"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpectrMaster[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   65,    2, 0x0a,    3 /* Public */,
       7,    1,   68,    2, 0x0a,    5 /* Public */,
      10,    2,   71,    2, 0x0a,    7 /* Public */,
      10,    1,   76,    2, 0x2a,   10 /* Public | MethodCloned */,
      11,    1,   79,    2, 0x0a,   12 /* Public */,
      12,    1,   82,    2, 0x10a,   14 /* Public | MethodIsConst  */,
      14,    0,   85,    2, 0x0a,   16 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5,    3,    6,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    0x80000000 | 13, QMetaType::Int,    3,
    QMetaType::Int,

       0        // eod
};

void SpectrMaster::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SpectrMaster *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->cmdReceived((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->setStatus((*reinterpret_cast< std::add_pointer_t<DeviceStatus>>(_a[1]))); break;
        case 2: _t->initSlaveList((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1]))); break;
        case 3: _t->addSlave((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<DeviceStatus>>(_a[2]))); break;
        case 4: _t->addSlave((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->removeSlave((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: { std::optional<SpectrSlave> _r = _t->findSlave((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::optional<SpectrSlave>*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->countSlaves();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SpectrMaster::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpectrMaster::cmdReceived)) {
                *result = 0;
                return;
            }
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
, QtPrivate::TypeAndForceComplete<SpectrMaster, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const DeviceStatus, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<const DeviceStatus, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<const std::optional<SpectrSlave>, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>


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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void SpectrMaster::cmdReceived(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

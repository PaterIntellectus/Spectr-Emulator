/****************************************************************************
** Meta object code from reading C++ file 'spectrabstract.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../source/spectrabstract.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spectrabstract.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SpectrAbstract_t {
    const uint offsetsAndSize[38];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SpectrAbstract_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SpectrAbstract_t qt_meta_stringdata_SpectrAbstract = {
    {
QT_MOC_LITERAL(0, 14), // "SpectrAbstract"
QT_MOC_LITERAL(15, 12), // "errorMessage"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 11), // "QStringView"
QT_MOC_LITERAL(41, 9), // "str_error"
QT_MOC_LITERAL(51, 10), // "newMessage"
QT_MOC_LITERAL(62, 7), // "message"
QT_MOC_LITERAL(70, 9), // "idChanged"
QT_MOC_LITERAL(80, 2), // "id"
QT_MOC_LITERAL(83, 13), // "statusChanged"
QT_MOC_LITERAL(97, 6), // "status"
QT_MOC_LITERAL(104, 15), // "relayValChanged"
QT_MOC_LITERAL(120, 9), // "inputsVal"
QT_MOC_LITERAL(130, 5), // "setId"
QT_MOC_LITERAL(136, 9), // "setStatus"
QT_MOC_LITERAL(146, 12), // "DeviceStatus"
QT_MOC_LITERAL(159, 11), // "toggleRelay"
QT_MOC_LITERAL(171, 8), // "relayNum"
QT_MOC_LITERAL(180, 5) // "onOff"

    },
    "SpectrAbstract\0errorMessage\0\0QStringView\0"
    "str_error\0newMessage\0message\0idChanged\0"
    "id\0statusChanged\0status\0relayValChanged\0"
    "inputsVal\0setId\0setStatus\0DeviceStatus\0"
    "toggleRelay\0relayNum\0onOff"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpectrAbstract[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x106,    1 /* Public | MethodIsConst  */,
       5,    1,   65,    2, 0x106,    3 /* Public | MethodIsConst  */,
       7,    1,   68,    2, 0x106,    5 /* Public | MethodIsConst  */,
       9,    1,   71,    2, 0x106,    7 /* Public | MethodIsConst  */,
      11,    1,   74,    2, 0x106,    9 /* Public | MethodIsConst  */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      13,    1,   77,    2, 0x0a,   11 /* Public */,
      14,    1,   80,    2, 0x0a,   13 /* Public */,
      16,    2,   83,    2, 0x0a,   15 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, 0x80000000 | 15,   10,
    QMetaType::Bool, QMetaType::Int, QMetaType::Bool,   17,   18,

       0        // eod
};

void SpectrAbstract::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SpectrAbstract *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->errorMessage((*reinterpret_cast< std::add_pointer_t<QStringView>>(_a[1]))); break;
        case 1: _t->newMessage((*reinterpret_cast< std::add_pointer_t<QStringView>>(_a[1]))); break;
        case 2: _t->idChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->statusChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->relayValChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->setId((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->setStatus((*reinterpret_cast< std::add_pointer_t<DeviceStatus>>(_a[1]))); break;
        case 7: { bool _r = _t->toggleRelay((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SpectrAbstract::*)(QStringView ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpectrAbstract::errorMessage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SpectrAbstract::*)(QStringView ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpectrAbstract::newMessage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SpectrAbstract::*)(const int ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpectrAbstract::idChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SpectrAbstract::*)(const int ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpectrAbstract::statusChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SpectrAbstract::*)(const int ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpectrAbstract::relayValChanged)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject SpectrAbstract::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SpectrAbstract.offsetsAndSize,
    qt_meta_data_SpectrAbstract,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SpectrAbstract_t
, QtPrivate::TypeAndForceComplete<SpectrAbstract, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QStringView, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QStringView, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const DeviceStatus, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *SpectrAbstract::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpectrAbstract::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SpectrAbstract.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SpectrAbstract::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void SpectrAbstract::errorMessage(QStringView _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< SpectrAbstract *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SpectrAbstract::newMessage(QStringView _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< SpectrAbstract *>(this), &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SpectrAbstract::idChanged(const int _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< SpectrAbstract *>(this), &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SpectrAbstract::statusChanged(const int _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< SpectrAbstract *>(this), &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SpectrAbstract::relayValChanged(const int _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< SpectrAbstract *>(this), &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

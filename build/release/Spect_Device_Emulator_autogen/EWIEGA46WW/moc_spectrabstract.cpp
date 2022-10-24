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
    const uint offsetsAndSize[36];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SpectrAbstract_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SpectrAbstract_t qt_meta_stringdata_SpectrAbstract = {
    {
QT_MOC_LITERAL(0, 14), // "SpectrAbstract"
QT_MOC_LITERAL(15, 12), // "errorMessage"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 9), // "str_error"
QT_MOC_LITERAL(39, 10), // "newMessage"
QT_MOC_LITERAL(50, 7), // "message"
QT_MOC_LITERAL(58, 9), // "idChanged"
QT_MOC_LITERAL(68, 2), // "id"
QT_MOC_LITERAL(71, 13), // "statusChanged"
QT_MOC_LITERAL(85, 6), // "status"
QT_MOC_LITERAL(92, 15), // "inputValChanged"
QT_MOC_LITERAL(108, 9), // "inputsVal"
QT_MOC_LITERAL(118, 5), // "setId"
QT_MOC_LITERAL(124, 9), // "setStatus"
QT_MOC_LITERAL(134, 12), // "DeviceStatus"
QT_MOC_LITERAL(147, 11), // "toggleInput"
QT_MOC_LITERAL(159, 8), // "inputNum"
QT_MOC_LITERAL(168, 5) // "onOff"

    },
    "SpectrAbstract\0errorMessage\0\0str_error\0"
    "newMessage\0message\0idChanged\0id\0"
    "statusChanged\0status\0inputValChanged\0"
    "inputsVal\0setId\0setStatus\0DeviceStatus\0"
    "toggleInput\0inputNum\0onOff"
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
       1,    1,   62,    2, 0x06,    1 /* Public */,
       4,    1,   65,    2, 0x06,    3 /* Public */,
       6,    1,   68,    2, 0x06,    5 /* Public */,
       8,    1,   71,    2, 0x06,    7 /* Public */,
      10,    1,   74,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    1,   77,    2, 0x0a,   11 /* Public */,
      13,    1,   80,    2, 0x0a,   13 /* Public */,
      15,    2,   83,    2, 0x0a,   15 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, 0x80000000 | 14,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   16,   17,

       0        // eod
};

void SpectrAbstract::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SpectrAbstract *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->errorMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->newMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->idChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->statusChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->inputValChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->setId((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->setStatus((*reinterpret_cast< std::add_pointer_t<DeviceStatus>>(_a[1]))); break;
        case 7: _t->toggleInput((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SpectrAbstract::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpectrAbstract::errorMessage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SpectrAbstract::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpectrAbstract::newMessage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SpectrAbstract::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpectrAbstract::idChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SpectrAbstract::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpectrAbstract::statusChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SpectrAbstract::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpectrAbstract::inputValChanged)) {
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
, QtPrivate::TypeAndForceComplete<SpectrAbstract, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const DeviceStatus, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


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
void SpectrAbstract::errorMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SpectrAbstract::newMessage(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SpectrAbstract::idChanged(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SpectrAbstract::statusChanged(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SpectrAbstract::inputValChanged(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

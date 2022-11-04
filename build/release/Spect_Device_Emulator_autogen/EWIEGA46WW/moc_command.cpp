/****************************************************************************
** Meta object code from reading C++ file 'command.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../source/command.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'command.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Command_t {
    const uint offsetsAndSize[44];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Command_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Command_t qt_meta_stringdata_Command = {
    {
QT_MOC_LITERAL(0, 7), // "Command"
QT_MOC_LITERAL(8, 9), // "idChanged"
QT_MOC_LITERAL(18, 0), // ""
QT_MOC_LITERAL(19, 11), // "nameChanged"
QT_MOC_LITERAL(31, 11), // "QStringView"
QT_MOC_LITERAL(43, 13), // "statusChanged"
QT_MOC_LITERAL(57, 16), // "errorCodeChanged"
QT_MOC_LITERAL(74, 12), // "errorMessage"
QT_MOC_LITERAL(87, 5), // "setId"
QT_MOC_LITERAL(93, 2), // "id"
QT_MOC_LITERAL(96, 7), // "setName"
QT_MOC_LITERAL(104, 4), // "name"
QT_MOC_LITERAL(109, 9), // "setStatus"
QT_MOC_LITERAL(119, 15), // "Command::Status"
QT_MOC_LITERAL(135, 6), // "status"
QT_MOC_LITERAL(142, 12), // "setErrorCode"
QT_MOC_LITERAL(155, 14), // "Command::Error"
QT_MOC_LITERAL(170, 9), // "errorCode"
QT_MOC_LITERAL(180, 12), // "setArguments"
QT_MOC_LITERAL(193, 9), // "Arguments"
QT_MOC_LITERAL(203, 4), // "argv"
QT_MOC_LITERAL(208, 9) // "delimeter"

    },
    "Command\0idChanged\0\0nameChanged\0"
    "QStringView\0statusChanged\0errorCodeChanged\0"
    "errorMessage\0setId\0id\0setName\0name\0"
    "setStatus\0Command::Status\0status\0"
    "setErrorCode\0Command::Error\0errorCode\0"
    "setArguments\0Arguments\0argv\0delimeter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Command[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   86,    2, 0x106,    1 /* Public | MethodIsConst  */,
       3,    1,   89,    2, 0x106,    3 /* Public | MethodIsConst  */,
       5,    1,   92,    2, 0x106,    5 /* Public | MethodIsConst  */,
       6,    1,   95,    2, 0x106,    7 /* Public | MethodIsConst  */,
       7,    1,   98,    2, 0x106,    9 /* Public | MethodIsConst  */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,  101,    2, 0x0a,   11 /* Public */,
      10,    1,  104,    2, 0x0a,   13 /* Public */,
      12,    1,  107,    2, 0x0a,   15 /* Public */,
      15,    1,  110,    2, 0x0a,   17 /* Public */,
      18,    1,  113,    2, 0x0a,   19 /* Public */,
      18,    2,  116,    2, 0x0a,   21 /* Public */,
      18,    1,  121,    2, 0x2a,   24 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 4,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QString,   20,   21,
    QMetaType::Void, 0x80000000 | 4,   20,

       0        // eod
};

void Command::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Command *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->idChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->nameChanged((*reinterpret_cast< std::add_pointer_t<QStringView>>(_a[1]))); break;
        case 2: _t->statusChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->errorCodeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->errorMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->setId((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->setName((*reinterpret_cast< std::add_pointer_t<QStringView>>(_a[1]))); break;
        case 7: _t->setStatus((*reinterpret_cast< std::add_pointer_t<Command::Status>>(_a[1]))); break;
        case 8: _t->setErrorCode((*reinterpret_cast< std::add_pointer_t<Command::Error>>(_a[1]))); break;
        case 9: _t->setArguments((*reinterpret_cast< std::add_pointer_t<Arguments>>(_a[1]))); break;
        case 10: _t->setArguments((*reinterpret_cast< std::add_pointer_t<QStringView>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 11: _t->setArguments((*reinterpret_cast< std::add_pointer_t<QStringView>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Command::*)(int ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Command::idChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Command::*)(QStringView ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Command::nameChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Command::*)(int ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Command::statusChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Command::*)(int ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Command::errorCodeChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Command::*)(const QString & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Command::errorMessage)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject Command::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Command.offsetsAndSize,
    qt_meta_data_Command,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Command_t
, QtPrivate::TypeAndForceComplete<Command, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QStringView, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QStringView, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Command::Status, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Command::Error, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Arguments &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QStringView, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QStringView, std::false_type>


>,
    nullptr
} };


const QMetaObject *Command::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Command::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Command.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Command::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Command::idChanged(int _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Command *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Command::nameChanged(QStringView _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Command *>(this), &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Command::statusChanged(int _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Command *>(this), &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Command::errorCodeChanged(int _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Command *>(this), &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Command::errorMessage(const QString & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Command *>(this), &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'spectrnetworkmanager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../source/spectrnetworkmanager.h"
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spectrnetworkmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SpectrNetworkManager_t {
    const uint offsetsAndSize[14];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SpectrNetworkManager_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SpectrNetworkManager_t qt_meta_stringdata_SpectrNetworkManager = {
    {
QT_MOC_LITERAL(0, 20), // "SpectrNetworkManager"
QT_MOC_LITERAL(21, 12), // "errorMessage"
QT_MOC_LITERAL(34, 0), // ""
QT_MOC_LITERAL(35, 11), // "QStringView"
QT_MOC_LITERAL(47, 10), // "newMessage"
QT_MOC_LITERAL(58, 7), // "message"
QT_MOC_LITERAL(66, 22) // "initConnectionSettings"

    },
    "SpectrNetworkManager\0errorMessage\0\0"
    "QStringView\0newMessage\0message\0"
    "initConnectionSettings"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpectrNetworkManager[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x06,    1 /* Public */,
       4,    1,   35,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   38,    2, 0x0a,    5 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    1,
    QMetaType::Void, 0x80000000 | 3,    5,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void SpectrNetworkManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SpectrNetworkManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->errorMessage((*reinterpret_cast< std::add_pointer_t<QStringView>>(_a[1]))); break;
        case 1: _t->newMessage((*reinterpret_cast< std::add_pointer_t<QStringView>>(_a[1]))); break;
        case 2: _t->initConnectionSettings(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SpectrNetworkManager::*)(QStringView );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpectrNetworkManager::errorMessage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SpectrNetworkManager::*)(QStringView );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpectrNetworkManager::newMessage)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SpectrNetworkManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QNetworkAccessManager::staticMetaObject>(),
    qt_meta_stringdata_SpectrNetworkManager.offsetsAndSize,
    qt_meta_data_SpectrNetworkManager,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SpectrNetworkManager_t
, QtPrivate::TypeAndForceComplete<SpectrNetworkManager, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QStringView, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QStringView, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *SpectrNetworkManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpectrNetworkManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SpectrNetworkManager.stringdata0))
        return static_cast<void*>(this);
    return QNetworkAccessManager::qt_metacast(_clname);
}

int SpectrNetworkManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QNetworkAccessManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SpectrNetworkManager::errorMessage(QStringView _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SpectrNetworkManager::newMessage(QStringView _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

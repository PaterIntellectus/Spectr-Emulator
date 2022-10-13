/****************************************************************************
** Meta object code from reading C++ file 'spectrmaster.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../source/spectrmaster.h"
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
    const uint offsetsAndSize[30];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SpectrMaster_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SpectrMaster_t qt_meta_stringdata_SpectrMaster = {
    {
QT_MOC_LITERAL(0, 12), // "SpectrMaster"
QT_MOC_LITERAL(13, 24), // "updateConnectionSettings"
QT_MOC_LITERAL(38, 0), // ""
QT_MOC_LITERAL(39, 9), // "setStatus"
QT_MOC_LITERAL(49, 12), // "DeviceStatus"
QT_MOC_LITERAL(62, 6), // "status"
QT_MOC_LITERAL(69, 11), // "sendRequest"
QT_MOC_LITERAL(81, 9), // "QUrlQuery"
QT_MOC_LITERAL(91, 5), // "query"
QT_MOC_LITERAL(97, 19), // "toggleEmulationMode"
QT_MOC_LITERAL(117, 5), // "onOff"
QT_MOC_LITERAL(123, 11), // "createQuery"
QT_MOC_LITERAL(135, 12), // "processReply"
QT_MOC_LITERAL(148, 14), // "QNetworkReply*"
QT_MOC_LITERAL(163, 5) // "reply"

    },
    "SpectrMaster\0updateConnectionSettings\0"
    "\0setStatus\0DeviceStatus\0status\0"
    "sendRequest\0QUrlQuery\0query\0"
    "toggleEmulationMode\0onOff\0createQuery\0"
    "processReply\0QNetworkReply*\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpectrMaster[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x0a,    1 /* Public */,
       3,    1,   57,    2, 0x0a,    2 /* Public */,
       6,    1,   60,    2, 0x0a,    4 /* Public */,
       6,    0,   63,    2, 0x2a,    6 /* Public | MethodCloned */,
       9,    1,   64,    2, 0x0a,    7 /* Public */,
      11,    0,   67,    2, 0x08,    9 /* Private */,
      12,    1,   68,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    0x80000000 | 7,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void SpectrMaster::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SpectrMaster *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateConnectionSettings(); break;
        case 1: _t->setStatus((*reinterpret_cast< std::add_pointer_t<DeviceStatus>>(_a[1]))); break;
        case 2: _t->sendRequest((*reinterpret_cast< std::add_pointer_t<QUrlQuery>>(_a[1]))); break;
        case 3: _t->sendRequest(); break;
        case 4: _t->toggleEmulationMode((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: { QUrlQuery _r = _t->createQuery();
            if (_a[0]) *reinterpret_cast< QUrlQuery*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->processReply((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
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
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const DeviceStatus, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QUrlQuery, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const QUrlQuery, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>


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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

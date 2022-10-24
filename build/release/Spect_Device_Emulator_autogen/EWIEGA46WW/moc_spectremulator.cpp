/****************************************************************************
** Meta object code from reading C++ file 'spectremulator.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../source/spectremulator.h"
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spectremulator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SpectrEmulator_t {
    const uint offsetsAndSize[46];
    char stringdata0[314];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SpectrEmulator_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SpectrEmulator_t qt_meta_stringdata_SpectrEmulator = {
    {
QT_MOC_LITERAL(0, 14), // "SpectrEmulator"
QT_MOC_LITERAL(15, 21), // "setConnectionSettings"
QT_MOC_LITERAL(37, 0), // ""
QT_MOC_LITERAL(38, 12), // "PairHostPort"
QT_MOC_LITERAL(51, 13), // "pair_hostPort"
QT_MOC_LITERAL(65, 19), // "toggleEmulationMode"
QT_MOC_LITERAL(85, 5), // "onOff"
QT_MOC_LITERAL(91, 11), // "sendRequest"
QT_MOC_LITERAL(103, 11), // "RequestType"
QT_MOC_LITERAL(115, 11), // "requestType"
QT_MOC_LITERAL(127, 9), // "QUrlQuery"
QT_MOC_LITERAL(137, 5), // "query"
QT_MOC_LITERAL(143, 11), // "createQuery"
QT_MOC_LITERAL(155, 12), // "processReply"
QT_MOC_LITERAL(168, 14), // "QNetworkReply*"
QT_MOC_LITERAL(183, 5), // "reply"
QT_MOC_LITERAL(189, 18), // "processGetcmdReply"
QT_MOC_LITERAL(208, 9), // "replyData"
QT_MOC_LITERAL(218, 17), // "processStcmdReply"
QT_MOC_LITERAL(236, 17), // "processSlistReply"
QT_MOC_LITERAL(254, 17), // "processFlistReply"
QT_MOC_LITERAL(272, 20), // "const QNetworkReply*"
QT_MOC_LITERAL(293, 20) // "processDownloadReply"

    },
    "SpectrEmulator\0setConnectionSettings\0"
    "\0PairHostPort\0pair_hostPort\0"
    "toggleEmulationMode\0onOff\0sendRequest\0"
    "RequestType\0requestType\0QUrlQuery\0"
    "query\0createQuery\0processReply\0"
    "QNetworkReply*\0reply\0processGetcmdReply\0"
    "replyData\0processStcmdReply\0"
    "processSlistReply\0processFlistReply\0"
    "const QNetworkReply*\0processDownloadReply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpectrEmulator[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x0a,    1 /* Public */,
       5,    1,   83,    2, 0x0a,    3 /* Public */,
       7,    2,   86,    2, 0x0a,    5 /* Public */,
       7,    1,   91,    2, 0x2a,    8 /* Public | MethodCloned */,
      12,    0,   94,    2, 0x08,   10 /* Private */,
      13,    1,   95,    2, 0x08,   11 /* Private */,
      16,    1,   98,    2, 0x08,   13 /* Private */,
      18,    1,  101,    2, 0x08,   15 /* Private */,
      19,    1,  104,    2, 0x08,   17 /* Private */,
      20,    2,  107,    2, 0x08,   19 /* Private */,
      22,    2,  112,    2, 0x08,   22 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 10,    9,   11,
    QMetaType::Void, 0x80000000 | 8,    9,
    0x80000000 | 10,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QByteArray,   15,   17,
    QMetaType::Void, 0x80000000 | 21, QMetaType::QByteArray,   15,   17,

       0        // eod
};

void SpectrEmulator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SpectrEmulator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setConnectionSettings((*reinterpret_cast< std::add_pointer_t<PairHostPort>>(_a[1]))); break;
        case 1: _t->toggleEmulationMode((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->sendRequest((*reinterpret_cast< std::add_pointer_t<RequestType>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QUrlQuery>>(_a[2]))); break;
        case 3: _t->sendRequest((*reinterpret_cast< std::add_pointer_t<RequestType>>(_a[1]))); break;
        case 4: { QUrlQuery _r = _t->createQuery();
            if (_a[0]) *reinterpret_cast< QUrlQuery*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->processReply((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 6: _t->processGetcmdReply((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->processStcmdReply((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->processSlistReply((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->processFlistReply((*reinterpret_cast< std::add_pointer_t<const QNetworkReply*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 10: _t->processDownloadReply((*reinterpret_cast< std::add_pointer_t<const QNetworkReply*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject SpectrEmulator::staticMetaObject = { {
    QMetaObject::SuperData::link<SpectrMaster::staticMetaObject>(),
    qt_meta_stringdata_SpectrEmulator.offsetsAndSize,
    qt_meta_data_SpectrEmulator,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SpectrEmulator_t
, QtPrivate::TypeAndForceComplete<SpectrEmulator, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<PairHostPort, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const RequestType, std::false_type>, QtPrivate::TypeAndForceComplete<QUrlQuery, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const RequestType, std::false_type>, QtPrivate::TypeAndForceComplete<const QUrlQuery, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QNetworkReply *, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QNetworkReply *, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>


>,
    nullptr
} };


const QMetaObject *SpectrEmulator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpectrEmulator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SpectrEmulator.stringdata0))
        return static_cast<void*>(this);
    return SpectrMaster::qt_metacast(_clname);
}

int SpectrEmulator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SpectrMaster::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

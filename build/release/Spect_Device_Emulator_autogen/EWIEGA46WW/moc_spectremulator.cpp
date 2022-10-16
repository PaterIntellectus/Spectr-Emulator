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
    const uint offsetsAndSize[42];
    char stringdata0[290];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SpectrEmulator_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SpectrEmulator_t qt_meta_stringdata_SpectrEmulator = {
    {
QT_MOC_LITERAL(0, 14), // "SpectrEmulator"
QT_MOC_LITERAL(15, 24), // "updateConnectionSettings"
QT_MOC_LITERAL(40, 0), // ""
QT_MOC_LITERAL(41, 19), // "toggleEmulationMode"
QT_MOC_LITERAL(61, 5), // "onOff"
QT_MOC_LITERAL(67, 11), // "sendRequest"
QT_MOC_LITERAL(79, 11), // "RequestType"
QT_MOC_LITERAL(91, 11), // "requestType"
QT_MOC_LITERAL(103, 9), // "QUrlQuery"
QT_MOC_LITERAL(113, 5), // "query"
QT_MOC_LITERAL(119, 11), // "createQuery"
QT_MOC_LITERAL(131, 12), // "processReply"
QT_MOC_LITERAL(144, 14), // "QNetworkReply*"
QT_MOC_LITERAL(159, 5), // "reply"
QT_MOC_LITERAL(165, 18), // "processGetcmdReply"
QT_MOC_LITERAL(184, 9), // "replyData"
QT_MOC_LITERAL(194, 17), // "processStcmdReply"
QT_MOC_LITERAL(212, 17), // "processFlistReply"
QT_MOC_LITERAL(230, 17), // "processSlistReply"
QT_MOC_LITERAL(248, 20), // "processDownloadReply"
QT_MOC_LITERAL(269, 20) // "const QNetworkReply*"

    },
    "SpectrEmulator\0updateConnectionSettings\0"
    "\0toggleEmulationMode\0onOff\0sendRequest\0"
    "RequestType\0requestType\0QUrlQuery\0"
    "query\0createQuery\0processReply\0"
    "QNetworkReply*\0reply\0processGetcmdReply\0"
    "replyData\0processStcmdReply\0"
    "processFlistReply\0processSlistReply\0"
    "processDownloadReply\0const QNetworkReply*"
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
       1,    0,   80,    2, 0x0a,    1 /* Public */,
       3,    1,   81,    2, 0x0a,    2 /* Public */,
       5,    2,   84,    2, 0x0a,    4 /* Public */,
       5,    1,   89,    2, 0x2a,    7 /* Public | MethodCloned */,
      10,    0,   92,    2, 0x08,    9 /* Private */,
      11,    1,   93,    2, 0x08,   10 /* Private */,
      14,    1,   96,    2, 0x08,   12 /* Private */,
      16,    1,   99,    2, 0x08,   14 /* Private */,
      17,    1,  102,    2, 0x08,   16 /* Private */,
      18,    1,  105,    2, 0x08,   18 /* Private */,
      19,    2,  108,    2, 0x08,   20 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,
    QMetaType::Void, 0x80000000 | 6,    7,
    0x80000000 | 8,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, 0x80000000 | 20, QMetaType::QByteArray,   13,   15,

       0        // eod
};

void SpectrEmulator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SpectrEmulator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateConnectionSettings(); break;
        case 1: _t->toggleEmulationMode((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->sendRequest((*reinterpret_cast< std::add_pointer_t<RequestType>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QUrlQuery>>(_a[2]))); break;
        case 3: _t->sendRequest((*reinterpret_cast< std::add_pointer_t<RequestType>>(_a[1]))); break;
        case 4: { QUrlQuery _r = _t->createQuery();
            if (_a[0]) *reinterpret_cast< QUrlQuery*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->processReply((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 6: _t->processGetcmdReply((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->processStcmdReply((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->processFlistReply((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->processSlistReply((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
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
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const RequestType, std::false_type>, QtPrivate::TypeAndForceComplete<QUrlQuery, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const RequestType, std::false_type>, QtPrivate::TypeAndForceComplete<const QUrlQuery, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QNetworkReply *, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>


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

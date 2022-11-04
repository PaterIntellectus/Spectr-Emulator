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
    const uint offsetsAndSize[74];
    char stringdata0[479];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SpectrEmulator_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SpectrEmulator_t qt_meta_stringdata_SpectrEmulator = {
    {
QT_MOC_LITERAL(0, 14), // "SpectrEmulator"
QT_MOC_LITERAL(15, 8), // "finished"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 22), // "initConnectionSettings"
QT_MOC_LITERAL(48, 10), // "updateHost"
QT_MOC_LITERAL(59, 11), // "QStringView"
QT_MOC_LITERAL(71, 4), // "host"
QT_MOC_LITERAL(76, 10), // "updatePort"
QT_MOC_LITERAL(87, 4), // "port"
QT_MOC_LITERAL(92, 19), // "toggleAutomaticMode"
QT_MOC_LITERAL(112, 5), // "onOff"
QT_MOC_LITERAL(118, 11), // "sendRequest"
QT_MOC_LITERAL(130, 11), // "RequestType"
QT_MOC_LITERAL(142, 11), // "requestType"
QT_MOC_LITERAL(154, 9), // "QUrlQuery"
QT_MOC_LITERAL(164, 5), // "query"
QT_MOC_LITERAL(170, 11), // "createQuery"
QT_MOC_LITERAL(182, 12), // "processReply"
QT_MOC_LITERAL(195, 14), // "QNetworkReply*"
QT_MOC_LITERAL(210, 5), // "reply"
QT_MOC_LITERAL(216, 18), // "processGetcmdReply"
QT_MOC_LITERAL(235, 9), // "replyData"
QT_MOC_LITERAL(245, 17), // "processStcmdReply"
QT_MOC_LITERAL(263, 17), // "processSlistReply"
QT_MOC_LITERAL(281, 17), // "processFlistReply"
QT_MOC_LITERAL(299, 20), // "const QNetworkReply*"
QT_MOC_LITERAL(320, 20), // "processDownloadReply"
QT_MOC_LITERAL(341, 14), // "syncWithServer"
QT_MOC_LITERAL(356, 21), // "bArr_serverParameters"
QT_MOC_LITERAL(378, 10), // "executeCmd"
QT_MOC_LITERAL(389, 7), // "Command"
QT_MOC_LITERAL(397, 3), // "cmd"
QT_MOC_LITERAL(401, 14), // "executePlayCmd"
QT_MOC_LITERAL(416, 15), // "executeQuietCmd"
QT_MOC_LITERAL(432, 14), // "executeStopCmd"
QT_MOC_LITERAL(447, 17), // "executeGetFileCmd"
QT_MOC_LITERAL(465, 13) // "executeOutCmd"

    },
    "SpectrEmulator\0finished\0\0"
    "initConnectionSettings\0updateHost\0"
    "QStringView\0host\0updatePort\0port\0"
    "toggleAutomaticMode\0onOff\0sendRequest\0"
    "RequestType\0requestType\0QUrlQuery\0"
    "query\0createQuery\0processReply\0"
    "QNetworkReply*\0reply\0processGetcmdReply\0"
    "replyData\0processStcmdReply\0"
    "processSlistReply\0processFlistReply\0"
    "const QNetworkReply*\0processDownloadReply\0"
    "syncWithServer\0bArr_serverParameters\0"
    "executeCmd\0Command\0cmd\0executePlayCmd\0"
    "executeQuietCmd\0executeStopCmd\0"
    "executeGetFileCmd\0executeOutCmd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpectrEmulator[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  140,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  143,    2, 0x0a,    3 /* Public */,
       4,    1,  144,    2, 0x0a,    4 /* Public */,
       7,    1,  147,    2, 0x0a,    6 /* Public */,
       9,    1,  150,    2, 0x0a,    8 /* Public */,
      11,    2,  153,    2, 0x0a,   10 /* Public */,
      11,    1,  158,    2, 0x2a,   13 /* Public | MethodCloned */,
      16,    0,  161,    2, 0x08,   15 /* Private */,
      17,    1,  162,    2, 0x08,   16 /* Private */,
      20,    1,  165,    2, 0x08,   18 /* Private */,
      22,    1,  168,    2, 0x08,   20 /* Private */,
      23,    1,  171,    2, 0x08,   22 /* Private */,
      24,    2,  174,    2, 0x08,   24 /* Private */,
      26,    2,  179,    2, 0x08,   27 /* Private */,
      27,    1,  184,    2, 0x08,   30 /* Private */,
      29,    1,  187,    2, 0x08,   32 /* Private */,
      32,    1,  190,    2, 0x08,   34 /* Private */,
      33,    1,  193,    2, 0x08,   36 /* Private */,
      34,    1,  196,    2, 0x08,   38 /* Private */,
      35,    1,  199,    2, 0x08,   40 /* Private */,
      36,    1,  202,    2, 0x08,   42 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::UShort,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 14,   13,   15,
    QMetaType::Void, 0x80000000 | 12,   13,
    0x80000000 | 14,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, QMetaType::QByteArray,   21,
    QMetaType::Void, QMetaType::QByteArray,   21,
    QMetaType::Void, QMetaType::QByteArray,   21,
    QMetaType::Void, 0x80000000 | 25, QMetaType::QByteArray,   19,   21,
    QMetaType::Void, 0x80000000 | 25, QMetaType::QByteArray,   19,   21,
    QMetaType::Void, QMetaType::QByteArray,   28,
    QMetaType::Void, 0x80000000 | 30,   31,
    QMetaType::Void, 0x80000000 | 30,   31,
    QMetaType::Void, 0x80000000 | 30,   31,
    QMetaType::Void, 0x80000000 | 30,   31,
    QMetaType::Void, 0x80000000 | 30,   31,
    QMetaType::Void, 0x80000000 | 30,   31,

       0        // eod
};

void SpectrEmulator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SpectrEmulator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->finished((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->initConnectionSettings(); break;
        case 2: _t->updateHost((*reinterpret_cast< std::add_pointer_t<QStringView>>(_a[1]))); break;
        case 3: _t->updatePort((*reinterpret_cast< std::add_pointer_t<quint16>>(_a[1]))); break;
        case 4: _t->toggleAutomaticMode((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->sendRequest((*reinterpret_cast< std::add_pointer_t<RequestType>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QUrlQuery>>(_a[2]))); break;
        case 6: _t->sendRequest((*reinterpret_cast< std::add_pointer_t<RequestType>>(_a[1]))); break;
        case 7: { QUrlQuery _r = _t->createQuery();
            if (_a[0]) *reinterpret_cast< QUrlQuery*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->processReply((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 9: _t->processGetcmdReply((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 10: _t->processStcmdReply((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 11: _t->processSlistReply((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 12: _t->processFlistReply((*reinterpret_cast< std::add_pointer_t<const QNetworkReply*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 13: _t->processDownloadReply((*reinterpret_cast< std::add_pointer_t<const QNetworkReply*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 14: _t->syncWithServer((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 15: _t->executeCmd((*reinterpret_cast< std::add_pointer_t<Command>>(_a[1]))); break;
        case 16: _t->executePlayCmd((*reinterpret_cast< std::add_pointer_t<Command>>(_a[1]))); break;
        case 17: _t->executeQuietCmd((*reinterpret_cast< std::add_pointer_t<Command>>(_a[1]))); break;
        case 18: _t->executeStopCmd((*reinterpret_cast< std::add_pointer_t<Command>>(_a[1]))); break;
        case 19: _t->executeGetFileCmd((*reinterpret_cast< std::add_pointer_t<Command>>(_a[1]))); break;
        case 20: _t->executeOutCmd((*reinterpret_cast< std::add_pointer_t<Command>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SpectrEmulator::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpectrEmulator::finished)) {
                *result = 0;
                return;
            }
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
, QtPrivate::TypeAndForceComplete<SpectrEmulator, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QStringView, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const quint16, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const RequestType, std::false_type>, QtPrivate::TypeAndForceComplete<QUrlQuery, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const RequestType, std::false_type>, QtPrivate::TypeAndForceComplete<const QUrlQuery, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QNetworkReply *, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QNetworkReply *, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Command &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Command &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Command &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Command &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Command &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Command &, std::false_type>


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
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void SpectrEmulator::finished(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

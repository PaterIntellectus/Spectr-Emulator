/****************************************************************************
** Meta object code from reading C++ file 'trackmanager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../source/trackmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trackmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TrackManager_t {
    const uint offsetsAndSize[50];
    char stringdata0[291];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TrackManager_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TrackManager_t qt_meta_stringdata_TrackManager = {
    {
QT_MOC_LITERAL(0, 12), // "TrackManager"
QT_MOC_LITERAL(13, 12), // "errorMessage"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 11), // "QStringView"
QT_MOC_LITERAL(39, 9), // "str_error"
QT_MOC_LITERAL(49, 10), // "newMessage"
QT_MOC_LITERAL(60, 7), // "message"
QT_MOC_LITERAL(68, 11), // "stopPlaying"
QT_MOC_LITERAL(80, 16), // "rememberTrackNum"
QT_MOC_LITERAL(97, 8), // "trackNum"
QT_MOC_LITERAL(106, 14), // "remindTrackNum"
QT_MOC_LITERAL(121, 14), // "createNewTrack"
QT_MOC_LITERAL(136, 5), // "Track"
QT_MOC_LITERAL(142, 8), // "newTrack"
QT_MOC_LITERAL(151, 9), // "trackData"
QT_MOC_LITERAL(161, 9), // "findTrack"
QT_MOC_LITERAL(171, 20), // "std::optional<Track>"
QT_MOC_LITERAL(192, 9), // "trackName"
QT_MOC_LITERAL(202, 9), // "playTrack"
QT_MOC_LITERAL(212, 6), // "volume"
QT_MOC_LITERAL(219, 19), // "calculateCrc32Track"
QT_MOC_LITERAL(239, 25), // "calculateCrc32OfAllTracks"
QT_MOC_LITERAL(265, 5), // "track"
QT_MOC_LITERAL(271, 14), // "calculateCrc32"
QT_MOC_LITERAL(286, 4) // "data"

    },
    "TrackManager\0errorMessage\0\0QStringView\0"
    "str_error\0newMessage\0message\0stopPlaying\0"
    "rememberTrackNum\0trackNum\0remindTrackNum\0"
    "createNewTrack\0Track\0newTrack\0trackData\0"
    "findTrack\0std::optional<Track>\0trackName\0"
    "playTrack\0volume\0calculateCrc32Track\0"
    "calculateCrc32OfAllTracks\0track\0"
    "calculateCrc32\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrackManager[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  110,    2, 0x106,    1 /* Public | MethodIsConst  */,
       5,    1,  113,    2, 0x106,    3 /* Public | MethodIsConst  */,
       7,    0,  116,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,  117,    2, 0x0a,    6 /* Public */,
      10,    0,  120,    2, 0x0a,    8 /* Public */,
      11,    2,  121,    2, 0x0a,    9 /* Public */,
      15,    1,  126,    2, 0x10a,   12 /* Public | MethodIsConst  */,
      18,    2,  129,    2, 0x0a,   14 /* Public */,
      18,    1,  134,    2, 0x2a,   17 /* Public | MethodCloned */,
      18,    2,  137,    2, 0x0a,   19 /* Public */,
      18,    1,  142,    2, 0x2a,   22 /* Public | MethodCloned */,
      20,    1,  145,    2, 0x10a,   24 /* Public | MethodIsConst  */,
      20,    1,  148,    2, 0x10a,   26 /* Public | MethodIsConst  */,
      21,    0,  151,    2, 0x10a,   28 /* Public | MethodIsConst  */,
      20,    1,  152,    2, 0x108,   29 /* Private | MethodIsConst  */,
      23,    1,  155,    2, 0x108,   31 /* Private | MethodIsConst  */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Int,
    QMetaType::Bool, 0x80000000 | 12, QMetaType::QByteArray,   13,   14,
    0x80000000 | 16, QMetaType::QString,   17,
    QMetaType::Bool, QMetaType::QString, QMetaType::Float,   17,   19,
    QMetaType::Bool, QMetaType::QString,   17,
    QMetaType::Bool, QMetaType::Int, QMetaType::Float,    9,   19,
    QMetaType::Bool, QMetaType::Int,    9,
    QMetaType::UInt, QMetaType::QString,   17,
    QMetaType::UInt, QMetaType::Int,    9,
    QMetaType::UInt,
    QMetaType::UInt, 0x80000000 | 12,   22,
    QMetaType::UInt, QMetaType::QByteArray,   24,

       0        // eod
};

void TrackManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TrackManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->errorMessage((*reinterpret_cast< std::add_pointer_t<QStringView>>(_a[1]))); break;
        case 1: _t->newMessage((*reinterpret_cast< std::add_pointer_t<QStringView>>(_a[1]))); break;
        case 2: _t->stopPlaying(); break;
        case 3: _t->rememberTrackNum((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: { int _r = _t->remindTrackNum();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->createNewTrack((*reinterpret_cast< std::add_pointer_t<Track>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { std::optional<Track> _r = _t->findTrack((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::optional<Track>*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->playTrack((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->playTrack((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->playTrack((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->playTrack((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { quint32 _r = _t->calculateCrc32Track((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< quint32*>(_a[0]) = std::move(_r); }  break;
        case 12: { quint32 _r = _t->calculateCrc32Track((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< quint32*>(_a[0]) = std::move(_r); }  break;
        case 13: { quint32 _r = _t->calculateCrc32OfAllTracks();
            if (_a[0]) *reinterpret_cast< quint32*>(_a[0]) = std::move(_r); }  break;
        case 14: { quint32 _r = _t->calculateCrc32Track((*reinterpret_cast< std::add_pointer_t<Track>>(_a[1])));
            if (_a[0]) *reinterpret_cast< quint32*>(_a[0]) = std::move(_r); }  break;
        case 15: { quint32 _r = _t->calculateCrc32((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])));
            if (_a[0]) *reinterpret_cast< quint32*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TrackManager::*)(QStringView ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrackManager::errorMessage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TrackManager::*)(QStringView ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrackManager::newMessage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TrackManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrackManager::stopPlaying)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject TrackManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TrackManager.offsetsAndSize,
    qt_meta_data_TrackManager,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TrackManager_t
, QtPrivate::TypeAndForceComplete<TrackManager, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QStringView, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QStringView, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const Track &, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<const std::optional<Track>, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const float, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<const float, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<const quint32, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const quint32, std::false_type>, QtPrivate::TypeAndForceComplete<const int, std::false_type>, QtPrivate::TypeAndForceComplete<const quint32, std::false_type>, QtPrivate::TypeAndForceComplete<const quint32, std::false_type>, QtPrivate::TypeAndForceComplete<const Track &, std::false_type>, QtPrivate::TypeAndForceComplete<const quint32, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>


>,
    nullptr
} };


const QMetaObject *TrackManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrackManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TrackManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TrackManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void TrackManager::errorMessage(QStringView _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< TrackManager *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TrackManager::newMessage(QStringView _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< TrackManager *>(this), &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TrackManager::stopPlaying()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'MediaPlayer.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/MediaPlayer.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MediaPlayer.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MediaPlayer_t {
    QByteArrayData data[14];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MediaPlayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MediaPlayer_t qt_meta_stringdata_MediaPlayer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MediaPlayer"
QT_MOC_LITERAL(1, 12, 16), // "downloadProgress"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 4), // "read"
QT_MOC_LITERAL(4, 35, 5), // "total"
QT_MOC_LITERAL(5, 41, 16), // "downloadFinished"
QT_MOC_LITERAL(6, 58, 14), // "playYoutubeURL"
QT_MOC_LITERAL(7, 73, 7), // "videoID"
QT_MOC_LITERAL(8, 81, 19), // "downloadYoutubeFile"
QT_MOC_LITERAL(9, 101, 12), // "loadFinished"
QT_MOC_LITERAL(10, 114, 2), // "ok"
QT_MOC_LITERAL(11, 117, 11), // "saveAndPlay"
QT_MOC_LITERAL(12, 129, 14), // "QNetworkReply*"
QT_MOC_LITERAL(13, 144, 5) // "reply"

    },
    "MediaPlayer\0downloadProgress\0\0read\0"
    "total\0downloadFinished\0playYoutubeURL\0"
    "videoID\0downloadYoutubeFile\0loadFinished\0"
    "ok\0saveAndPlay\0QNetworkReply*\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MediaPlayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       5,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   50,    2, 0x0a /* Public */,
       8,    0,   53,    2, 0x0a /* Public */,
       9,    1,   54,    2, 0x0a /* Public */,
      11,    1,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void MediaPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MediaPlayer *_t = static_cast<MediaPlayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->downloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 1: _t->downloadFinished(); break;
        case 2: _t->playYoutubeURL((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->downloadYoutubeFile(); break;
        case 4: _t->loadFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->saveAndPlay((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MediaPlayer::*_t)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MediaPlayer::downloadProgress)) {
                *result = 0;
            }
        }
        {
            typedef void (MediaPlayer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MediaPlayer::downloadFinished)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MediaPlayer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MediaPlayer.data,
      qt_meta_data_MediaPlayer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MediaPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MediaPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MediaPlayer.stringdata0))
        return static_cast<void*>(const_cast< MediaPlayer*>(this));
    return QObject::qt_metacast(_clname);
}

int MediaPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MediaPlayer::downloadProgress(qint64 _t1, qint64 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MediaPlayer::downloadFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

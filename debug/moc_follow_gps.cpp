/****************************************************************************
** Meta object code from reading C++ file 'follow_gps.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../follow_gps.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'follow_gps.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_follow_gps_t {
    QByteArrayData data[8];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_follow_gps_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_follow_gps_t qt_meta_stringdata_follow_gps = {
    {
QT_MOC_LITERAL(0, 0, 10), // "follow_gps"
QT_MOC_LITERAL(1, 11, 8), // "send_gps"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "lati"
QT_MOC_LITERAL(4, 26, 5), // "longi"
QT_MOC_LITERAL(5, 32, 14), // "take_device_id"
QT_MOC_LITERAL(6, 47, 9), // "device_id"
QT_MOC_LITERAL(7, 57, 9) // "Read_Data"

    },
    "follow_gps\0send_gps\0\0lati\0longi\0"
    "take_device_id\0device_id\0Read_Data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_follow_gps[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   34,    2, 0x0a /* Public */,
       7,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

       0        // eod
};

void follow_gps::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        follow_gps *_t = static_cast<follow_gps *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_gps((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->take_device_id((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->Read_Data(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (follow_gps::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&follow_gps::send_gps)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject follow_gps::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_follow_gps.data,
      qt_meta_data_follow_gps,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *follow_gps::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *follow_gps::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_follow_gps.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int follow_gps::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void follow_gps::send_gps(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

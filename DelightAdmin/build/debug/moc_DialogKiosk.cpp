/****************************************************************************
** Meta object code from reading C++ file 'DialogKiosk.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DialogKiosk.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DialogKiosk.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogKiosk_t {
    QByteArrayData data[12];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogKiosk_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogKiosk_t qt_meta_stringdata_DialogKiosk = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DialogKiosk"
QT_MOC_LITERAL(1, 12, 7), // "onTimer"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 14), // "onRequestReply"
QT_MOC_LITERAL(4, 36, 14), // "QtHttpRequest*"
QT_MOC_LITERAL(5, 51, 7), // "request"
QT_MOC_LITERAL(6, 59, 12), // "QtHttpReply*"
QT_MOC_LITERAL(7, 72, 5), // "reply"
QT_MOC_LITERAL(8, 78, 32), // "on_BTN_FORCE_ORDER_BLOCK_clicked"
QT_MOC_LITERAL(9, 111, 31), // "on_BTN_FORCE_ORDER_PASS_clicked"
QT_MOC_LITERAL(10, 143, 25), // "on_CB_FORCE_KIOSK_clicked"
QT_MOC_LITERAL(11, 169, 7) // "checked"

    },
    "DialogKiosk\0onTimer\0\0onRequestReply\0"
    "QtHttpRequest*\0request\0QtHttpReply*\0"
    "reply\0on_BTN_FORCE_ORDER_BLOCK_clicked\0"
    "on_BTN_FORCE_ORDER_PASS_clicked\0"
    "on_CB_FORCE_KIOSK_clicked\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogKiosk[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    2,   40,    2, 0x0a /* Public */,
       8,    0,   45,    2, 0x08 /* Private */,
       9,    0,   46,    2, 0x08 /* Private */,
      10,    1,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,

       0        // eod
};

void DialogKiosk::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogKiosk *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTimer(); break;
        case 1: _t->onRequestReply((*reinterpret_cast< QtHttpRequest*(*)>(_a[1])),(*reinterpret_cast< QtHttpReply*(*)>(_a[2]))); break;
        case 2: _t->on_BTN_FORCE_ORDER_BLOCK_clicked(); break;
        case 3: _t->on_BTN_FORCE_ORDER_PASS_clicked(); break;
        case 4: _t->on_CB_FORCE_KIOSK_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QtHttpReply* >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QtHttpRequest* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DialogKiosk::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DialogKiosk.data,
    qt_meta_data_DialogKiosk,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DialogKiosk::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogKiosk::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogKiosk.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DialogKiosk::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

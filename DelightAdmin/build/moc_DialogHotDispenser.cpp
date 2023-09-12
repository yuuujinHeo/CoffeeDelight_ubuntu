/****************************************************************************
** Meta object code from reading C++ file 'DialogHotDispenser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../DialogHotDispenser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DialogHotDispenser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogHotDispenser_t {
    QByteArrayData data[8];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogHotDispenser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogHotDispenser_t qt_meta_stringdata_DialogHotDispenser = {
    {
QT_MOC_LITERAL(0, 0, 18), // "DialogHotDispenser"
QT_MOC_LITERAL(1, 19, 7), // "onTimer"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 35), // "on_BTN_DISPENSE_HOT_BY_TIME_c..."
QT_MOC_LITERAL(4, 64, 37), // "on_BTN_DISPENSE_HOT_BY_WEIGHT..."
QT_MOC_LITERAL(5, 102, 19), // "on_BTN_TARE_clicked"
QT_MOC_LITERAL(6, 122, 24), // "on_BTN_SET_SCALE_clicked"
QT_MOC_LITERAL(7, 147, 26) // "on_BTN_SET_SCALE_2_clicked"

    },
    "DialogHotDispenser\0onTimer\0\0"
    "on_BTN_DISPENSE_HOT_BY_TIME_clicked\0"
    "on_BTN_DISPENSE_HOT_BY_WEIGHT_clicked\0"
    "on_BTN_TARE_clicked\0on_BTN_SET_SCALE_clicked\0"
    "on_BTN_SET_SCALE_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogHotDispenser[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DialogHotDispenser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogHotDispenser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTimer(); break;
        case 1: _t->on_BTN_DISPENSE_HOT_BY_TIME_clicked(); break;
        case 2: _t->on_BTN_DISPENSE_HOT_BY_WEIGHT_clicked(); break;
        case 3: _t->on_BTN_TARE_clicked(); break;
        case 4: _t->on_BTN_SET_SCALE_clicked(); break;
        case 5: _t->on_BTN_SET_SCALE_2_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DialogHotDispenser::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DialogHotDispenser.data,
    qt_meta_data_DialogHotDispenser,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DialogHotDispenser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogHotDispenser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogHotDispenser.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DialogHotDispenser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

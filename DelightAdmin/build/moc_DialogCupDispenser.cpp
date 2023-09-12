/****************************************************************************
** Meta object code from reading C++ file 'DialogCupDispenser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../DialogCupDispenser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DialogCupDispenser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogCupDispenser_t {
    QByteArrayData data[7];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogCupDispenser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogCupDispenser_t qt_meta_stringdata_DialogCupDispenser = {
    {
QT_MOC_LITERAL(0, 0, 18), // "DialogCupDispenser"
QT_MOC_LITERAL(1, 19, 7), // "onTimer"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 29), // "on_BTN_CUP_DISPENSE_1_clicked"
QT_MOC_LITERAL(4, 58, 29), // "on_BTN_CUP_DISPENSE_2_clicked"
QT_MOC_LITERAL(5, 88, 29), // "on_BTN_CUP_DISPENSE_3_clicked"
QT_MOC_LITERAL(6, 118, 29) // "on_BTN_CUP_DISPENSE_4_clicked"

    },
    "DialogCupDispenser\0onTimer\0\0"
    "on_BTN_CUP_DISPENSE_1_clicked\0"
    "on_BTN_CUP_DISPENSE_2_clicked\0"
    "on_BTN_CUP_DISPENSE_3_clicked\0"
    "on_BTN_CUP_DISPENSE_4_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogCupDispenser[] = {

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
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DialogCupDispenser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogCupDispenser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTimer(); break;
        case 1: _t->on_BTN_CUP_DISPENSE_1_clicked(); break;
        case 2: _t->on_BTN_CUP_DISPENSE_2_clicked(); break;
        case 3: _t->on_BTN_CUP_DISPENSE_3_clicked(); break;
        case 4: _t->on_BTN_CUP_DISPENSE_4_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DialogCupDispenser::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DialogCupDispenser.data,
    qt_meta_data_DialogCupDispenser,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DialogCupDispenser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogCupDispenser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogCupDispenser.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DialogCupDispenser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

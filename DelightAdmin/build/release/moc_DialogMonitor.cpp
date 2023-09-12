/****************************************************************************
** Meta object code from reading C++ file 'DialogMonitor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DialogMonitor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DialogMonitor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogMonitor_t {
    QByteArrayData data[14];
    char stringdata0[328];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogMonitor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogMonitor_t qt_meta_stringdata_DialogMonitor = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DialogMonitor"
QT_MOC_LITERAL(1, 14, 7), // "onTimer"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 18), // "ProvideContextList"
QT_MOC_LITERAL(4, 42, 3), // "pos"
QT_MOC_LITERAL(5, 46, 30), // "on_BTN_FORCE_OPERATION_clicked"
QT_MOC_LITERAL(6, 77, 32), // "on_BTN_FORCE_MAINTENANCE_clicked"
QT_MOC_LITERAL(7, 110, 32), // "on_BTN_FORCE_PREPARATION_clicked"
QT_MOC_LITERAL(8, 143, 26), // "on_BTN_FORCE_ERROR_clicked"
QT_MOC_LITERAL(9, 170, 34), // "on_CB_FORCE_MONITOR_STATUS_cl..."
QT_MOC_LITERAL(10, 205, 7), // "checked"
QT_MOC_LITERAL(11, 213, 39), // "on_BTN_FORCE_CLEAR_WAITING_LI..."
QT_MOC_LITERAL(12, 253, 41), // "on_BTN_FORCE_CLEAR_COMPLETED_..."
QT_MOC_LITERAL(13, 295, 32) // "on_CB_FORCE_CLEAR_DRINKS_clicked"

    },
    "DialogMonitor\0onTimer\0\0ProvideContextList\0"
    "pos\0on_BTN_FORCE_OPERATION_clicked\0"
    "on_BTN_FORCE_MAINTENANCE_clicked\0"
    "on_BTN_FORCE_PREPARATION_clicked\0"
    "on_BTN_FORCE_ERROR_clicked\0"
    "on_CB_FORCE_MONITOR_STATUS_clicked\0"
    "checked\0on_BTN_FORCE_CLEAR_WAITING_LIST_clicked\0"
    "on_BTN_FORCE_CLEAR_COMPLETED_LIST_clicked\0"
    "on_CB_FORCE_CLEAR_DRINKS_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogMonitor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    1,   65,    2, 0x0a /* Public */,
       5,    0,   68,    2, 0x08 /* Private */,
       6,    0,   69,    2, 0x08 /* Private */,
       7,    0,   70,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    1,   72,    2, 0x08 /* Private */,
      11,    0,   75,    2, 0x08 /* Private */,
      12,    0,   76,    2, 0x08 /* Private */,
      13,    1,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,

       0        // eod
};

void DialogMonitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogMonitor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTimer(); break;
        case 1: _t->ProvideContextList((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 2: _t->on_BTN_FORCE_OPERATION_clicked(); break;
        case 3: _t->on_BTN_FORCE_MAINTENANCE_clicked(); break;
        case 4: _t->on_BTN_FORCE_PREPARATION_clicked(); break;
        case 5: _t->on_BTN_FORCE_ERROR_clicked(); break;
        case 6: _t->on_CB_FORCE_MONITOR_STATUS_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_BTN_FORCE_CLEAR_WAITING_LIST_clicked(); break;
        case 8: _t->on_BTN_FORCE_CLEAR_COMPLETED_LIST_clicked(); break;
        case 9: _t->on_CB_FORCE_CLEAR_DRINKS_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DialogMonitor::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DialogMonitor.data,
    qt_meta_data_DialogMonitor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DialogMonitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogMonitor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogMonitor.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DialogMonitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

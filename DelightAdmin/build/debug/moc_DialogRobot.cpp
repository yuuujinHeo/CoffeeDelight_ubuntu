/****************************************************************************
** Meta object code from reading C++ file 'DialogRobot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DialogRobot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DialogRobot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogRobot_t {
    QByteArrayData data[17];
    char stringdata0[359];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogRobot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogRobot_t qt_meta_stringdata_DialogRobot = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DialogRobot"
QT_MOC_LITERAL(1, 12, 7), // "onTimer"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 14), // "onCmdConnected"
QT_MOC_LITERAL(4, 36, 17), // "onCmdDisconnected"
QT_MOC_LITERAL(5, 54, 15), // "onDataConnected"
QT_MOC_LITERAL(6, 70, 18), // "onDataDisconnected"
QT_MOC_LITERAL(7, 89, 14), // "onReadyCmdRead"
QT_MOC_LITERAL(8, 104, 15), // "onReadyDataRead"
QT_MOC_LITERAL(9, 120, 30), // "on_BTN_ROBOT_TASK_STOP_clicked"
QT_MOC_LITERAL(10, 151, 31), // "on_BTN_ROBOT_TASK_START_clicked"
QT_MOC_LITERAL(11, 183, 25), // "on_BTN_ROBOT_REAL_clicked"
QT_MOC_LITERAL(12, 209, 26), // "on_BTN_ROBOT_SIMUL_clicked"
QT_MOC_LITERAL(13, 236, 26), // "on_BTN_ROBOT_PAUSE_clicked"
QT_MOC_LITERAL(14, 263, 34), // "on_BTN_ROBOT_RESUME_OUTCOL_cl..."
QT_MOC_LITERAL(15, 298, 34), // "on_BTN_ROBOT_RESUME_PAUSED_cl..."
QT_MOC_LITERAL(16, 333, 25) // "on_BTN_ROBOT_HALT_clicked"

    },
    "DialogRobot\0onTimer\0\0onCmdConnected\0"
    "onCmdDisconnected\0onDataConnected\0"
    "onDataDisconnected\0onReadyCmdRead\0"
    "onReadyDataRead\0on_BTN_ROBOT_TASK_STOP_clicked\0"
    "on_BTN_ROBOT_TASK_START_clicked\0"
    "on_BTN_ROBOT_REAL_clicked\0"
    "on_BTN_ROBOT_SIMUL_clicked\0"
    "on_BTN_ROBOT_PAUSE_clicked\0"
    "on_BTN_ROBOT_RESUME_OUTCOL_clicked\0"
    "on_BTN_ROBOT_RESUME_PAUSED_clicked\0"
    "on_BTN_ROBOT_HALT_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogRobot[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a /* Public */,
       3,    0,   90,    2, 0x0a /* Public */,
       4,    0,   91,    2, 0x0a /* Public */,
       5,    0,   92,    2, 0x0a /* Public */,
       6,    0,   93,    2, 0x0a /* Public */,
       7,    0,   94,    2, 0x0a /* Public */,
       8,    0,   95,    2, 0x0a /* Public */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DialogRobot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogRobot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTimer(); break;
        case 1: _t->onCmdConnected(); break;
        case 2: _t->onCmdDisconnected(); break;
        case 3: _t->onDataConnected(); break;
        case 4: _t->onDataDisconnected(); break;
        case 5: _t->onReadyCmdRead(); break;
        case 6: _t->onReadyDataRead(); break;
        case 7: _t->on_BTN_ROBOT_TASK_STOP_clicked(); break;
        case 8: _t->on_BTN_ROBOT_TASK_START_clicked(); break;
        case 9: _t->on_BTN_ROBOT_REAL_clicked(); break;
        case 10: _t->on_BTN_ROBOT_SIMUL_clicked(); break;
        case 11: _t->on_BTN_ROBOT_PAUSE_clicked(); break;
        case 12: _t->on_BTN_ROBOT_RESUME_OUTCOL_clicked(); break;
        case 13: _t->on_BTN_ROBOT_RESUME_PAUSED_clicked(); break;
        case 14: _t->on_BTN_ROBOT_HALT_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DialogRobot::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DialogRobot.data,
    qt_meta_data_DialogRobot,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DialogRobot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogRobot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogRobot.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DialogRobot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
struct qt_meta_stringdata_RBTCPServer_t {
    QByteArrayData data[7];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RBTCPServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RBTCPServer_t qt_meta_stringdata_RBTCPServer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "RBTCPServer"
QT_MOC_LITERAL(1, 12, 16), // "SigNewConnection"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 16), // "SigDisConnection"
QT_MOC_LITERAL(4, 47, 15), // "RBNewConnection"
QT_MOC_LITERAL(5, 63, 20), // "RBClientDisconnected"
QT_MOC_LITERAL(6, 84, 10) // "RBReadData"

    },
    "RBTCPServer\0SigNewConnection\0\0"
    "SigDisConnection\0RBNewConnection\0"
    "RBClientDisconnected\0RBReadData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RBTCPServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RBTCPServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RBTCPServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SigNewConnection(); break;
        case 1: _t->SigDisConnection(); break;
        case 2: _t->RBNewConnection(); break;
        case 3: _t->RBClientDisconnected(); break;
        case 4: _t->RBReadData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RBTCPServer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RBTCPServer::SigNewConnection)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RBTCPServer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RBTCPServer::SigDisConnection)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject RBTCPServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QTcpServer::staticMetaObject>(),
    qt_meta_stringdata_RBTCPServer.data,
    qt_meta_data_RBTCPServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RBTCPServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RBTCPServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RBTCPServer.stringdata0))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int RBTCPServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void RBTCPServer::SigNewConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RBTCPServer::SigDisConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

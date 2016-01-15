/****************************************************************************
** Meta object code from reading C++ file 'bluegiga_controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../hicling-bledebug/bluegiga_controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluegiga_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BlueGiga_controller_t {
    QByteArrayData data[10];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BlueGiga_controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BlueGiga_controller_t qt_meta_stringdata_BlueGiga_controller = {
    {
QT_MOC_LITERAL(0, 0, 19), // "BlueGiga_controller"
QT_MOC_LITERAL(1, 20, 17), // "serial_error_slot"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(4, 68, 5), // "error"
QT_MOC_LITERAL(5, 74, 16), // "slot_read_serial"
QT_MOC_LITERAL(6, 91, 28), // "push_button_ble_connect_slot"
QT_MOC_LITERAL(7, 120, 31), // "push_button_ble_disconnect_slot"
QT_MOC_LITERAL(8, 152, 28), // "push_button_ble_add_mac_slot"
QT_MOC_LITERAL(9, 181, 26) // "push_button_log_clear_slot"

    },
    "BlueGiga_controller\0serial_error_slot\0"
    "\0QSerialPort::SerialPortError\0error\0"
    "slot_read_serial\0push_button_ble_connect_slot\0"
    "push_button_ble_disconnect_slot\0"
    "push_button_ble_add_mac_slot\0"
    "push_button_log_clear_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BlueGiga_controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,
       8,    0,   50,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BlueGiga_controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BlueGiga_controller *_t = static_cast<BlueGiga_controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->serial_error_slot((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 1: _t->slot_read_serial(); break;
        case 2: _t->push_button_ble_connect_slot(); break;
        case 3: _t->push_button_ble_disconnect_slot(); break;
        case 4: _t->push_button_ble_add_mac_slot(); break;
        case 5: _t->push_button_log_clear_slot(); break;
        default: ;
        }
    }
}

const QMetaObject BlueGiga_controller::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BlueGiga_controller.data,
      qt_meta_data_BlueGiga_controller,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BlueGiga_controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BlueGiga_controller::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BlueGiga_controller.stringdata0))
        return static_cast<void*>(const_cast< BlueGiga_controller*>(this));
    return QDialog::qt_metacast(_clname);
}

int BlueGiga_controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'informationwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../informationwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'informationwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_InformationWidget_t {
    QByteArrayData data[9];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InformationWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InformationWidget_t qt_meta_stringdata_InformationWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "InformationWidget"
QT_MOC_LITERAL(1, 18, 11), // "refreshInfo"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 16), // "changeBackground"
QT_MOC_LITERAL(4, 48, 4), // "path"
QT_MOC_LITERAL(5, 53, 14), // "changFointSize"
QT_MOC_LITERAL(6, 68, 1), // "i"
QT_MOC_LITERAL(7, 70, 11), // "isFileExist"
QT_MOC_LITERAL(8, 82, 12) // "fullFilePath"

    },
    "InformationWidget\0refreshInfo\0\0"
    "changeBackground\0path\0changFointSize\0"
    "i\0isFileExist\0fullFilePath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InformationWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    1,   35,    2, 0x0a /* Public */,
       5,    1,   38,    2, 0x0a /* Public */,
       7,    1,   41,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Bool, QMetaType::QString,    8,

       0        // eod
};

void InformationWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InformationWidget *_t = static_cast<InformationWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refreshInfo(); break;
        case 1: _t->changeBackground((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->changFointSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { bool _r = _t->isFileExist((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject InformationWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_InformationWidget.data,
      qt_meta_data_InformationWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *InformationWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InformationWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_InformationWidget.stringdata0))
        return static_cast<void*>(const_cast< InformationWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int InformationWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

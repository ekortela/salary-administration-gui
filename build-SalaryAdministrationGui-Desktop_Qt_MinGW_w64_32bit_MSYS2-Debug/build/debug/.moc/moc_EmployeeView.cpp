/****************************************************************************
** Meta object code from reading C++ file 'EmployeeView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../SalaryAdministrationGui/src/view/EmployeeView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EmployeeView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EmployeeView_t {
    QByteArrayData data[7];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EmployeeView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EmployeeView_t qt_meta_stringdata_EmployeeView = {
    {
QT_MOC_LITERAL(0, 0, 12), // "EmployeeView"
QT_MOC_LITERAL(1, 13, 21), // "handleSaveButtonClick"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 23), // "handleDeleteButtonClick"
QT_MOC_LITERAL(4, 60, 27), // "handleTreeWidgetDoubleClick"
QT_MOC_LITERAL(5, 88, 19), // "handlePayTypeChange"
QT_MOC_LITERAL(6, 108, 31) // "handleAddNewEmployeeButtonClick"

    },
    "EmployeeView\0handleSaveButtonClick\0\0"
    "handleDeleteButtonClick\0"
    "handleTreeWidgetDoubleClick\0"
    "handlePayTypeChange\0handleAddNewEmployeeButtonClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EmployeeView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
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

void EmployeeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EmployeeView *_t = static_cast<EmployeeView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleSaveButtonClick(); break;
        case 1: _t->handleDeleteButtonClick(); break;
        case 2: _t->handleTreeWidgetDoubleClick(); break;
        case 3: _t->handlePayTypeChange(); break;
        case 4: _t->handleAddNewEmployeeButtonClick(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject EmployeeView::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_EmployeeView.data,
      qt_meta_data_EmployeeView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EmployeeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EmployeeView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EmployeeView.stringdata0))
        return static_cast<void*>(const_cast< EmployeeView*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int EmployeeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE

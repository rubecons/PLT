/****************************************************************************
** Meta object code from reading C++ file 'FenetrePremiereOuverture.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/FenetrePremiereOuverture.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FenetrePremiereOuverture.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FenetrePremiereOuverture_t {
    QByteArrayData data[8];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FenetrePremiereOuverture_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FenetrePremiereOuverture_t qt_meta_stringdata_FenetrePremiereOuverture = {
    {
QT_MOC_LITERAL(0, 0, 24), // "FenetrePremiereOuverture"
QT_MOC_LITERAL(1, 25, 10), // "annulation"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 11), // "enregistrer"
QT_MOC_LITERAL(4, 49, 10), // "DbManager*"
QT_MOC_LITERAL(5, 60, 3), // "dbC"
QT_MOC_LITERAL(6, 64, 4), // "budg"
QT_MOC_LITERAL(7, 69, 4) // "empr"

    },
    "FenetrePremiereOuverture\0annulation\0"
    "\0enregistrer\0DbManager*\0dbC\0budg\0empr"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FenetrePremiereOuverture[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    3,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Double, QMetaType::Double,    5,    6,    7,

       0        // eod
};

void FenetrePremiereOuverture::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FenetrePremiereOuverture *_t = static_cast<FenetrePremiereOuverture *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->annulation(); break;
        case 1: _t->enregistrer((*reinterpret_cast< DbManager*(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject FenetrePremiereOuverture::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FenetrePremiereOuverture.data,
      qt_meta_data_FenetrePremiereOuverture,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FenetrePremiereOuverture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FenetrePremiereOuverture::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FenetrePremiereOuverture.stringdata0))
        return static_cast<void*>(const_cast< FenetrePremiereOuverture*>(this));
    return QWidget::qt_metacast(_clname);
}

int FenetrePremiereOuverture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/********************************************************************************
** Form generated from reading UI file 'dy.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DY_H
#define UI_DY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DYClass
{
public:

    void setupUi(QWidget *DYClass)
    {
        if (DYClass->objectName().isEmpty())
            DYClass->setObjectName(QStringLiteral("DYClass"));
        DYClass->resize(600, 400);

        retranslateUi(DYClass);

        QMetaObject::connectSlotsByName(DYClass);
    } // setupUi

    void retranslateUi(QWidget *DYClass)
    {
        DYClass->setWindowTitle(QApplication::translate("DYClass", "DY", 0));
    } // retranslateUi

};

namespace Ui {
    class DYClass: public Ui_DYClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DY_H

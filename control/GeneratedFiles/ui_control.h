/********************************************************************************
** Form generated from reading UI file 'control.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROL_H
#define UI_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_controlClass
{
public:

    void setupUi(QWidget *controlClass)
    {
        if (controlClass->objectName().isEmpty())
            controlClass->setObjectName(QStringLiteral("controlClass"));
        controlClass->resize(600, 400);

        retranslateUi(controlClass);

        QMetaObject::connectSlotsByName(controlClass);
    } // setupUi

    void retranslateUi(QWidget *controlClass)
    {
        controlClass->setWindowTitle(QApplication::translate("controlClass", "control", 0));
    } // retranslateUi

};

namespace Ui {
    class controlClass: public Ui_controlClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROL_H

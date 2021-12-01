/********************************************************************************
** Form generated from reading UI file 'mainwindowcompanyemployee.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWCOMPANYEMPLOYEE_H
#define UI_MAINWINDOWCOMPANYEMPLOYEE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowCompanyEmployee
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowCompanyEmployee)
    {
        if (MainWindowCompanyEmployee->objectName().isEmpty())
            MainWindowCompanyEmployee->setObjectName(QString::fromUtf8("MainWindowCompanyEmployee"));
        MainWindowCompanyEmployee->resize(800, 600);
        centralwidget = new QWidget(MainWindowCompanyEmployee);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindowCompanyEmployee->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowCompanyEmployee);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindowCompanyEmployee->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowCompanyEmployee);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowCompanyEmployee->setStatusBar(statusbar);

        retranslateUi(MainWindowCompanyEmployee);

        QMetaObject::connectSlotsByName(MainWindowCompanyEmployee);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowCompanyEmployee)
    {
        MainWindowCompanyEmployee->setWindowTitle(QApplication::translate("MainWindowCompanyEmployee", "MainWindowCompanyEmployee", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowCompanyEmployee: public Ui_MainWindowCompanyEmployee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWCOMPANYEMPLOYEE_H

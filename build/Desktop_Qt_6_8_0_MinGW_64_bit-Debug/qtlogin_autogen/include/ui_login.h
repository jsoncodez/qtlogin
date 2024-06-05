/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLineEdit *line_user;
    QLineEdit *line_pw;
    QPushButton *btn_login;
    QMenuBar *menubar;
    QMenu *menuLOGIN_WINDOW;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(800, 600);
        centralwidget = new QWidget(login);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(200, 40, 361, 361));
        line_user = new QLineEdit(groupBox);
        line_user->setObjectName("line_user");
        line_user->setGeometry(QRect(120, 110, 113, 21));
        line_pw = new QLineEdit(groupBox);
        line_pw->setObjectName("line_pw");
        line_pw->setGeometry(QRect(120, 170, 113, 21));
        btn_login = new QPushButton(groupBox);
        btn_login->setObjectName("btn_login");
        btn_login->setGeometry(QRect(120, 220, 100, 32));
        login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(login);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 43));
        menuLOGIN_WINDOW = new QMenu(menubar);
        menuLOGIN_WINDOW->setObjectName("menuLOGIN_WINDOW");
        login->setMenuBar(menubar);
        statusbar = new QStatusBar(login);
        statusbar->setObjectName("statusbar");
        login->setStatusBar(statusbar);

        menubar->addAction(menuLOGIN_WINDOW->menuAction());

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "login", nullptr));
        groupBox->setTitle(QCoreApplication::translate("login", "GroupBox", nullptr));
        btn_login->setText(QCoreApplication::translate("login", "LOGIN", nullptr));
        menuLOGIN_WINDOW->setTitle(QCoreApplication::translate("login", "LOGIN WINDOW", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

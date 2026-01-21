/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLineEdit *Pin;
    QLabel *TextP;
    QPushButton *BtnLogin;
    QLineEdit *cardNumber;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(763, 313);
        Pin = new QLineEdit(Login);
        Pin->setObjectName("Pin");
        Pin->setGeometry(QRect(490, 80, 161, 51));
        Pin->setMaxLength(4);
        Pin->setFrame(true);
        Pin->setEchoMode(QLineEdit::EchoMode::Password);
        Pin->setReadOnly(false);
        TextP = new QLabel(Login);
        TextP->setObjectName("TextP");
        TextP->setGeometry(QRect(30, 10, 451, 131));
        QFont font;
        font.setPointSize(14);
        TextP->setFont(font);
        BtnLogin = new QPushButton(Login);
        BtnLogin->setObjectName("BtnLogin");
        BtnLogin->setGeometry(QRect(20, 150, 241, 61));
        QFont font1;
        font1.setPointSize(18);
        BtnLogin->setFont(font1);
        cardNumber = new QLineEdit(Login);
        cardNumber->setObjectName("cardNumber");
        cardNumber->setGeometry(QRect(490, 160, 161, 51));
        cardNumber->setFrame(true);
        cardNumber->setEchoMode(QLineEdit::EchoMode::Password);
        cardNumber->setReadOnly(false);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        Pin->setInputMask(QString());
        Pin->setText(QString());
        Pin->setPlaceholderText(QCoreApplication::translate("Login", "PIN", nullptr));
        TextP->setText(QCoreApplication::translate("Login", "Tervetuloa", nullptr));
        BtnLogin->setText(QCoreApplication::translate("Login", "Kirjaudu", nullptr));
        cardNumber->setText(QString());
        cardNumber->setPlaceholderText(QCoreApplication::translate("Login", "Kortin numero", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

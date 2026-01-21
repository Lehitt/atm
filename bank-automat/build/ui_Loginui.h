/********************************************************************************
** Form generated from reading UI file 'Loginui.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINUI_H
#define UI_LOGINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLineEdit *Pin;
    QLabel *TextP;
    QPushButton *BtnLogin;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(879, 644);
        Pin = new QLineEdit(Form);
        Pin->setObjectName("Pin");
        Pin->setGeometry(QRect(350, 220, 161, 51));
        Pin->setFrame(true);
        Pin->setEchoMode(QLineEdit::EchoMode::Password);
        Pin->setReadOnly(false);
        TextP = new QLabel(Form);
        TextP->setObjectName("TextP");
        TextP->setGeometry(QRect(360, 140, 121, 51));
        QFont font;
        font.setPointSize(20);
        TextP->setFont(font);
        BtnLogin = new QPushButton(Form);
        BtnLogin->setObjectName("BtnLogin");
        BtnLogin->setGeometry(QRect(310, 300, 241, 61));
        QFont font1;
        font1.setPointSize(18);
        BtnLogin->setFont(font1);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        Pin->setText(QString());
        Pin->setPlaceholderText(QCoreApplication::translate("Form", "PIN", nullptr));
        TextP->setText(QCoreApplication::translate("Form", "Tervetuloa", nullptr));
        BtnLogin->setText(QCoreApplication::translate("Form", "Sis\303\244\303\244nkirjautuminen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINUI_H

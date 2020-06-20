/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *logIn_login;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *logIn_password;
    QPushButton *logIn_pushButton;
    QWidget *tab_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *reg_login;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *reg_password1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *reg_password2;
    QPushButton *reg_pushButton;

    void setupUi(QDialog *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(357, 267);
        tabWidget = new QTabWidget(Form);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 311, 231));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 261, 141));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        logIn_login = new QLineEdit(layoutWidget);
        logIn_login->setObjectName(QString::fromUtf8("logIn_login"));

        horizontalLayout_2->addWidget(logIn_login);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        logIn_password = new QLineEdit(layoutWidget);
        logIn_password->setObjectName(QString::fromUtf8("logIn_password"));
        logIn_password->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(logIn_password);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        logIn_pushButton = new QPushButton(layoutWidget);
        logIn_pushButton->setObjectName(QString::fromUtf8("logIn_pushButton"));

        verticalLayout_2->addWidget(logIn_pushButton);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        layoutWidget1 = new QWidget(tab_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 20, 261, 161));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        reg_login = new QLineEdit(layoutWidget1);
        reg_login->setObjectName(QString::fromUtf8("reg_login"));

        horizontalLayout_5->addWidget(reg_login);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        reg_password1 = new QLineEdit(layoutWidget1);
        reg_password1->setObjectName(QString::fromUtf8("reg_password1"));
        reg_password1->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(reg_password1);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        reg_password2 = new QLineEdit(layoutWidget1);
        reg_password2->setObjectName(QString::fromUtf8("reg_password2"));
        reg_password2->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(reg_password2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        reg_pushButton = new QPushButton(layoutWidget1);
        reg_pushButton->setObjectName(QString::fromUtf8("reg_pushButton"));

        verticalLayout_3->addWidget(reg_pushButton);

        tabWidget->addTab(tab_2, QString());

        retranslateUi(Form);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QDialog *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Form", "Login", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "Password", nullptr));
        logIn_pushButton->setText(QCoreApplication::translate("Form", "Log in", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Form", "Log in", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "Login", nullptr));
        label_4->setText(QCoreApplication::translate("Form", "Password", nullptr));
        label_5->setText(QCoreApplication::translate("Form", "Password", nullptr));
        reg_pushButton->setText(QCoreApplication::translate("Form", "Sign up", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Form", "Sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H

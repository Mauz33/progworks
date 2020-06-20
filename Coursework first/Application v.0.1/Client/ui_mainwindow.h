/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QWidget *layoutWidget_7;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_13;
    QLineEdit *linePort;
    QWidget *layoutWidget_8;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_14;
    QLineEdit *lineIP;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonConnect;
    QPushButton *getAccessButton;
    QPushButton *pushButtonSend;
    QWidget *layoutWidget_9;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_15;
    QLineEdit *lineCommand;
    QWidget *layoutWidget_10;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_16;
    QTextBrowser *textBrowser_4;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(621, 410);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(420, 0, 191, 161));
        layoutWidget_7 = new QWidget(groupBox);
        layoutWidget_7->setObjectName(QString::fromUtf8("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(10, 70, 110, 50));
        verticalLayout_13 = new QVBoxLayout(layoutWidget_7);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget_7);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_13->addWidget(label_13);

        linePort = new QLineEdit(layoutWidget_7);
        linePort->setObjectName(QString::fromUtf8("linePort"));

        verticalLayout_13->addWidget(linePort);

        layoutWidget_8 = new QWidget(groupBox);
        layoutWidget_8->setObjectName(QString::fromUtf8("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(10, 20, 171, 50));
        verticalLayout_14 = new QVBoxLayout(layoutWidget_8);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(layoutWidget_8);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_14->addWidget(label_14);

        lineIP = new QLineEdit(layoutWidget_8);
        lineIP->setObjectName(QString::fromUtf8("lineIP"));

        verticalLayout_14->addWidget(lineIP);

        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 120, 171, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonConnect = new QPushButton(layoutWidget);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonConnect->sizePolicy().hasHeightForWidth());
        pushButtonConnect->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButtonConnect);

        getAccessButton = new QPushButton(layoutWidget);
        getAccessButton->setObjectName(QString::fromUtf8("getAccessButton"));
        sizePolicy.setHeightForWidth(getAccessButton->sizePolicy().hasHeightForWidth());
        getAccessButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(getAccessButton);

        pushButtonSend = new QPushButton(centralwidget);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));
        pushButtonSend->setGeometry(QRect(10, 70, 81, 31));
        layoutWidget_9 = new QWidget(centralwidget);
        layoutWidget_9->setObjectName(QString::fromUtf8("layoutWidget_9"));
        layoutWidget_9->setGeometry(QRect(10, 20, 401, 50));
        verticalLayout_15 = new QVBoxLayout(layoutWidget_9);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(layoutWidget_9);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_15->addWidget(label_15);

        lineCommand = new QLineEdit(layoutWidget_9);
        lineCommand->setObjectName(QString::fromUtf8("lineCommand"));

        verticalLayout_15->addWidget(lineCommand);

        layoutWidget_10 = new QWidget(centralwidget);
        layoutWidget_10->setObjectName(QString::fromUtf8("layoutWidget_10"));
        layoutWidget_10->setGeometry(QRect(10, 150, 601, 213));
        verticalLayout_16 = new QVBoxLayout(layoutWidget_10);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(layoutWidget_10);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout_16->addWidget(label_16);

        textBrowser_4 = new QTextBrowser(layoutWidget_10);
        textBrowser_4->setObjectName(QString::fromUtf8("textBrowser_4"));
        QFont font;
        font.setPointSize(10);
        textBrowser_4->setFont(font);

        verticalLayout_16->addWidget(textBrowser_4);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 621, 20));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \320\264\320\276\321\201\321\202\321\203\320\277", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        action_4->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        linePort->setText(QCoreApplication::translate("MainWindow", "4242", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "IP", nullptr));
        lineIP->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        getAccessButton->setText(QCoreApplication::translate("MainWindow", "Get access", nullptr));
        pushButtonSend->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Command", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Log", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

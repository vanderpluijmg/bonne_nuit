/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TEST_H
#define TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_start_question;
    QWidget *widget_player;
    QHBoxLayout *horizontalLayout;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QLabel *label_age;
    QLineEdit *lineEdit_age;
    QLineEdit *lineEdit_numberOfPlayer;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_start_question = new QLabel(centralwidget);
        label_start_question->setObjectName(QString::fromUtf8("label_start_question"));
        label_start_question->setGeometry(QRect(200, 0, 271, 71));
        widget_player = new QWidget(centralwidget);
        widget_player->setObjectName(QString::fromUtf8("widget_player"));
        widget_player->setGeometry(QRect(30, 100, 430, 50));
        horizontalLayout = new QHBoxLayout(widget_player);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_name = new QLabel(widget_player);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        horizontalLayout->addWidget(label_name);

        lineEdit_name = new QLineEdit(widget_player);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        horizontalLayout->addWidget(lineEdit_name);

        label_age = new QLabel(widget_player);
        label_age->setObjectName(QString::fromUtf8("label_age"));

        horizontalLayout->addWidget(label_age);

        lineEdit_age = new QLineEdit(widget_player);
        lineEdit_age->setObjectName(QString::fromUtf8("lineEdit_age"));

        horizontalLayout->addWidget(lineEdit_age);

        lineEdit_numberOfPlayer = new QLineEdit(centralwidget);
        lineEdit_numberOfPlayer->setObjectName(QString::fromUtf8("lineEdit_numberOfPlayer"));
        lineEdit_numberOfPlayer->setGeometry(QRect(470, 20, 113, 32));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(610, 20, 90, 34));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 30));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_start_question->setText(QCoreApplication::translate("MainWindow", " How many players are going to play ?", nullptr));
        label_name->setText(QCoreApplication::translate("MainWindow", "What is your name? ", nullptr));
        label_age->setText(QCoreApplication::translate("MainWindow", "Age ?", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TEST_H

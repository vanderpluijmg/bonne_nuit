/********************************************************************************
** Form generated from reading UI file 'application.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef APPLICATION_H
#define APPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Application
{
public:
    QStackedWidget *stackedWidget;
    QWidget *welcomePage;
    QPushButton *players;
    QLabel *label;

    void setupUi(QWidget *Application)
    {
        if (Application->objectName().isEmpty())
            Application->setObjectName(QString::fromUtf8("Application"));
        Application->resize(1175, 694);
        stackedWidget = new QStackedWidget(Application);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, -40, 1171, 731));
        welcomePage = new QWidget();
        welcomePage->setObjectName(QString::fromUtf8("welcomePage"));
        players = new QPushButton(welcomePage);
        players->setObjectName(QString::fromUtf8("players"));
        players->setGeometry(QRect(470, 560, 261, 34));
        label = new QLabel(welcomePage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(560, 450, 221, 111));
        stackedWidget->addWidget(welcomePage);

        retranslateUi(Application);

        QMetaObject::connectSlotsByName(Application);
    } // setupUi

    void retranslateUi(QWidget *Application)
    {
        Application->setWindowTitle(QCoreApplication::translate("Application", "Form", nullptr));
        players->setText(QCoreApplication::translate("Application", "Please press button to continue to game", nullptr));
        label->setText(QCoreApplication::translate("Application", "GoodNight", nullptr));
    } // retranslateUi

};

QT_END_NAMESPACE

#endif // APPLICATION_H

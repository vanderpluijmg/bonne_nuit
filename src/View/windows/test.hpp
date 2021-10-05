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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QStackedWidget *stackedWidget;
    QWidget *gameIntro;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *numberOfPlayerLayout;
    QLabel *label;
    QLCDNumber *numberOfPlayers;
    QPushButton *addPlayer;
    QPushButton *removePlayer;
    QFrame *centralFrame;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QWidget *verticalLayoutWidget;
    QHBoxLayout *startGameLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *startGame;
    QSpacerItem *horizontalSpacer;
    QWidget *page_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(1376, 883);
        stackedWidget = new QStackedWidget(Form);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(140, 30, 1221, 821));
        gameIntro = new QWidget();
        gameIntro->setObjectName(QString::fromUtf8("gameIntro"));
        horizontalLayoutWidget = new QWidget(gameIntro);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 1211, 101));
        numberOfPlayerLayout = new QHBoxLayout(horizontalLayoutWidget);
        numberOfPlayerLayout->setObjectName(QString::fromUtf8("numberOfPlayerLayout"));
        numberOfPlayerLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        numberOfPlayerLayout->addWidget(label);

        numberOfPlayers = new QLCDNumber(horizontalLayoutWidget);
        numberOfPlayers->setObjectName(QString::fromUtf8("numberOfPlayers"));

        numberOfPlayerLayout->addWidget(numberOfPlayers);

        addPlayer = new QPushButton(horizontalLayoutWidget);
        addPlayer->setObjectName(QString::fromUtf8("addPlayer"));

        numberOfPlayerLayout->addWidget(addPlayer);

        removePlayer = new QPushButton(horizontalLayoutWidget);
        removePlayer->setObjectName(QString::fromUtf8("removePlayer"));

        numberOfPlayerLayout->addWidget(removePlayer);

        centralFrame = new QFrame(gameIntro);
        centralFrame->setObjectName(QString::fromUtf8("centralFrame"));
        centralFrame->setGeometry(QRect(20, 130, 1191, 471));
        centralFrame->setFrameShape(QFrame::StyledPanel);
        centralFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(centralFrame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 448, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayoutWidget = new QWidget(gameIntro);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 620, 1181, 151));
        startGameLayout = new QHBoxLayout(verticalLayoutWidget);
        startGameLayout->setObjectName(QString::fromUtf8("startGameLayout"));
        startGameLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        startGameLayout->addItem(horizontalSpacer_2);

        startGame = new QPushButton(verticalLayoutWidget);
        startGame->setObjectName(QString::fromUtf8("startGame"));

        startGameLayout->addWidget(startGame);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        startGameLayout->addItem(horizontalSpacer);

        stackedWidget->addWidget(gameIntro);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        retranslateUi(Form);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form", "How many players are going to play?", nullptr));
        addPlayer->setText(QCoreApplication::translate("Form", "add player", nullptr));
        removePlayer->setText(QCoreApplication::translate("Form", "remove player", nullptr));
        startGame->setText(QCoreApplication::translate("Form", "Start Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TEST_H

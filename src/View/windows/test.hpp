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
    QWidget *cases;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *case8;
    QPushButton *pushButton_7;
    QWidget *verticalLayoutWidget_9;
    QVBoxLayout *case3;
    QPushButton *pushButton_4;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *case0;
    QPushButton *pushButton;
    QWidget *verticalLayoutWidget_11;
    QVBoxLayout *case4;
    QPushButton *pushButton_5;
    QWidget *verticalLayoutWidget_8;
    QVBoxLayout *case2;
    QPushButton *pushButton_3;
    QWidget *verticalLayoutWidget_12;
    QVBoxLayout *case5;
    QPushButton *pushButton_10;
    QWidget *verticalLayoutWidget_10;
    QVBoxLayout *case7;
    QPushButton *pushButton_9;
    QWidget *verticalLayoutWidget_13;
    QVBoxLayout *case6;
    QPushButton *pushButton_6;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *case1;
    QPushButton *pushButton_2;
    QWidget *verticalLayoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *rollDice;
    QLCDNumber *rollDiceValue;
    QLabel *currentPlayer;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(1373, 911);
        stackedWidget = new QStackedWidget(Form);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(-10, 10, 1371, 911));
        gameIntro = new QWidget();
        gameIntro->setObjectName(QString::fromUtf8("gameIntro"));
        horizontalLayoutWidget = new QWidget(gameIntro);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 1341, 101));
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
        centralFrame->setGeometry(QRect(20, 130, 1321, 471));
        centralFrame->setFrameShape(QFrame::StyledPanel);
        centralFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(centralFrame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 448, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayoutWidget = new QWidget(gameIntro);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 620, 1331, 151));
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
        cases = new QWidget(page_2);
        cases->setObjectName(QString::fromUtf8("cases"));
        cases->setGeometry(QRect(10, 40, 1351, 801));
        verticalLayoutWidget_6 = new QWidget(cases);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(870, 290, 431, 111));
        case8 = new QVBoxLayout(verticalLayoutWidget_6);
        case8->setObjectName(QString::fromUtf8("case8"));
        case8->setContentsMargins(0, 0, 0, 0);
        pushButton_7 = new QPushButton(verticalLayoutWidget_6);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        case8->addWidget(pushButton_7);

        verticalLayoutWidget_9 = new QWidget(cases);
        verticalLayoutWidget_9->setObjectName(QString::fromUtf8("verticalLayoutWidget_9"));
        verticalLayoutWidget_9->setGeometry(QRect(40, 550, 431, 111));
        case3 = new QVBoxLayout(verticalLayoutWidget_9);
        case3->setObjectName(QString::fromUtf8("case3"));
        case3->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(verticalLayoutWidget_9);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        case3->addWidget(pushButton_4);

        verticalLayoutWidget_3 = new QWidget(cases);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(460, 160, 431, 110));
        case0 = new QVBoxLayout(verticalLayoutWidget_3);
        case0->setObjectName(QString::fromUtf8("case0"));
        case0->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        case0->addWidget(pushButton);

        verticalLayoutWidget_11 = new QWidget(cases);
        verticalLayoutWidget_11->setObjectName(QString::fromUtf8("verticalLayoutWidget_11"));
        verticalLayoutWidget_11->setGeometry(QRect(250, 680, 431, 111));
        case4 = new QVBoxLayout(verticalLayoutWidget_11);
        case4->setObjectName(QString::fromUtf8("case4"));
        case4->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(verticalLayoutWidget_11);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        case4->addWidget(pushButton_5);

        verticalLayoutWidget_8 = new QWidget(cases);
        verticalLayoutWidget_8->setObjectName(QString::fromUtf8("verticalLayoutWidget_8"));
        verticalLayoutWidget_8->setGeometry(QRect(0, 420, 431, 111));
        case2 = new QVBoxLayout(verticalLayoutWidget_8);
        case2->setObjectName(QString::fromUtf8("case2"));
        case2->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(verticalLayoutWidget_8);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        case2->addWidget(pushButton_3);

        verticalLayoutWidget_12 = new QWidget(cases);
        verticalLayoutWidget_12->setObjectName(QString::fromUtf8("verticalLayoutWidget_12"));
        verticalLayoutWidget_12->setGeometry(QRect(690, 680, 431, 111));
        case5 = new QVBoxLayout(verticalLayoutWidget_12);
        case5->setObjectName(QString::fromUtf8("case5"));
        case5->setContentsMargins(0, 0, 0, 0);
        pushButton_10 = new QPushButton(verticalLayoutWidget_12);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        case5->addWidget(pushButton_10);

        verticalLayoutWidget_10 = new QWidget(cases);
        verticalLayoutWidget_10->setObjectName(QString::fromUtf8("verticalLayoutWidget_10"));
        verticalLayoutWidget_10->setGeometry(QRect(910, 420, 431, 110));
        case7 = new QVBoxLayout(verticalLayoutWidget_10);
        case7->setObjectName(QString::fromUtf8("case7"));
        case7->setContentsMargins(0, 0, 0, 0);
        pushButton_9 = new QPushButton(verticalLayoutWidget_10);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        case7->addWidget(pushButton_9);

        verticalLayoutWidget_13 = new QWidget(cases);
        verticalLayoutWidget_13->setObjectName(QString::fromUtf8("verticalLayoutWidget_13"));
        verticalLayoutWidget_13->setGeometry(QRect(870, 550, 431, 111));
        case6 = new QVBoxLayout(verticalLayoutWidget_13);
        case6->setObjectName(QString::fromUtf8("case6"));
        case6->setContentsMargins(0, 0, 0, 0);
        pushButton_6 = new QPushButton(verticalLayoutWidget_13);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        case6->addWidget(pushButton_6);

        verticalLayoutWidget_5 = new QWidget(cases);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(50, 290, 431, 111));
        case1 = new QVBoxLayout(verticalLayoutWidget_5);
        case1->setObjectName(QString::fromUtf8("case1"));
        case1->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(verticalLayoutWidget_5);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        case1->addWidget(pushButton_2);

        verticalLayoutWidget_2 = new QWidget(page_2);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 0, 431, 81));
        horizontalLayout = new QHBoxLayout(verticalLayoutWidget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        rollDice = new QPushButton(verticalLayoutWidget_2);
        rollDice->setObjectName(QString::fromUtf8("rollDice"));

        horizontalLayout->addWidget(rollDice);

        rollDiceValue = new QLCDNumber(verticalLayoutWidget_2);
        rollDiceValue->setObjectName(QString::fromUtf8("rollDiceValue"));

        horizontalLayout->addWidget(rollDiceValue);

        currentPlayer = new QLabel(verticalLayoutWidget_2);
        currentPlayer->setObjectName(QString::fromUtf8("currentPlayer"));

        horizontalLayout->addWidget(currentPlayer);

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
        pushButton_7->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
        pushButton_10->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
        rollDice->setText(QCoreApplication::translate("Form", "Roll Dice", nullptr));
        currentPlayer->setText(QCoreApplication::translate("Form", "current Player", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TEST_H

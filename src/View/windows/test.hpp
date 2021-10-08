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
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *caseStar0;
    QPushButton *star00;
    QPushButton *star01;
    QPushButton *star02;
    QPushButton *star03;
    QPushButton *star04;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *caseStar8;
    QPushButton *star80;
    QPushButton *star81;
    QPushButton *star82;
    QPushButton *star83;
    QPushButton *star84;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *caseStar7;
    QPushButton *star70;
    QPushButton *star71;
    QPushButton *star72;
    QPushButton *star73;
    QPushButton *star74;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *caseStar6;
    QPushButton *star60;
    QPushButton *star61;
    QPushButton *star62;
    QPushButton *star63;
    QPushButton *star64;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *caseStar5;
    QPushButton *star50;
    QPushButton *star51;
    QPushButton *star52;
    QPushButton *star53;
    QPushButton *star54;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *caseStar2;
    QPushButton *star20;
    QPushButton *star21;
    QPushButton *star22;
    QPushButton *star23;
    QPushButton *star24;
    QWidget *horizontalLayoutWidget_8;
    QHBoxLayout *caseStar4;
    QPushButton *star40;
    QPushButton *star41;
    QPushButton *star42;
    QPushButton *star43;
    QPushButton *star44;
    QWidget *horizontalLayoutWidget_9;
    QHBoxLayout *caseStar3;
    QPushButton *star30;
    QPushButton *star31;
    QPushButton *star32;
    QPushButton *star33;
    QPushButton *star34;
    QWidget *horizontalLayoutWidget_10;
    QHBoxLayout *caseStar1;
    QPushButton *star10;
    QPushButton *star11;
    QPushButton *star12;
    QPushButton *star13;
    QPushButton *star14;
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
        verticalLayoutWidget_6->setGeometry(QRect(870, 360, 431, 41));
        case8 = new QVBoxLayout(verticalLayoutWidget_6);
        case8->setObjectName(QString::fromUtf8("case8"));
        case8->setContentsMargins(0, 0, 0, 0);
        pushButton_7 = new QPushButton(verticalLayoutWidget_6);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        case8->addWidget(pushButton_7);

        verticalLayoutWidget_9 = new QWidget(cases);
        verticalLayoutWidget_9->setObjectName(QString::fromUtf8("verticalLayoutWidget_9"));
        verticalLayoutWidget_9->setGeometry(QRect(40, 620, 431, 41));
        case3 = new QVBoxLayout(verticalLayoutWidget_9);
        case3->setObjectName(QString::fromUtf8("case3"));
        case3->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(verticalLayoutWidget_9);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        case3->addWidget(pushButton_4);

        verticalLayoutWidget_3 = new QWidget(cases);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(460, 229, 431, 41));
        case0 = new QVBoxLayout(verticalLayoutWidget_3);
        case0->setObjectName(QString::fromUtf8("case0"));
        case0->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        case0->addWidget(pushButton);

        verticalLayoutWidget_11 = new QWidget(cases);
        verticalLayoutWidget_11->setObjectName(QString::fromUtf8("verticalLayoutWidget_11"));
        verticalLayoutWidget_11->setGeometry(QRect(250, 750, 431, 41));
        case4 = new QVBoxLayout(verticalLayoutWidget_11);
        case4->setObjectName(QString::fromUtf8("case4"));
        case4->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(verticalLayoutWidget_11);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        case4->addWidget(pushButton_5);

        verticalLayoutWidget_8 = new QWidget(cases);
        verticalLayoutWidget_8->setObjectName(QString::fromUtf8("verticalLayoutWidget_8"));
        verticalLayoutWidget_8->setGeometry(QRect(0, 490, 431, 41));
        case2 = new QVBoxLayout(verticalLayoutWidget_8);
        case2->setObjectName(QString::fromUtf8("case2"));
        case2->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(verticalLayoutWidget_8);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        case2->addWidget(pushButton_3);

        verticalLayoutWidget_12 = new QWidget(cases);
        verticalLayoutWidget_12->setObjectName(QString::fromUtf8("verticalLayoutWidget_12"));
        verticalLayoutWidget_12->setGeometry(QRect(690, 750, 431, 41));
        case5 = new QVBoxLayout(verticalLayoutWidget_12);
        case5->setObjectName(QString::fromUtf8("case5"));
        case5->setContentsMargins(0, 0, 0, 0);
        pushButton_10 = new QPushButton(verticalLayoutWidget_12);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        case5->addWidget(pushButton_10);

        verticalLayoutWidget_10 = new QWidget(cases);
        verticalLayoutWidget_10->setObjectName(QString::fromUtf8("verticalLayoutWidget_10"));
        verticalLayoutWidget_10->setGeometry(QRect(910, 489, 431, 41));
        case7 = new QVBoxLayout(verticalLayoutWidget_10);
        case7->setObjectName(QString::fromUtf8("case7"));
        case7->setContentsMargins(0, 0, 0, 0);
        pushButton_9 = new QPushButton(verticalLayoutWidget_10);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        case7->addWidget(pushButton_9);

        verticalLayoutWidget_13 = new QWidget(cases);
        verticalLayoutWidget_13->setObjectName(QString::fromUtf8("verticalLayoutWidget_13"));
        verticalLayoutWidget_13->setGeometry(QRect(870, 620, 431, 41));
        case6 = new QVBoxLayout(verticalLayoutWidget_13);
        case6->setObjectName(QString::fromUtf8("case6"));
        case6->setContentsMargins(0, 0, 0, 0);
        pushButton_6 = new QPushButton(verticalLayoutWidget_13);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        case6->addWidget(pushButton_6);

        verticalLayoutWidget_5 = new QWidget(cases);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(50, 360, 431, 41));
        case1 = new QVBoxLayout(verticalLayoutWidget_5);
        case1->setObjectName(QString::fromUtf8("case1"));
        case1->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(verticalLayoutWidget_5);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        case1->addWidget(pushButton_2);

        horizontalLayoutWidget_2 = new QWidget(cases);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(460, 180, 431, 51));
        caseStar0 = new QHBoxLayout(horizontalLayoutWidget_2);
        caseStar0->setObjectName(QString::fromUtf8("caseStar0"));
        caseStar0->setContentsMargins(0, 0, 0, 0);
        star00 = new QPushButton(horizontalLayoutWidget_2);
        star00->setObjectName(QString::fromUtf8("star00"));

        caseStar0->addWidget(star00);

        star01 = new QPushButton(horizontalLayoutWidget_2);
        star01->setObjectName(QString::fromUtf8("star01"));

        caseStar0->addWidget(star01);

        star02 = new QPushButton(horizontalLayoutWidget_2);
        star02->setObjectName(QString::fromUtf8("star02"));

        caseStar0->addWidget(star02);

        star03 = new QPushButton(horizontalLayoutWidget_2);
        star03->setObjectName(QString::fromUtf8("star03"));

        caseStar0->addWidget(star03);

        star04 = new QPushButton(horizontalLayoutWidget_2);
        star04->setObjectName(QString::fromUtf8("star04"));

        caseStar0->addWidget(star04);

        verticalLayoutWidget_4 = new QWidget(cases);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(610, 0, 131, 81));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        horizontalLayoutWidget_3 = new QWidget(cases);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(870, 310, 431, 51));
        caseStar8 = new QHBoxLayout(horizontalLayoutWidget_3);
        caseStar8->setObjectName(QString::fromUtf8("caseStar8"));
        caseStar8->setContentsMargins(0, 0, 0, 0);
        star80 = new QPushButton(horizontalLayoutWidget_3);
        star80->setObjectName(QString::fromUtf8("star80"));

        caseStar8->addWidget(star80);

        star81 = new QPushButton(horizontalLayoutWidget_3);
        star81->setObjectName(QString::fromUtf8("star81"));

        caseStar8->addWidget(star81);

        star82 = new QPushButton(horizontalLayoutWidget_3);
        star82->setObjectName(QString::fromUtf8("star82"));

        caseStar8->addWidget(star82);

        star83 = new QPushButton(horizontalLayoutWidget_3);
        star83->setObjectName(QString::fromUtf8("star83"));

        caseStar8->addWidget(star83);

        star84 = new QPushButton(horizontalLayoutWidget_3);
        star84->setObjectName(QString::fromUtf8("star84"));

        caseStar8->addWidget(star84);

        horizontalLayoutWidget_4 = new QWidget(cases);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(910, 440, 431, 51));
        caseStar7 = new QHBoxLayout(horizontalLayoutWidget_4);
        caseStar7->setObjectName(QString::fromUtf8("caseStar7"));
        caseStar7->setContentsMargins(0, 0, 0, 0);
        star70 = new QPushButton(horizontalLayoutWidget_4);
        star70->setObjectName(QString::fromUtf8("star70"));

        caseStar7->addWidget(star70);

        star71 = new QPushButton(horizontalLayoutWidget_4);
        star71->setObjectName(QString::fromUtf8("star71"));

        caseStar7->addWidget(star71);

        star72 = new QPushButton(horizontalLayoutWidget_4);
        star72->setObjectName(QString::fromUtf8("star72"));

        caseStar7->addWidget(star72);

        star73 = new QPushButton(horizontalLayoutWidget_4);
        star73->setObjectName(QString::fromUtf8("star73"));

        caseStar7->addWidget(star73);

        star74 = new QPushButton(horizontalLayoutWidget_4);
        star74->setObjectName(QString::fromUtf8("star74"));

        caseStar7->addWidget(star74);

        horizontalLayoutWidget_5 = new QWidget(cases);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(870, 570, 431, 51));
        caseStar6 = new QHBoxLayout(horizontalLayoutWidget_5);
        caseStar6->setObjectName(QString::fromUtf8("caseStar6"));
        caseStar6->setContentsMargins(0, 0, 0, 0);
        star60 = new QPushButton(horizontalLayoutWidget_5);
        star60->setObjectName(QString::fromUtf8("star60"));

        caseStar6->addWidget(star60);

        star61 = new QPushButton(horizontalLayoutWidget_5);
        star61->setObjectName(QString::fromUtf8("star61"));

        caseStar6->addWidget(star61);

        star62 = new QPushButton(horizontalLayoutWidget_5);
        star62->setObjectName(QString::fromUtf8("star62"));

        caseStar6->addWidget(star62);

        star63 = new QPushButton(horizontalLayoutWidget_5);
        star63->setObjectName(QString::fromUtf8("star63"));

        caseStar6->addWidget(star63);

        star64 = new QPushButton(horizontalLayoutWidget_5);
        star64->setObjectName(QString::fromUtf8("star64"));

        caseStar6->addWidget(star64);

        horizontalLayoutWidget_6 = new QWidget(cases);
        horizontalLayoutWidget_6->setObjectName(QString::fromUtf8("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(690, 700, 431, 51));
        caseStar5 = new QHBoxLayout(horizontalLayoutWidget_6);
        caseStar5->setObjectName(QString::fromUtf8("caseStar5"));
        caseStar5->setContentsMargins(0, 0, 0, 0);
        star50 = new QPushButton(horizontalLayoutWidget_6);
        star50->setObjectName(QString::fromUtf8("star50"));

        caseStar5->addWidget(star50);

        star51 = new QPushButton(horizontalLayoutWidget_6);
        star51->setObjectName(QString::fromUtf8("star51"));

        caseStar5->addWidget(star51);

        star52 = new QPushButton(horizontalLayoutWidget_6);
        star52->setObjectName(QString::fromUtf8("star52"));

        caseStar5->addWidget(star52);

        star53 = new QPushButton(horizontalLayoutWidget_6);
        star53->setObjectName(QString::fromUtf8("star53"));

        caseStar5->addWidget(star53);

        star54 = new QPushButton(horizontalLayoutWidget_6);
        star54->setObjectName(QString::fromUtf8("star54"));

        caseStar5->addWidget(star54);

        horizontalLayoutWidget_7 = new QWidget(cases);
        horizontalLayoutWidget_7->setObjectName(QString::fromUtf8("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(0, 440, 431, 51));
        caseStar2 = new QHBoxLayout(horizontalLayoutWidget_7);
        caseStar2->setObjectName(QString::fromUtf8("caseStar2"));
        caseStar2->setContentsMargins(0, 0, 0, 0);
        star20 = new QPushButton(horizontalLayoutWidget_7);
        star20->setObjectName(QString::fromUtf8("star20"));

        caseStar2->addWidget(star20);

        star21 = new QPushButton(horizontalLayoutWidget_7);
        star21->setObjectName(QString::fromUtf8("star21"));

        caseStar2->addWidget(star21);

        star22 = new QPushButton(horizontalLayoutWidget_7);
        star22->setObjectName(QString::fromUtf8("star22"));

        caseStar2->addWidget(star22);

        star23 = new QPushButton(horizontalLayoutWidget_7);
        star23->setObjectName(QString::fromUtf8("star23"));

        caseStar2->addWidget(star23);

        star24 = new QPushButton(horizontalLayoutWidget_7);
        star24->setObjectName(QString::fromUtf8("star24"));

        caseStar2->addWidget(star24);

        horizontalLayoutWidget_8 = new QWidget(cases);
        horizontalLayoutWidget_8->setObjectName(QString::fromUtf8("horizontalLayoutWidget_8"));
        horizontalLayoutWidget_8->setGeometry(QRect(250, 700, 431, 51));
        caseStar4 = new QHBoxLayout(horizontalLayoutWidget_8);
        caseStar4->setObjectName(QString::fromUtf8("caseStar4"));
        caseStar4->setContentsMargins(0, 0, 0, 0);
        star40 = new QPushButton(horizontalLayoutWidget_8);
        star40->setObjectName(QString::fromUtf8("star40"));

        caseStar4->addWidget(star40);

        star41 = new QPushButton(horizontalLayoutWidget_8);
        star41->setObjectName(QString::fromUtf8("star41"));

        caseStar4->addWidget(star41);

        star42 = new QPushButton(horizontalLayoutWidget_8);
        star42->setObjectName(QString::fromUtf8("star42"));

        caseStar4->addWidget(star42);

        star43 = new QPushButton(horizontalLayoutWidget_8);
        star43->setObjectName(QString::fromUtf8("star43"));

        caseStar4->addWidget(star43);

        star44 = new QPushButton(horizontalLayoutWidget_8);
        star44->setObjectName(QString::fromUtf8("star44"));

        caseStar4->addWidget(star44);

        horizontalLayoutWidget_9 = new QWidget(cases);
        horizontalLayoutWidget_9->setObjectName(QString::fromUtf8("horizontalLayoutWidget_9"));
        horizontalLayoutWidget_9->setGeometry(QRect(40, 570, 431, 51));
        caseStar3 = new QHBoxLayout(horizontalLayoutWidget_9);
        caseStar3->setObjectName(QString::fromUtf8("caseStar3"));
        caseStar3->setContentsMargins(0, 0, 0, 0);
        star30 = new QPushButton(horizontalLayoutWidget_9);
        star30->setObjectName(QString::fromUtf8("star30"));

        caseStar3->addWidget(star30);

        star31 = new QPushButton(horizontalLayoutWidget_9);
        star31->setObjectName(QString::fromUtf8("star31"));

        caseStar3->addWidget(star31);

        star32 = new QPushButton(horizontalLayoutWidget_9);
        star32->setObjectName(QString::fromUtf8("star32"));

        caseStar3->addWidget(star32);

        star33 = new QPushButton(horizontalLayoutWidget_9);
        star33->setObjectName(QString::fromUtf8("star33"));

        caseStar3->addWidget(star33);

        star34 = new QPushButton(horizontalLayoutWidget_9);
        star34->setObjectName(QString::fromUtf8("star34"));

        caseStar3->addWidget(star34);

        horizontalLayoutWidget_10 = new QWidget(cases);
        horizontalLayoutWidget_10->setObjectName(QString::fromUtf8("horizontalLayoutWidget_10"));
        horizontalLayoutWidget_10->setGeometry(QRect(50, 310, 431, 51));
        caseStar1 = new QHBoxLayout(horizontalLayoutWidget_10);
        caseStar1->setObjectName(QString::fromUtf8("caseStar1"));
        caseStar1->setContentsMargins(0, 0, 0, 0);
        star10 = new QPushButton(horizontalLayoutWidget_10);
        star10->setObjectName(QString::fromUtf8("star10"));

        caseStar1->addWidget(star10);

        star11 = new QPushButton(horizontalLayoutWidget_10);
        star11->setObjectName(QString::fromUtf8("star11"));

        caseStar1->addWidget(star11);

        star12 = new QPushButton(horizontalLayoutWidget_10);
        star12->setObjectName(QString::fromUtf8("star12"));

        caseStar1->addWidget(star12);

        star13 = new QPushButton(horizontalLayoutWidget_10);
        star13->setObjectName(QString::fromUtf8("star13"));

        caseStar1->addWidget(star13);

        star14 = new QPushButton(horizontalLayoutWidget_10);
        star14->setObjectName(QString::fromUtf8("star14"));

        caseStar1->addWidget(star14);

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
        pushButton_7->setText(QString());
        pushButton_4->setText(QString());
        pushButton->setText(QString());
        pushButton_5->setText(QString());
        pushButton_3->setText(QString());
        pushButton_10->setText(QString());
        pushButton_9->setText(QString());
        pushButton_6->setText(QString());
        pushButton_2->setText(QString());
        star00->setText(QString());
        star01->setText(QString());
        star02->setText(QString());
        star03->setText(QString());
        star04->setText(QString());
        label_2->setText(QCoreApplication::translate("Form", "Chose place of star", nullptr));
        star80->setText(QString());
        star81->setText(QString());
        star82->setText(QString());
        star83->setText(QString());
        star84->setText(QString());
        star70->setText(QString());
        star71->setText(QString());
        star72->setText(QString());
        star73->setText(QString());
        star74->setText(QString());
        star60->setText(QString());
        star61->setText(QString());
        star62->setText(QString());
        star63->setText(QString());
        star64->setText(QString());
        star50->setText(QString());
        star51->setText(QString());
        star52->setText(QString());
        star53->setText(QString());
        star54->setText(QString());
        star20->setText(QString());
        star21->setText(QString());
        star22->setText(QString());
        star23->setText(QString());
        star24->setText(QString());
        star40->setText(QString());
        star41->setText(QString());
        star42->setText(QString());
        star43->setText(QString());
        star44->setText(QString());
        star30->setText(QString());
        star31->setText(QString());
        star32->setText(QString());
        star33->setText(QString());
        star34->setText(QString());
        star10->setText(QString());
        star11->setText(QString());
        star12->setText(QString());
        star13->setText(QString());
        star14->setText(QString());
        rollDice->setText(QCoreApplication::translate("Form", "Roll Dice", nullptr));
        currentPlayer->setText(QCoreApplication::translate("Form", "current Player", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TEST_H

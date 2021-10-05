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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
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
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QWidget *verticalLayoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *rollDice;
    QLCDNumber *rollDiceValue;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(1373, 911);
        stackedWidget = new QStackedWidget(Form);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 20, 1351, 891));
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
        gridLayoutWidget = new QWidget(page_2);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 1351, 751));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/img/no_drop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        gridLayout->addWidget(pushButton, 1, 2, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setIcon(icon);

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setIcon(icon);

        gridLayout->addWidget(pushButton_3, 2, 0, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/img/drop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon1);

        gridLayout->addWidget(pushButton_4, 0, 0, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setIcon(icon);

        gridLayout->addWidget(pushButton_6, 2, 2, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setIcon(icon);

        gridLayout->addWidget(pushButton_5, 0, 2, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setIcon(icon);

        gridLayout->addWidget(pushButton_7, 0, 1, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setIcon(icon);
        pushButton_8->setIconSize(QSize(68, 68));

        gridLayout->addWidget(pushButton_8, 1, 1, 1, 1);

        pushButton_9 = new QPushButton(gridLayoutWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setIcon(icon);

        gridLayout->addWidget(pushButton_9, 2, 1, 1, 1);

        verticalLayoutWidget_2 = new QWidget(page_2);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 770, 431, 81));
        horizontalLayout = new QHBoxLayout(verticalLayoutWidget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        rollDice = new QPushButton(verticalLayoutWidget_2);
        rollDice->setObjectName(QString::fromUtf8("rollDice"));

        horizontalLayout->addWidget(rollDice);

        rollDiceValue = new QLCDNumber(verticalLayoutWidget_2);
        rollDiceValue->setObjectName(QString::fromUtf8("rollDiceValue"));

        horizontalLayout->addWidget(rollDiceValue);

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
        rollDice->setText(QCoreApplication::translate("Form", "Roll Dice", nullptr));
    } // retranslateUi

};

QT_END_NAMESPACE

#endif // TEST_H

/********************************************************************************
** Form generated from reading UI file 'playerInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PLAYERINFO_H
#define PLAYERINFO_H

#include <QtDebug>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QLineEdit>

QT_BEGIN_NAMESPACE

class NumberOfPlayers : public QWidget
{
public:
    QVBoxLayout *window;
    QHBoxLayout *addPlayersLayout;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QLabel *numberOfPlayersLabel;
    QLCDNumber *numberOfPlayersLCD;
    QPushButton *addPlayer;
    QPushButton *removePlayer;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *centralLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *startGameLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *startGame;
    QSpacerItem *horizontalSpacer;
    NumberOfPlayers(){
        setupUi(this);
        initStartWindow();
    }

    void setupUi(QWidget *numberOfPlayers)
    {
        if (numberOfPlayers->objectName().isEmpty())
            numberOfPlayers->setObjectName(QString::fromUtf8("numberOfPlayers"));
        numberOfPlayers->resize(783, 553);
        window = new QVBoxLayout(numberOfPlayers);
        window->setObjectName(QString::fromUtf8("window"));
        addPlayersLayout = new QHBoxLayout();
        addPlayersLayout->setObjectName(QString::fromUtf8("addPlayersLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        addPlayersLayout->addItem(horizontalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        numberOfPlayersLabel = new QLabel(numberOfPlayers);
        numberOfPlayersLabel->setObjectName(QString::fromUtf8("numberOfPlayersLabel"));

        horizontalLayout->addWidget(numberOfPlayersLabel);

        numberOfPlayersLCD = new QLCDNumber(numberOfPlayers);
        numberOfPlayersLCD->setObjectName(QString::fromUtf8("numberOfPlayersLCD"));

        horizontalLayout->addWidget(numberOfPlayersLCD);

        addPlayer = new QPushButton(numberOfPlayers);
        addPlayer->setObjectName(QString::fromUtf8("addPlayer"));

        horizontalLayout->addWidget(addPlayer);

        removePlayer = new QPushButton(numberOfPlayers);
        removePlayer->setObjectName(QString::fromUtf8("removePlayer"));

        horizontalLayout->addWidget(removePlayer);


        addPlayersLayout->addLayout(horizontalLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        addPlayersLayout->addItem(horizontalSpacer_4);


        window->addLayout(addPlayersLayout);

        centralLayout = new QVBoxLayout();
        centralLayout->setObjectName(QString::fromUtf8("centralLayout"));
        verticalSpacer = new QSpacerItem(20, 40);
        centralLayout->addItem(verticalSpacer);



        window->addLayout(centralLayout);

        startGameLayout = new QHBoxLayout();
        startGameLayout->setObjectName(QString::fromUtf8("startGameLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        startGameLayout->addItem(horizontalSpacer_2);

        startGame = new QPushButton(numberOfPlayers);
        startGame->setObjectName(QString::fromUtf8("startGame"));

        startGameLayout->addWidget(startGame);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        startGameLayout->addItem(horizontalSpacer);


        window->addLayout(startGameLayout);


        retranslateUi(numberOfPlayers);

        QMetaObject::connectSlotsByName(numberOfPlayers);
    } // setupUi

    void retranslateUi(QWidget *numberOfPlayers)
    {
        numberOfPlayers->setWindowTitle(QCoreApplication::translate("numberOfPlayers", "Form", nullptr));
        numberOfPlayersLabel->setText(QCoreApplication::translate("numberOfPlayers", "Number Of Players", nullptr));
        addPlayer->setText(QCoreApplication::translate("numberOfPlayers", "Add player", nullptr));
        removePlayer->setText(QCoreApplication::translate("numberOfPlayers", "Remove player", nullptr));
        startGame->setText(QCoreApplication::translate("numberOfPlayers", "Start game", nullptr));
    } // retranslateUi

    void initStartWindow(){
        QObject::connect(addPlayer, &QPushButton::clicked, this , &NumberOfPlayers::onAddPlayer);
        QObject::connect(removePlayer, &QPushButton::clicked, this ,  &NumberOfPlayers::onRemovePlayer);
    }

    QWidget* newPlayer() {
        QWidget* player = new QWidget();
        QHBoxLayout* verticalLayout = new QHBoxLayout(player);
        //Name
        QString playerName = tr("Hello Player %1").arg(numberOfPlayersLCD->intValue());
        auto name = new QLabel(playerName);
        verticalLayout->addWidget(name);
        //Age
        verticalLayout->addWidget(new QLabel("How old are you"));
        auto edit = new QLineEdit(nullptr);
        verticalLayout->addWidget(edit);

        return player;
    }

    void onAddPlayer() {
        numberOfPlayersLCD->display(numberOfPlayersLCD->intValue() + 1);
        centralLayout->insertWidget(0,newPlayer());
        addPlayersLayout->setEnabled(false);

    }

    void onRemovePlayer() {
        numberOfPlayersLCD->display(numberOfPlayersLCD->intValue() - 1);
        //QList<QWidget *> Widgets = startWindow->frame->layout()->widget()->findChildren<QWidget *>();
        //delete Widgets.first();
    }


};

QT_END_NAMESPACE

#endif // PLAYERINFO_H

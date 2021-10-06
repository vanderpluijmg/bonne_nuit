//
// Created by gregory on 9/27/21.
//

#include <QMainWindow>
#include <iostream>
#include <QSpinBox>
#include <QInputDialog>
#include "View.h"
#include "windows/application.hpp"
#include "windows/test.hpp"
#include "../model/Game/Game.h"
#include "../exceptions/NumberOfPlayersException.h"
#include <QtGlobal>
#include <QMessageBox>

View::View(QWidget *parent, Model *model) : QWidget(parent) {
    model_ = model;
    form->setupUi(this);
    QObject::connect(form->addPlayer, &QPushButton::clicked, this , &View::onAddPlayer);
    QObject::connect(form->removePlayer, &QPushButton::clicked, this , &View::onRemovePlayer);
    QObject::connect(form->startGame, &QPushButton::clicked, this , &View::changeToGameWindow);
    QObject::connect(form->rollDice, &QPushButton::clicked, this, &View::playTurn);
}
void View::update(Modification m, const Observable *obs) {
    if (m.a == "rose move")
        moveRoseView(m.value);
        std::cout<<m.value<<std::endl;
}
void View::changeToGameWindow() {
    try {
        //Game game(form->numberOfPlayers->intValue());
        //model_ = &game;
        model_->addObserver(this);
        form->stackedWidget->setCurrentIndex(1);
        moveRoseView(model_->getRosePlace());
    } catch (NumberOfPlayersException& e) {
        QMessageBox msgBox;
        msgBox.setText("You need at least one player to play");
        msgBox.exec();
    }
}

void View::onAddPlayer() {
    if(form->numberOfPlayers->intValue()>=5){
        QMessageBox msgBox;
        msgBox.setText("You have reached the maximum number of players");
        msgBox.exec();
    } else {
    form->numberOfPlayers->display(form->numberOfPlayers->intValue()+1);
    QVBoxLayout* a = qobject_cast<QVBoxLayout *>(form->centralFrame->layout());
    a->insertWidget(0,newPlayer()); }
}

QWidget *View::newPlayer() {
    QWidget* player = new QWidget();
    QHBoxLayout* verticalLayout = new QHBoxLayout(player);
    QString playerName = tr("Hello Player %1").arg(form->numberOfPlayers->intValue());
    verticalLayout->addWidget(new QLabel(playerName));
    //Add color of player.
    verticalLayout->addWidget(new QLabel("How old are you"));
    auto edit = new QLineEdit();
    verticalLayout->addWidget(edit);
    return player;
}

void View::onRemovePlayer() {
    if(form->numberOfPlayers->intValue()==0){
        QMessageBox msgBox;
        msgBox.setText("You have reached the minimum number of players");
        msgBox.exec();
    }
    else {
        QVBoxLayout *a = qobject_cast<QVBoxLayout *>(form->centralFrame->layout());
        form->numberOfPlayers->display(form->numberOfPlayers->intValue() - 1);
        delete a->takeAt(0);
    }
}

void View::playTurn() {
    // Moves the rose
    currentRosePlace = model_->getRosePlace();
    int diceRoll = model_->rollDice();
    form->rollDiceValue->display(diceRoll);
    model_->moveRose(diceRoll);
    // Play turn of current player.
    //Need to ask where he wants to place it next to the star.
    //model_->playTurnLightOn();
}

void View::moveRoseView(int rosePlace) {
    auto buttonOldRosePlace = qobject_cast<QPushButton*>((form->gridLayout->itemAt(currentRosePlace))->widget());
    auto buttonNewRosePlace = qobject_cast<QPushButton*>((form->gridLayout->itemAt(rosePlace))->widget());
    qDebug() << buttonNewRosePlace->objectName();
    qDebug() << buttonOldRosePlace->objectName();
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/images/img/no_drop.png"), QSize(), QIcon::Normal, QIcon::Off);
    buttonOldRosePlace->setIcon(icon);
    QIcon icon1;
    icon1.addFile(QString::fromUtf8(":/images/img/drop.png"), QSize(), QIcon::Normal, QIcon::Off);
    buttonNewRosePlace->setIcon(icon1);
}

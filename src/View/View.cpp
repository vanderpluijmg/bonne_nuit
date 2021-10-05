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
}
void View::update(std::string_view ,const Observable *obs) {
    auto model = dynamic_cast<const Model *>(obs);
}

void View::changeToGameWindow() {
    try {
        Game game(form->numberOfPlayers->intValue());
        model_ = &game;
        model_->addObserver(this);
        form->stackedWidget->setCurrentIndex(1);
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
    qDebug()<<player->sizePolicy();
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

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
#include <QtGlobal>
#include <QMessageBox>

View::View(QWidget *parent, Model *model) : QWidget(parent) {
    if (model == nullptr)
        throw std::invalid_argument("model can't be null");
    model->addObserver(this);
    form->setupUi(this);
    QObject::connect(form->addPlayer, &QPushButton::clicked, this , &View::onAddPlayer);
    QObject::connect(form->removePlayer, &QPushButton::clicked, this , &View::onRemovePlayer);
    QObject::connect(form->startGame, &QPushButton::clicked, this , &View::changeToGameWindow);
}
void View::update(std::string_view ,const Observable *obs) {
    auto model = dynamic_cast<const Model *>(obs);
}

void View::changeToGameWindow() {
    form->stackedWidget->setCurrentIndex(1);
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
    //QString playerName = tr("Hello Player %1").arg();
    verticalLayout->addWidget(new QLabel("player"));
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

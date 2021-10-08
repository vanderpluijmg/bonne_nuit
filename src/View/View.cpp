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
#include "../exceptions/PawnInPlaceException.h"
#include <QtGlobal>
#include <QMessageBox>

View::View(QWidget *parent) : QWidget(parent) {
    form->setupUi(this);
    QObject::connect(form->addPlayer, &QPushButton::clicked, this , &View::onAddPlayer);
    QObject::connect(form->removePlayer, &QPushButton::clicked, this , &View::onRemovePlayer);
    QObject::connect(form->startGame, &QPushButton::clicked, this , &View::changeToGameWindow);
    QObject::connect(form->rollDice, &QPushButton::clicked, this, &View::playTurn);
}
void View::update(Modification m, const Observable *obs) {
    if (m.a == "rose move")
        moveRoseView();
        std::cout<<m.value<<std::endl;
}
void View::changeToGameWindow() {
    try {
        g = Game(form->numberOfPlayers->intValue());
        g->addObserver(this);;
        form->stackedWidget->setCurrentIndex(1);
        connectStars();
        moveRoseView();
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
    currentRosePlace = g->getRosePlace();
    int diceRoll = g->rollDice();
    form->rollDiceValue->display(diceRoll);
    g->moveRose(diceRoll);
    form->rollDice->setDisabled(true);
    // Play turn of current player.
    //Need to ask where he wants to place it next to the star.
    //model_->playTurnLightOn();
}

void View::moveRoseView() {
    //rosePlace not between 1 ans 9
    QString current = tr("case%1").arg(g->getRosePlace());
    QString old = tr("case%1").arg(currentRosePlace);
    QVBoxLayout* layoutOld = (form->cases->findChild<QVBoxLayout*>(old));
    QPushButton* buttonOldRosePlace = qobject_cast<QPushButton*>(layoutOld->itemAt(0)->widget());
    QVBoxLayout* layoutNew = (form->cases->findChild<QVBoxLayout*>(current));
    QPushButton* buttonNewRosePlace = qobject_cast<QPushButton*>(layoutNew->itemAt(0)->widget());
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/images/img/no_drop.png"), QSize(), QIcon::Normal, QIcon::Off);
    buttonOldRosePlace->setIcon(icon);

    QIcon icon1;
    icon1.addFile(QString::fromUtf8(":/images/img/drop.png"), QSize(), QIcon::Normal, QIcon::Off);
    buttonNewRosePlace->setIcon(icon1);
}

void View::placeAntiPlayerPawns() {
    for (auto& x : g->getNpc())
        placePawnsView(x.getPawns());
}

void View::placePawnsView(const std::list<Pawn>& x) {
    //for (auto& p : x)
}

void View::connectStars() {
    QHBoxLayout* layout = (form->cases->findChild<QHBoxLayout*>("caseStar0"));
    //QList<QPushButton*> lstChildren = layout->findChildren<QPushButton*>();
    //for (auto& obj : lstChildren) {
    for (int i = 0; i<5;i++){

        QObject::connect(a, &QPushButton::clicked, this , &View::onAddStar);
    }
    //QObject::connect(form->star1, &QPushButton::clicked, this , &View::onAddStar);
}

void View::onAddStar() {
    int posY = sender()->objectName().at(4).digitValue();
    try {
        g->playMove(g->getCurrentPlayer(),posY+1);
        QIcon icon1;
        switch (g->getCurrentPlayer().getColor()) {
            case Black:
                icon1.addFile(QString::fromUtf8(":/images/img/star_black.png"), QSize(), QIcon::Normal, QIcon::Off);
                break;
            case Green:
                icon1.addFile(QString::fromUtf8(":/images/img/star_green.png"), QSize(), QIcon::Normal, QIcon::Off);
                break;
            case Purple:
                icon1.addFile(QString::fromUtf8(":/images/img/star_purple.png"), QSize(), QIcon::Normal, QIcon::Off);
                break;
            case Blue:
                icon1.addFile(QString::fromUtf8(":/images/img/star_blue.png"), QSize(), QIcon::Normal, QIcon::Off);
                break;
            case Red:
                icon1.addFile(QString::fromUtf8(":/images/img/star_red.png"), QSize(), QIcon::Normal, QIcon::Off);
                break;
        }
        qobject_cast<QPushButton*>(sender())->setIcon(icon1);
        g->nextPlayer();
    } catch (PawnInPlaceException& e ){
        QMessageBox msgBox;
        msgBox.setText("Sorry you or another player already has a pawn there");
        msgBox.exec();
    }

}



//
// Created by gregory on 9/27/21.
//

#include <QMainWindow>
#include <QSpinBox>
#include <QInputDialog>
#include "View.h"
#include "windows/test.hpp"
#include "../exceptions/NumberOfPlayersException.h"
#include "../exceptions/PawnInPlaceException.h"
#include "windows/newPlayerWidget.h"
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
    else if (m.a == "pawnsBeginning") {
        placePawn(m.x, m.y, m.color);
    } else if (m.a =="turnLightOff"){
        updateGameState(m.gameState);
    } else if (m.a == "currentPlayer"){
        updateCurrentPlayer();
    }
}



void View::changeToGameWindow() {
    try {
        g = Game(form->numberOfPlayers->intValue());
        g->addObserver(this);
        g->turnLightOn();
        g->initGame(form->numberOfPlayers->intValue());
        form->stackedWidget->setCurrentIndex(1);
        //findYoungestPlayer();
        connectStars();
        moveRoseView();
    } catch (NumberOfPlayersException& e) {
        QMessageBox msgBox;
        msgBox.setText("You need at least one player to play");
        msgBox.exec();
    }
}

void View::onAddPlayer() {
    if (form->numberOfPlayers->intValue() >= 5) {
        QMessageBox msgBox;
        msgBox.setText("You have reached the maximum number of players");
        msgBox.exec();
    } else {
        form->numberOfPlayers->display(form->numberOfPlayers->intValue() + 1);
        QVBoxLayout *a = qobject_cast<QVBoxLayout *>(form->centralFrame->layout());
        QWidget* aut = new newPlayerWidget(form->numberOfPlayers->intValue());
        a->insertWidget(0, aut);
    }
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
    disableButtonsNotOnRose(g->getRosePlace());

}

void View::moveRoseView() {
    //rosePlace not between 1 ans 9
    QString current = tr("case%1").arg(g->getRosePlace());
    QString old = tr("case%1").arg(currentRosePlace);
    QVBoxLayout* layoutOld = (form->cases->findChild<QVBoxLayout*>(old));
    auto* buttonOldRosePlace = qobject_cast<QPushButton*>(layoutOld->itemAt(0)->widget());
    QVBoxLayout* layoutNew = (form->cases->findChild<QVBoxLayout*>(current));
    auto* buttonNewRosePlace = qobject_cast<QPushButton*>(layoutNew->itemAt(0)->widget());
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/images/img/no_drop.png"), QSize(), QIcon::Normal, QIcon::Off);
    buttonOldRosePlace->setIcon(icon);

    QIcon icon1;
    icon1.addFile(QString::fromUtf8(":/images/img/drop.png"), QSize(), QIcon::Normal, QIcon::Off);
    buttonNewRosePlace->setIcon(icon1);
}

void View::placePawn(int x, int y, int c) {
        QIcon icon1;
        QString starX = tr("star%1").arg(x);
        QPushButton *star = (form->cases->findChild<QPushButton *>(starX + QString::number(y-1)));
        switch (c) {
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
        star->setIcon(icon1);
}



void View::connectStars() {
    for(int x = 0; x<9; x++){
        QString starX = tr("star%1").arg(x);
        for (int y = 0; y<5; y++){
            qDebug()<<starX + QString::number(y);
            QPushButton* star = (form->cases->findChild<QPushButton*>(starX + QString::number(y)));
            QObject::connect(star, &QPushButton::clicked, this , &View::onAddStar);
        }
    }
}

void View::onAddStar() {
    int posY = sender()->objectName().at(5).digitValue();
    try {
        QIcon icon1;
        std::cout<<g->getCurrentPlayer().getPawns().size()<<" size "<<std::endl;
        g->playMove(posY+1);
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
        form->rollDice->setEnabled(true);
        activateAllButton(false);
    } catch (PawnInPlaceException& e ){
        QMessageBox msgBox;
        msgBox.setText("Sorry you or another player already has a pawn there");
        msgBox.exec();
    }

}

void View::updateGameState(GameState gs) {
    form->label_2->setText("please return a star");
    goIntoNight();
}

void View::disableButtonsNotOnRose(int rosePlace) {
    for (int x =0; x<9; x++) {
        for (int y = 0; y < 5; y++){
            QString starX = tr("star%1").arg(x);
            QPushButton *star = (form->cases->findChild<QPushButton *>(starX + QString::number(y)));
            if (x != rosePlace) {
                star->setDisabled(true);
            } else star->setEnabled(true);
        }
    }
}
//Disable all the buttons except the ones that have a star.
void View::goIntoNight() {
    form->label_2->setText("Please click on the star you would like to turn over");
    form->rollDice->hide();
    form->rollDiceValue->hide();
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/images/img/night.png"), QSize(), QIcon::Normal, QIcon::Off);
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 5; y++) {
            QString starX = tr("star%1").arg(x);
            QPushButton *star = (form->cases->findChild<QPushButton *>(starX + QString::number(y)));
            if (g->getBoard().getCase(x,y).getState() == shining ) //Not sure why but does not make all shining star night logo.
                star->setIcon(icon);
        }
    }
}
void View::activateAllButton(bool activate){
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 5; y++) {
            QString starX = tr("star%1").arg(x);
            QPushButton *star = (form->cases->findChild<QPushButton *>(starX + QString::number(y)));
            star->setDisabled(true);
        }
        }
}

int View::findYoungestPlayer() {
    int min = 0;
    for (int x = 0; x<=form->numberOfPlayers->intValue();x++){
        int age = form->centralFrame->layout()->itemAt(x)->layout()->findChild<QLineEdit*>("ageResp")->text().toInt();
        age > min ? : min =age;
    }
    return min;
}

void View::updateCurrentPlayer() {
    form->currentPlayer->setText(QString::fromStdString("It is player: " + std::to_string(g->getCurrentPlayer().getName()) + "'s turn to make a move"));
}



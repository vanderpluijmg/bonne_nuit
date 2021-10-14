#include <QMainWindow>
#include <QSpinBox>
#include <QInputDialog>
#include "View.h"
#include "windows/mainWindow.hpp"
#include "../exceptions/NumberOfPlayersException.h"
#include "../exceptions/PawnInPlaceException.h"
#include "windows/newPlayerWidget.h"
#include "../exceptions/NoPawnFound.h"
#include "../exceptions/OutOfGameBoardException.h"
#include <QMessageBox>

View::View(QWidget *parent) : QWidget(parent) {
    mainWindow->setupUi(this);
    QObject::connect(mainWindow->addPlayer, &QPushButton::clicked, this , &View::onAddPlayer);
    QObject::connect(mainWindow->removePlayer, &QPushButton::clicked, this , &View::onRemovePlayer);
    QObject::connect(mainWindow->startGame, &QPushButton::clicked, this , &View::changeToGameWindow);
    QObject::connect(mainWindow->rollDice, &QPushButton::clicked, this, &View::rollDiceMoveRose);
}
void View::update(Modification m, const Observable *obs) {
    if (m.description.value() == "ROSE move")
        updateRoseView();
    else if (m.description.value() == "pawnsBeginning")
        placePawn(m.x.value(), m.y.value(), m.color.value());
    else if (m.description.value() == "turnLightOff")
        updateGameState();
    else if (m.description.value() == "currentPlayer")
        updateCurrentPlayer();
    else if(m.description.value() == "winner")
        displayWinner(m.winner.value());
}

void View::changeToGameWindow() {
    try {
        game = Game();
        game->addObserver(this);
        game->turnLightOn();
        game->initGame(mainWindow->numberOfPlayers->intValue(), firstPlayer);
        mainWindow->stackedWidget->setCurrentIndex(1);
        //findYoungestPlayer();
        affectAllStars(true, false, false);
        updateRoseView();
    } catch (NumberOfPlayersException& e) {
        QMessageBox msgBox;
        msgBox.setText("You need at least one player to play");
        msgBox.exec();
    }
}

void View::onAddPlayer() {
    if (mainWindow->numberOfPlayers->intValue() >= 5) {
        QMessageBox msgBox;
        msgBox.setText("You have reached the maximum number of players");
        msgBox.exec();
    } else {
        mainWindow->numberOfPlayers->display(mainWindow->numberOfPlayers->intValue() + 1);
        auto layout = qobject_cast<QVBoxLayout *>(mainWindow->centralFrame->layout());
        auto player = new newPlayerWidget(mainWindow->numberOfPlayers->intValue());
        if (player->getAge()<smallestAge)
            firstPlayer = mainWindow->numberOfPlayers->intValue();
        layout->insertWidget(0, player);
    }
}

void View::onRemovePlayer() {
    if(mainWindow->numberOfPlayers->intValue() == 0){
        QMessageBox msgBox;
        msgBox.setText("You have reached the minimum number of players");
        msgBox.exec();
    }
    else {
        auto *layout = qobject_cast<QVBoxLayout *>(mainWindow->centralFrame->layout());
        mainWindow->numberOfPlayers->display(mainWindow->numberOfPlayers->intValue() - 1);
        delete layout->takeAt(0);
    }
}

void View::rollDiceMoveRose() {
    currentRosePlace_ = game->getRosePlace();
    int diceRoll = game->rollDice();
    mainWindow->rollDiceValue->display(diceRoll);
    game->moveRose(diceRoll);
    mainWindow->rollDice->setDisabled(true);
    affectAllStars(false,true,false,game->getRosePlace());
    mainWindow->label_2->setText("Please place description pawn");
}

void View::updateRoseView() {
    QString currentPlace = tr("case%1").arg(game->getRosePlace());
    QString previousPlace = tr("case%1").arg(currentRosePlace_);
    auto previousLayout = (mainWindow->cases->findChild<QVBoxLayout*>(previousPlace));
    auto previousRosePlace = qobject_cast<QPushButton*>(previousLayout->itemAt(0)->widget());
    auto currentLayout = (mainWindow->cases->findChild<QVBoxLayout*>(currentPlace));
    auto currentRosePlace = qobject_cast<QPushButton*>(currentLayout->itemAt(0)->widget());
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/images/img/no_drop.png"), QSize(), QIcon::Normal, QIcon::Off);
    QIcon icon1;
    icon1.addFile(QString::fromUtf8(":/images/img/drop.png"), QSize(), QIcon::Normal, QIcon::Off);
    previousRosePlace->setIcon(icon);
    currentRosePlace->setIcon(icon1);
}

void View::placePawn(int x, int y, int c) {
    QIcon icon;
    getStarPicture(c,icon);
    QString starX = tr("star%1").arg(x);
    QPushButton *star = (mainWindow->cases->findChild<QPushButton *>(starX + QString::number(y - 1)));
    star->setIcon(icon);
}

void View::onAddStarOrRemove() {
    if (game->getGameState() == lightOn) {
        int posY = sender()->objectName().at(5).digitValue();
        try {
            QIcon icon1;
            std::cout << game->getCurrentPlayer().getPawns().size() << " size " << std::endl;
            game->playMove(posY + 1);
            getStarPicture(game->getCurrentPlayer().getColor(), icon1);
            qobject_cast<QPushButton *>(sender())->setIcon(icon1);
            game->nextPlayer();
            mainWindow->rollDice->setEnabled(true);
            affectAllStars(false,false,true,false,true);
            setMessageGuiding("Please roll the dice");
            game->dayDone();
        } catch (PawnInPlaceException &e) {
            QMessageBox msgBox;
            msgBox.setText("Sorry you or another player already has description pawn there");
            msgBox.exec();
        }
    } else {
        try {
            int posX = sender()->objectName().at(4).digitValue();
            int posY = sender()->objectName().at(5).digitValue();
            game->returnPawn(posX, posY + 1);
            delete sender();
            game->isFinished();
        } catch (NoPawnFoundException &e) {
            QMessageBox msgBox;
            msgBox.setText("Sorry no pawn has been placed here");
            msgBox.exec();
        } catch (OutOfGameBoardException &a) {
            QMessageBox msgBox;
            msgBox.setText("Out of bounds");
            msgBox.exec();
        }
    }
}

void View::updateGameState() {
    setMessageGuiding("Please return description star");
    goIntoNight();
}

void View::goIntoNight() {
    game->turnLightOff();
    mainWindow->label_2->setText("Please click on the star you would like to turn over");
    mainWindow->rollDice->hide();
    mainWindow->rollDiceValue->hide();
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/images/img/night.png"), QSize(), QIcon::Normal, QIcon::Off);
    affectAllStars(false,false,true,false,false);
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 5; y++) {
            QString starX = tr("star%1").arg(x);
            QPushButton *star = (mainWindow->cases->findChild<QPushButton *>(starX + QString::number(y)));
            if (game->getBoard().getCase(x, y + 1).getState() == SHINING ){
                std::cout<<x <<" " <<y<<std::endl;//Not sure why but does not make all SHINING star night logo.
                star->setIcon(icon);
            } else {
                star->setHidden(true);
            }
        }
    }
}

void View::affectAllStars(bool connectStars, bool disableNotOnRose, bool activateAll, int rosePlace, bool activate) {
    for (int x = 0; x < 9; x++) {
        QString starX = tr("star%1").arg(x);
        for (int y = 0; y < 5; y++) {
            QPushButton *star = (mainWindow->cases->findChild<QPushButton *>(starX + QString::number(y)));
            if (disableNotOnRose) {
                if (x != rosePlace)
                    star->setDisabled(true);
                else star->setEnabled(true);
            } else if (connectStars) {
                QObject::connect(star, &QPushButton::clicked, this, &View::onAddStarOrRemove);
            } else if (activateAll) {
                star->setDisabled(activate);
            }
        }
    }
}

void View::updateCurrentPlayer() {
    mainWindow->currentPlayer->setText(QString::fromStdString("It is player: " + std::to_string(game->getCurrentPlayer().getName()) + "'s turn to make description move"));
}

void View::getStarPicture(int c, QIcon& icon) {
    switch (c) {
        case BLACK:
            icon.addFile(QString::fromUtf8(":/images/img/star_black.png"), QSize(), QIcon::Normal, QIcon::Off);
            break;
        case GREEN:
            icon.addFile(QString::fromUtf8(":/images/img/star_green.png"), QSize(), QIcon::Normal, QIcon::Off);
            break;
        case PURPLE:
            icon.addFile(QString::fromUtf8(":/images/img/star_purple.png"), QSize(), QIcon::Normal, QIcon::Off);
            break;
        case BLUE:
            icon.addFile(QString::fromUtf8(":/images/img/star_blue.png"), QSize(), QIcon::Normal, QIcon::Off);
            break;
        case RED:
            icon.addFile(QString::fromUtf8(":/images/img/star_red.png"), QSize(), QIcon::Normal, QIcon::Off);
            break;
    }
}

void View::setMessageGuiding(const QString& msg) {
    mainWindow->label_2->setText(msg);
}

void View::displayWinner(int winner) {
    QMessageBox msgBox;
    msgBox.setText(QString::number(winner));
    msgBox.exec();
}




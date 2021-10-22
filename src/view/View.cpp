#include <QMainWindow>
#include <QSpinBox>
#include <QInputDialog>
#include "View.h"
#include "../exceptions/NumberOfPlayerException.h"
#include "../exceptions/PawnInPlaceException.h"
#include "windows/newPlayerWidget.h"
#include "../exceptions/NoPawnFound.h"
#include "../exceptions/OutOfGameBoardException.h"
#include "windows/winnerWidget.h"
#include <QMessageBox>
#include <QScreen>

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
        affectAllStars(true, false, false);
        affectAllRoses(false);
        updateRoseView();
        affectAllStars(false,false,true,false,true);
        setMessageGuiding("Please roll the dice");
    } catch (NumberOfPlayerException& e) {
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
        layout->insertWidget(0, player);
        if (player->getAgeResp()<smallestAge) {
            smallestAge = player->getAgeResp();
            firstPlayer = player->getName();
        }
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
    mainWindow->label_2->setText("Please place a pawn");
}

void View::updateRoseView() {
    QString currentPlace = tr("caseRose%1").arg(game->getRosePlace());
    QString previousPlace = tr("caseRose%1").arg(currentRosePlace_);
    auto previousLayout = (mainWindow->cases->findChild<QVBoxLayout*>(previousPlace));
    auto previousRosePlace = qobject_cast<QLabel*>(previousLayout->itemAt(0)->widget());
    auto currentLayout = (mainWindow->cases->findChild<QVBoxLayout*>(currentPlace));
    auto currentRosePlace = qobject_cast<QLabel*>(currentLayout->itemAt(0)->widget());
    QPixmap rose(":/images/img/drop.png");
    QPixmap noRose(":/images/img/no_drop.png");
    previousRosePlace->setPixmap(noRose);
    previousLayout->setAlignment(Qt::AlignCenter);
    currentRosePlace->setPixmap(rose);
    currentRosePlace->setAlignment(Qt::AlignCenter);
}

void View::placePawn(int x, int y, int c) {
    QIcon icon;
    getStarPicture(c,icon);
    QString starX = tr("star%1").arg(x);
    QPushButton *star = (mainWindow->cases->findChild<QPushButton *>(starX + QString::number(y - 1)));
    star->setFixedSize(icon.actualSize(icon.availableSizes().first()));
    star->setIcon(icon);
    star->setIconSize(icon.availableSizes().first());
}

void View::onAddStarOrRemove() {
    if (game->getGameState() == LIGHTON) {
        int posY = sender()->objectName().at(5).digitValue();
        try {
            QIcon icon;
            game->playMove(posY + 1);
            getStarPicture(game->getCurrentPlayer().getColor(), icon);
            auto star = qobject_cast<QPushButton *>(sender());
            star->setFixedSize(icon.actualSize(icon.availableSizes().first()));
            star->setIcon(icon);
            star->setIconSize(icon.availableSizes().first());
            game->nextPlayer();
            mainWindow->rollDice->setEnabled(true);
            affectAllStars(false,false,true,false,true);
            setMessageGuiding("Please roll the dice");
            game->dayDone();
        } catch (PawnInPlaceException &e) {
            QMessageBox msgBox;
            msgBox.setText("Sorry you or another player already has a pawn there");
            msgBox.exec();
        }
    } else {
        try {
            int posX = sender()->objectName().at(4).digitValue();
            int posY = sender()->objectName().at(5).digitValue();
            QIcon icon = QIcon();
            getStarPicture(game->getBoard().getCase(posX, posY + 1).getColor(), icon);
            qobject_cast<QPushButton*>(sender())->setIcon(icon);
            game->returnPawn(posX, posY + 1);
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
    setMessageGuiding("Please return a star");
    goIntoNight();
}

void View::goIntoNight() {
    game->nextPlayer();
    affectAllRoses(true);
    mainWindow->label_2->setText("Please click on a star");
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
    mainWindow->currentPlayer->setText(QString::fromStdString("It is player " + std::to_string(game->getCurrentPlayer().getName()) + "'s turn"));
}

void View::getStarPicture(int c, QIcon& icon) {
    switch (c) {
        case BLACK:
            icon.addPixmap(QPixmap(":/images/img/star_black.png"), QIcon::Normal);
            icon.addPixmap(QPixmap(":/images/img/star_black.png"), QIcon::Disabled);
            break;
        case GREEN:
            icon.addPixmap(QPixmap(":/images/img/star_green.png"), QIcon::Normal);
            icon.addPixmap(QPixmap(":/images/img/star_green.png"), QIcon::Disabled);
            break;
        case PURPLE:
            icon.addPixmap(QPixmap(":/images/img/star_purple.png"), QIcon::Normal);
            icon.addPixmap(QPixmap(":/images/img/star_purple.png"), QIcon::Disabled);
            break;
        case BLUE:
            icon.addPixmap(QPixmap(":/images/img/star_blue.png"), QIcon::Normal);
            icon.addPixmap(QPixmap(":/images/img/star_blue.png"), QIcon::Disabled);
            break;
        case RED:
            icon.addPixmap(QPixmap(":/images/img/star_red.png"), QIcon::Normal);
            icon.addPixmap(QPixmap(":/images/img/star_red.png"), QIcon::Disabled);
            break;
        default :
            icon.addPixmap(QPixmap(":/images/img/night.png"), QIcon::Normal);
            icon.addPixmap(QPixmap(":/images/img/night.png"), QIcon::Disabled);
            break;
    }
}

void View::setMessageGuiding(const QString& msg) {
    mainWindow->label_2->setText(msg);
}

void View::displayWinner(int winner) {
    qDebug()<<winner;
    auto winnerW = new winnerWidget(winner);
    mainWindow->stackedWidget->addWidget(winnerW);
    mainWindow->stackedWidget->setCurrentIndex(2);
}

void View::affectAllRoses(bool hidden) {
    for (int i = 0; i<9;i++) {
        QString rose = tr("caseRose%1").arg(i);
        auto roseLayout = (mainWindow->cases->findChild<QVBoxLayout *>(rose));
        auto rosePlace = qobject_cast<QLabel *>(roseLayout->itemAt(0)->widget());
        hidden ? rosePlace->setHidden(true) : (rosePlace->setPixmap(QPixmap(":/images/img/no_drop.png"))
                , rosePlace->setAlignment(Qt::AlignCenter)) ;
    }
}




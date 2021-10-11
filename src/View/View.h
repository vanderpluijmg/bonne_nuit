//
// Created by gregory on 9/27/21.
//

#ifndef ATLIR5_BONNE_NUIT_VIEW_H
#define ATLIR5_BONNE_NUIT_VIEW_H
#include <QWidget>
#include <QLayout>
#include <QStackedWidget>
#include <QMainWindow>
#include "../Utils/Observable.h"
#include "../Utils/Observer.h"
#include "../model/Model.h"
#include "windows/test.hpp"
#include "../model/Game/Game.h"


class View : public QWidget, public Observer {
private:
    int currentRosePlace = 0;
    std::optional<Game> g;
    Ui_Form* form  = new Ui_Form ();

public:

    /**
     * Default constructor for view of game.
     * @param parent
     */
    explicit View(QWidget * parent = nullptr);

    /**
     * Default destructor
     */
    ~View() override =default;

    /**
     * Changes to game window when start button is pressed in GUI.
     */
    void changeToGameWindow();

    /**
     * Updates the view when the model has changed.
     * @param m Modification that have been made in the model.
     * @param obs Model that has been changed.
     */
    void update(Modification m, const Observable *obs) override;

    /**
     * Create a new players when on add player button in GUI is clicked.
     * @return Widget of new player.
     */
    QWidget *newPlayer();

    /**
     * Plays a turn for the current player
     */
    void playTurn();

    /**
     * Moves the rose in the view.
     * @param rosePlace New position of rose.
     */
    void moveRoseView();

    /**
     * When add players button in GUI is clicked.
     */
    void onAddPlayer();
    /**
     * When remove player button in GUI is clicked.
     */
    void onRemovePlayer();

    void connectStars();

    void placePawn(int x, int y, int c);

    void onAddStar();

    void updateGameState(GameState gs);

    void disableButtonsNotOnRose(int rosePlace);

};

#endif //ATLIR5_BONNE_NUIT_VIEW_H

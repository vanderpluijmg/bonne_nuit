//
// Created by greg on 17.09.21.
//

#ifndef ATLIR5_BONNE_NUIT_GAME_H
#define ATLIR5_BONNE_NUIT_GAME_H

#include <list>
#include <iostream>
#include "Player.h"

/**
 * Defines the states in which the game is currently in.
 */
enum GameState {notStarted, throwDice , placeStar, lightOff, turnOverStar ,lightOn};
struct Turn{
    int diceRoll;

    std::list<Color> pawnsToPlace_color;
};

/**
 * Defines a listener
 */
class Listener{
public:
    /**
    * updates board after publisher sends an update.
    * @param t Update of publisher.
    */
    virtual void onEvent (Turn t) = 0;
};

class Game {
private:
    GameState gameState;
    Player currentPlayer;
    std::vector<Player>players;
    std::vector<Listener*> listeners;
public:
    /**
     * Constructor of Game
     * @param numberOfPlayers Number of players who are going to play.
     */
    Game(int numberOfPlayers){
        gameState = notStarted;
        populateGame(numberOfPlayers);
        currentPlayer = players.at(0);
    }
    /**
     * Populates the game with number of players.
     */
    std::list<Player> populateGame(int);

    /**
     * Getter for the current playing player.
     * @return The current player that is playing.
     */
    const Player &getCurrentPlayer() const;

    /**
     * Gets current state of the game.
     * @return Current state of game.
     */
    GameState getGameState() const;

    /**
     * Gets players of game
     * @return Players that are playing the game.
     */
    std::vector<Player> getPlayers();

    /**
     * Gets the paws of a specific player.
     * @return
     */
    std::list<Pawn> getPlayerHand(int);

    /**
     * Changes to the next player
     */
    void nextPlayer();

    /**
     * Rolls a dice.
     * @return Value of dice after it has been rolled.
     */
    int rollDice();

    /**
     * Adds a listener to the publisher.
     * @param lis Listener to add.
     */
    void addListener( Listener* lis);

    /**
     * Notifies all listeners
     * @param t Information that has been updated.
     */
    void notify (Turn t);

    /**
     * Rolls dice and passes value to board.
     * @param t Information that has been updated.
     */
    void moveRose(Turn t);

    void addPawnsToPlace(Turn);
};


#endif //ATLIR5_BONNE_NUIT_GAME_H

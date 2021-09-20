//
// Created by greg on 17.09.21.
//

#ifndef ATLIR5_BONNE_NUIT_GAME_H
#define ATLIR5_BONNE_NUIT_GAME_H

#include <list>
#include <iostream>
#include "Player.h"
#include "Board.h"

/**
 * Defines the states in which the game is currently in.
 */
enum GameState {notStarted, throwDice , placeStar, lightOff, turnOverStar ,lightOn};

class Game {
private:
    GameState gameState;
    Player currentPlayer;
    std::vector<Player>players;
    Board board;

    /**
    * Populates the game with number of players.
    */
    std::list<Player> populateGame(int);

    /**
     * Adds all pawns that have not yet been taken by a player.
     */
    void addPawnsToPlace(int);


public:
    /**
     * Constructor of Game
     * @param numberOfPlayers Number of players who are going to play.
     */
    Game(int numberOfPlayers);

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
     * Rolls dice and passes value to board.
     * @param t Information that has been updated.
     */
    void moveRose();

    /**
     * Places the current players pawns.
     */
    bool placePawn(int, int);

     Board &getBoard() ;
};


#endif //ATLIR5_BONNE_NUIT_GAME_H

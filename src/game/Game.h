#ifndef BONNE_NUIT_GAME_H
#define BONNE_NUIT_GAME_H


#include <list>
#include <iostream>
#include "Player.h"
#include "Board.h"
#include "../utils/Observable.h"
#include "GameState.h"

class Game : public Observable {

private:
    std::list<Observer *> observers;
    GameState gameState_;
    Player currentPlayer;
    std::vector<Player> players;
    std::vector<Player> npc_;
    Board board;
    int returnedPawns;

    /**
    * Populates the game with number of players.
    */
    void populateGame(int);

    /**
     * Remove the pawn of the current player.
     */
    void removePawnCurrentPlayer();

    /**
     * Adds all pawns that have not yet been taken by any players.
     */
    void addPawnsToPlace(int);

    /**
     * Setter for game state.
     * @param gameState Game state to set to.
     */
    void setGameState(GameState gameState);

public:

    /**
     * Constructor of class Game.
     */
    Game();

    /**
     * Initializes a game with the number of players.
     * @param numberOfPlayers Number of players to initializes game with.
     */
    void initGame(int numberOfPlayers, int firstPlayer);

    /**
     * Gets all the players that are playing.
     * @return A list of all the players.
     */
    std::vector<Player> getPlayers();

    /**
     * Notifies view of all the pawns that have to be placed by the pc.
     */
    void notifyStartingNpcPawn();

    /**
    * Changes to the next player.
    */
    void nextPlayer();

    /**
     * Simulates a dice roll.
     * @return The value of the dice.
     */
    static int rollDice();

    /**
     * Moves ROSE and notifies view.
     * @param value Value of rolled dice.
     */
    void moveRose(int value);

    /**
     * Getter of the current place of the ROSE.
     * @return The current place of the ROSE.
     */
    int getRosePlace();

    /**
     * Places the current players pawns.
     */
    bool placePawn(int, int);

    /**
     * Getter for the game board.
     * @return game board.
     */
    Board &getBoard();

    /**
     * Plays the current players move. Removes a pawn from his hand.
     * @param y Y coordinates of the start he would like to place.
     */
    void playMove(int y);

    /**
     * Return pawn of current player at coordinates x and y.
     * @param y X coordinates of star.
     * @param x Y coordinates of star.
     */
    void returnPawn(int x, int y);

    /**
     * Checks if the game is finished.
     */
    void isFinished();

    /**
     * Getter for the current playing player.
     * @return The current player that is playing.
     */
    [[nodiscard]] Player getCurrentPlayer();

    /**
     * Gets current state of the game.
     * @return Current state of game.
     */
    [[nodiscard]] GameState getGameState() const;

    /**
    * Check if the fist part of the game is done. Notifies view if done.
     */
    void dayDone();

    /**
     * Turns "light off" during the game.
     */
    void turnLightOff();

    /**
     * Turns "lights on" during the game.
     */
    void turnLightOn();

    /**
     * Subscribes an observer to game.
     * @param observer Observer that needs to subscribe.
     */
    void addObserver(Observer *observer) override;

    /**
     * Notifies all subscribers of game.
     * @param m Modifications that have happened.
     */
    void notify(Modification m) override;

    /**
     * Gets a list of pawn of all the players that are not playing.
     * @return List of players that are not in the game.
     */
    [[nodiscard]] const std::vector<Player> &getNpc() const;

    int determineWinner();
};


#endif //BONNE_NUIT_GAME_H

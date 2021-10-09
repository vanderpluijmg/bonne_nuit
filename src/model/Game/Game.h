//
// Created by greg on 17.09.21.
//

#ifndef ATLIR5_BONNE_NUIT_GAME_H
#define ATLIR5_BONNE_NUIT_GAME_H

#include <list>
#include <iostream>
#include "Player.hpp"
#include "Board.h"
#include "../../Utils/Observable.h"
#include "GameState.hpp"
#include "../Model.h"

class Game : public Observable {

private:
    std::list<Observer *> observers;
    GameState gameState_;
    Player currentPlayer;
    std::vector<Player>players;
    std::vector<Player>npc_;
    Board board;

    /**
    * Populates the game with number of players.
    */
    void populateGame(int);

    static void removePawnCurrentPlayer(std::list<Pawn>& pawns);

    /**
     * Adds all pawns that have not yet been taken by startWindow player.
     */
    void addPawnsToPlace(int);


public:

    /**
     * Default constructor for Game
    */
    Game() : Game(5){};

    /**
     * Constructor of Game
     * @param numberOfPlayers Number of players who are going to play.
     */
    explicit Game(int numberOfPlayers);

    void initGame(int numberOfPlayers);

    /**
     * Gets players of game
     * @return Players that are playing the game.
     */
    std::vector<Player> getPlayers();

    /**
     * Gets the paws of startWindow specific player.
     * @return
     */
    std::list<Pawn> getPlayerHand(int);

    void notifyBoard();

    /**
     * Changes to the next player
     */
    void nextPlayer();

    /**
     * Simulates a dice roll.
     * @return The value of the dice.
     */
     int rollDice() ;

    /**
     * Rolls dice and passes value to board.
     * @param value Value of rolled dice
     */
    void moveRose(int value) ;

    int getRosePlace() ;
    /**
     * Places the current players pawns.
     */
    bool placePawn(int, int);

    /**
     * Getter for the game board.
     * @return game board.
     */
    Board &getBoard() ;

    /**
     * Setter for game state
     * @param gameState Game state to set to.
     */
    void setGameState(GameState gameState);

    /**
     * Plays startWindow move for startWindow player.
     * @param player Player to play move for.
     */
    void playMove(Player player, int);

    /**
     * Return pawn of current player.
     */
    bool returnPawn(int, int);

    /**
     * Gets winner of the game.
     * @return The player that has won the current game.
     */
    Player getWinner();

    /**
     * Auto fills startWindow game with pawn. Used to test second part of the game.
     */
    void autofill();

    /**
    * Plays turn of player in lights on state of game.
    */
    void playTurnLightOn(int) ;

    /**
     * Plays turn of player in light off on state of the game.
     */
    void playTurnLightOff(int,int) ;

    /**
     * Checks if the game is finished.
     * @return True if the game is finished.
     */
    bool isFinished() ;

    /**
     * Getter for the current playing player.
     * @return The current player that is playing.
     */
    [[nodiscard]] Player getCurrentPlayer() const ;

    /**
     * Gets current state of the game.
     * @return Current state of game.
     */
    [[nodiscard]] GameState getGameState() const ;

    /**
    * Check if game is done.
     * @return True if game is done.
     */
    bool isDone() ;

    /**
     * Turns light off during the game.
     */
    void turnLightOff() ;

    /**
     * Turns lights on during the game.
     */
    void turnLightOn() ;

    void addObserver(Observer *observer) override;
    void notify(Modification m) override;

    const std::vector<Player> &getNpc() const;


};


#endif //ATLIR5_BONNE_NUIT_GAME_H

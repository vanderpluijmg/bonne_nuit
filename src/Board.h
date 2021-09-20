#ifndef ATLIR5_BONNE_NUIT_BOARD_H
#define ATLIR5_BONNE_NUIT_BOARD_H

#include <string>
#include "Game.h"

/**
 * Represents the game board of the game.
 */
class Board : public Listener {
private:
    int gameBoard[9][6];
    int rosePlace;
public:

    /**
     * Default constructor for board.
     * @param g Publisher to subscribe to.
     */
    Board(Game &g);

    /**
     * Pseudo-constructor for board. Initializes board in beginning of game.
     */
    void initGameBoard();

    /**
     * Turns board to String for TUI.
     * @return String of board.
     */
    std::string toString();

    /**
     * updates board after publisher sends an update.
     * @param t Update of publisher.
     */
    virtual void onEvent(Turn t);

    /**
     * Moves rose on display.
     * @param Dice roll of user.
     */
    void moveRose(int);

    /**
     * Places the remaining pawns graphically that are not used.
     */
    void placePawnsBeg(std::list<Color>);

    /**
     * Places a player pawn where he wished to on the board.
     */
    void placePawn(int, int);

};

#endif //ATLIR5_BONNE_NUIT_BOARD_H

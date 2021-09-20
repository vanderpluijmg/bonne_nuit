#ifndef ATLIR5_BONNE_NUIT_BOARD_H
#define ATLIR5_BONNE_NUIT_BOARD_H

#include <string>
#include <list>
#include "Pawn.h"

/**
 * Represents the game board of the game.
 */
class Board {
private:
    Pawn gameBoard[9][6];
    int rosePlace;


public:

    /**
     * Default constructor for board.
     * @param g Publisher to subscribe to.
     */
    Board();

    /**
     * Turns board to String for TUI.
     * @return String of board.
     */
    std::string toString();

    /**
     * Moves rose on display.
     * @param Dice roll of user.
     */
    void moveRose(int);

    /**
    * Initializes all cases of the game to color "None" and state "none".
    */
    void initGameBoard();

    /**
     * Places the remaining pawns graphically that are not used.
     */
    void placePawnsBeg(std::list<Color>);

    /**
     * Places a player pawn where he wished to on the board.
     */
    void placePawn(int, int, Color);

    Pawn getCase (int,int);

};

#endif //ATLIR5_BONNE_NUIT_BOARD_H

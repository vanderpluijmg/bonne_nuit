#ifndef ATLIR5_BONNE_NUIT_BOARD_H
#define ATLIR5_BONNE_NUIT_BOARD_H

#include <string>
#include <list>
#include "Pawn.hpp"
#include "Player.hpp"

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
     */
    Board();

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
    void placePawnsBeg(Color);

    /**
     * Places startWindow player pawn where he wished to on the board.
     * @return True if pawn has been placed.
     */
    bool placePawn(int, int, Color);

    /**
     * Gets startWindow specific case in the game board.
     * @return pawn that occupies the specific case.
     */
    Pawn getCase(int, int);

    /**
     * Gets the x coordinates of the rose.
     * @return X coordinates of the rose.
     */
    [[nodiscard]] int getRosePlace() const;

    /**
     * Turns startWindow shining pawn into startWindow non shining pawn.
     * @param x X coordinates if the case.
     * @param y Y coordinates of the case.
     */
    void removePawn(int x,int y);
};

#endif //ATLIR5_BONNE_NUIT_BOARD_H

#ifndef BONNE_NUIT_BOARD_H
#define BONNE_NUIT_BOARD_H


#include <string>
#include <list>
#include "Pawn.h"
#include "Player.h"

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
     * Moves ROSE on display.
     * @param Dice roll of user.
     */
    void moveRose(int);

    /**
    * Initializes all cases of the game to color "NONE" and state "NOTDEFINED".
    */
    void initGameBoard();

    /**
     * Places the remaining pawns that are not used.
     */
    void placePawnsNpcPlayers(Color color);

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
     * Gets the x coordinates of the ROSE.
     * @return X coordinates of the ROSE.
     */
    [[nodiscard]] int getRosePlace() const;

    /**
     * Turns startWindow SHINING pawn into startWindow non SHINING pawn.
     * @param x X coordinates if the case.
     * @param y Y coordinates of the case.
     */
    void removePawn(int x,int y);
};




#endif //BONNE_NUIT_BOARD_H

//
// Created by greg on 17.09.21.
//

#include <iostream>
#include "Board.h"
#include "../../ressources/random.hpp"
#include "../../exceptions/OutOfGameBoardException.h"
#include "../../exceptions/PawnInPlaceException.h"
#include "../../exceptions/NoPawnFound.h"
#include "../../Utils/Observable.h"

Board::Board() {
    rosePlace = 0;

}

Pawn Board::getCase(int x, int y) {
    return gameBoard[x][y];
}

void Board::initGameBoard() {
    for (auto x = 0; x < 9; x++)
        for (auto y = 0; y <= 5; y++)
            gameBoard[x][y] = Pawn(Color::None, none);
}

bool Board::placePawn(int x, int y, Color color) {
    if (!((x <= 8 && x >= 0) && (y < 6 && y > 0)))
        throw OutOfGameBoardException("Sorry the coordinates you gave are not in the game board ("
                                      + std::to_string(x) + std::to_string(y) + " )") ;
    if (getCase(x, y).getColor() != Color::None)
        throw PawnInPlaceException("Sorry there is currently startWindow pawn in this case");
    else {
        gameBoard[x][y] = Pawn(color, shining);
        return true;
    }
}

void Board::placePawnsBeg(Color color) {
    nvs::randomize();
    for (auto i = 1; i < 4; i++) {
        int randomBetween0and8 = nvs::random_value(0, 8);
        int randomBetween1and5 = nvs::random_value(1, 5);
        while (gameBoard[randomBetween0and8][randomBetween1and5].getState() == shining) {
            randomBetween0and8 = nvs::random_value(0, 8);
            randomBetween1and5 = nvs::random_value(1, 5);
        }
        gameBoard[randomBetween0and8][randomBetween1and5] = Pawn(color, shining);
    }

}

int Board::getRosePlace() const {
    return rosePlace;
}

void Board::moveRose(int t) {
    int place = t + rosePlace >= 9 ? (std::abs(9 - (t + rosePlace))) : (t + rosePlace);
    gameBoard[place][0].setState(rose);
    gameBoard[rosePlace][0].setState(open);
    rosePlace = place;
}

void Board::removePawn(int x, int y) {
    getCase(x,y).getColor() == Color::None ? throw NoPawnFoundException("Sorry the coordinates do not lead to startWindow pawn") :
    gameBoard[x][y].setState(notShining);


}

/**std::string Board::toString() {
    std::string result = "";
    for (auto i = 0; i < 9; i++) {
        for (auto j = 0; j < 6; j++) {
            if (gameBoard[i][j] == 2)
                result.append(" |r| ");
            else if (gameBoard[i][j] ==1)
                result.append(" |b| ");
            else
                result.append(" | | ");
        }
        result.append("\n");
    }
    return result;
}*/

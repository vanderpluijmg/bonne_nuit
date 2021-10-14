#include "Board.h"
#include "../ressources/random.hpp"
#include "../exceptions/OutOfGameBoardException.h"
#include "../exceptions/PawnInPlaceException.h"
#include "../exceptions/NoPawnFound.h"

Board::Board() {
    rosePlace = 0;
}

Pawn Board::getCase(int x, int y) {
    return gameBoard[x][y];
}

void Board::initGameBoard() {
    for (auto &x: gameBoard)
        for (auto y = 0; y <= 5; y++)
            x[y] = Pawn(Color::NONE, NOTDEFINED);
}

bool Board::placePawn(int x, int y, Color color) {
    if (!((x <= 8 && x >= 0) && (y < 6 && y > 0)))
        throw OutOfGameBoardException("Sorry the coordinates you gave are not in the game board ("
                                      + std::to_string(x) + std::to_string(y) + " )");
    if (getCase(x, y).getColor() != Color::NONE)
        throw PawnInPlaceException("Sorry there is currently startWindow pawn in this case");
    else {
        gameBoard[x][y] = Pawn(color, SHINING);
        return true;
    }
}

void Board::placePawnsNpcPlayers(Color color) {
    nvs::randomize();
    for (auto i = 1; i < 4; i++) {
        int randomBetween0and8 = nvs::random_value(0, 8);
        int randomBetween1and5 = nvs::random_value(1, 5);
        while (gameBoard[randomBetween0and8][randomBetween1and5].getState() == SHINING) {
            randomBetween0and8 = nvs::random_value(0, 8);
            randomBetween1and5 = nvs::random_value(1, 5);
        }
        placePawn(randomBetween0and8, randomBetween1and5, color);
    }
}

int Board::getRosePlace() const {
    return rosePlace;
}

void Board::moveRose(int t) {
    int place = t + rosePlace >= 9 ? (std::abs(9 - (t + rosePlace))) : (t + rosePlace);
    gameBoard[place][0].setState(ROSE);
    rosePlace = place;
}

void Board::removePawn(int x, int y) {
    getCase(x, y).getColor() == Color::NONE ? throw NoPawnFoundException("Sorry there is no pawn here") :
    gameBoard[x][y].setState(NOTSHINING);
}
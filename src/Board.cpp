//
// Created by greg on 17.09.21.
//

#include <iostream>
#include "Board.h"
#include "../ressources/random.hpp"


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

void Board::placePawn(int x, int y, Color color) {
    gameBoard[x][y] = Pawn(color, shining);
}

void Board::placePawnsBeg(std::list<Color> colors) {
    for (auto &color: colors) {
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

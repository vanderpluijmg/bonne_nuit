//
// Created by greg on 17.09.21.
//

#include <iostream>
#include "Board.h"

Board::Board(Game &g) {
    g.addListener(this);
    rosePlace=0;
}

void Board::initGameBoard() {
    for (auto x = 0; x < 9; x++) {
        for (auto y = 0; y < 5; y++) {
            if (x == 0 && y == 0)
                gameBoard[x][y] = 2;
        }
    }
}

void Board::onEvent(Turn t) {
    moveRose(t.diceRoll);
    placePawnsBeg(t.pawnsToPlace_color);
}

void Board::placePawnsBeg(std::list<Color> colors) {
    for (auto& color: colors)
        for (auto i = 0; i<5;i++){
            gameBoard[]
        }
}
int randomgen(int max, int min) //Pass in range
{
    srand(time(NULL));  //Changed from rand(). srand() seeds rand for you.
    int random = rand() % max + min;
    return random;
}

void Board::moveRose(int t) {
    //gameBoard[ 9-(t+rosePlace) >= 0 ?  t+rosePlace :  std::abs( 9-(t+rosePlace)  )][0] = 2;
    //gameBoard[rosePlace][0] = 0;
    gameBoard[rosePlace][0] = 0;
    rosePlace += t;
}

std::string Board::toString() {
    std::string result = "";
    for (auto i = 0; i < 9; i++) {
        for (auto j = 0; j < 6; j++) {
            gameBoard[i][j] == 2 ? result.append(" |r| ") : result.append(" || ");
        }
        result.append("\n");
    }
    return result;
}

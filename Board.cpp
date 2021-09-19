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
    for (auto x = 0; x < 9; x++)
        for (auto y = 0; y < 5; y++)
            gameBoard[x][y]=0;
}

void Board::onEvent(Turn t) {
    moveRose(t.diceRoll);
    placePawnsBeg(t.pawnsToPlace_color);
}

void Board::placePawnsBeg(std::list<Color> colors) {
    for (auto& color: colors) {
        for (auto i = 1; i < 4; i++) {
            int randomBetween0and8 = rand()%(8-0)+0;
            int randomBetween1and5 = rand()%(5-1)+1;
            while(gameBoard[randomBetween0and8][randomBetween1and5]==1){
                randomBetween0and8 = rand()%(8-1)+1;
                randomBetween1and5 = rand()%(5-1)+1;
            }
            gameBoard[randomBetween0and8][randomBetween1and5]=1;
        }
    }
}

void Board::moveRose(int t) {
    //gameBoard[ 9-(t+rosePlace) >= 0 ?  t+rosePlace :  std::abs( 9-(t+rosePlace)  )][0] = 2;
    //gameBoard[2][0] = 2;
    //rosePlace += t;
    //gameBoard[0][0]=2;
    //gameBoard[1][0]=2;
    //gameBoard[2][0]=2;
    //gameBoard[3][0]=2;
    //gameBoard[4][0]=2;
    //gameBoard[5][0]=2;
    //gameBoard[6][0]=2;
    //gameBoard[7][0]=2;
    //gameBoard[8][0]=2;
}

std::string Board::toString() {
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
}

#include <iostream>
#include <list>
#include "Pawn.h"
#include "Game.h"
#include "Board.h"

using namespace std;

int main() {
    Game g(4);
    Board *b = new Board(g);
    b->initGameBoard();
    g.moveRose(Turn());
    std::cout << b->toString() << std::endl;
    delete b;

}

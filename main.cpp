#include <iostream>
#include <list>
#include "Pawn.h"
#include "Game.h"
#include "Board.h"

using namespace std;

int main() {
    Game g(4);
    Board *b = new Board(g);
    g.addPawnsToPlace(Turn(),1);
    std::cout << b->toString() << std::endl;
    delete b;

}

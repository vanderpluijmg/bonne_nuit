#include <iostream>
#include <list>
#include "Pawn.h"
#include "Game.h"
#include "Board.h"
#include "../ressources/random.hpp"

using namespace std;

int main() {
    nvs::randomize();
    Game g(5);
    Board b = Board(g);
    b.initGameBoard();
    g.addPawnsToPlace(Turn(), 3);
    std::cout << b.toString() << std::endl;
}

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
    g.addPawnsToPlace(3);
}

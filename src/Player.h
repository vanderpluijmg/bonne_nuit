//
// Created by greg on 17.09.21.
//

#ifndef ATLIR5_BONNE_NUIT_PLAYER_H
#define ATLIR5_BONNE_NUIT_PLAYER_H


#include <vector>
#include <string>
#include <map>
#include <list>
#include "Pawn.h"

class Player {
private:
    int _name;
    Color _color;
    std::list<Pawn> pawns;
public:

    /**
     * Default consturctor for player.
     */
    Player() {}

    /**
     * Constructor for player
     * @param name Name of player
     * @param color Color of playerplayer.getPawns()
     */
    Player(int name, Color color){
      _name= name;
      _color = color;
        for (auto i = 0; i < 3; i++) {
            pawns.push_back(Pawn(_color, pawnState::inHand));
        }
    }

    /**
     * Getter for name.
     * @return Name of player.
     */
    int getName() const {
        return _name;
    }

    Color getColor() const {
        return _color;
    }

    /**
     * Getter for pawns.
     * @return Pawns of player.
     */
    std::list<Pawn> getPawns() const {
        return pawns;
    }
};


#endif //ATLIR5_BONNE_NUIT_PLAYER_H

//
// Created by greg on 17.09.21.
//

#ifndef ATLIR5_BONNE_NUIT_PLAYER_HPP
#define ATLIR5_BONNE_NUIT_PLAYER_HPP


#include <vector>
#include <string>
#include <map>
#include <list>
#include "Pawn.hpp"

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
     * @param color Color of player
     */
    Player(int name, Color color){
      _name= name;
      _color = color;
        for (auto i = 0; i < 3; i++) {
            pawns.emplace_back(Pawn(_color, pawnState::inHand));
        }
    }

    /**
     * Getter for name.
     * @return Name of player.
     */
    [[nodiscard]] int getName() const {
        return _name;
    }

    /**
     * Getter for player color
     * @return Color of the player.
     */
    Color getColor() const {
        return _color;
    }

    [[nodiscard]] std::list<Pawn> &getPawns() {
        return pawns;
    }
    /**
     * Removes one pawn form the player.
     */
    void removePawn(){

    }

    /**
     * Checks if the player still has any pawns.
     * @return True if player still has pawns.
     */
    bool hasPawns(){
        return pawns.empty();
    }

    /**
     * Checks if startWindow player has it'startWindow
     * @return
     */
};


#endif //ATLIR5_BONNE_NUIT_PLAYER_HPP

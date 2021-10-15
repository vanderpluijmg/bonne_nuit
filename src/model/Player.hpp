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
    Player() = default;

    /**
     * Constructor for player
     * @param name Name of player
     * @param color Color of player
     */
    Player(int name, Color color) {
        _name = name;
        _color = color;
        for (auto i = 0; i < 3; i++) {
            pawns.emplace_back(Pawn(_color, pawnState::INHAND));
        }
    }
    void setPlayer(Player& player){
        _color = player.getColor();
        _name = player.getName();
        pawns = player.getPawns();
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
    [[nodiscard]] Color getColor() const {
        return _color;
    }

    /**
     * Getter for the pawn of a player.
     * @return A list of pawn for the player.
     */
    [[nodiscard]] std::list<Pawn> &getPawns() {
        return pawns;
    }
    /**
     * Checks if the player still has any pawns.
     * @return True if player still has pawns.
     */
    bool hasPawns() {
        return pawns.empty();
    }
};


#endif //ATLIR5_BONNE_NUIT_PLAYER_HPP

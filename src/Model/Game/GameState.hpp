//
// Created by gregory on 9/28/21.
//

#ifndef ATLIR5_BONNE_NUIT_GAMESTATE_HPP
#define ATLIR5_BONNE_NUIT_GAMESTATE_HPP

/**
 * All different possible game states.
 */
enum GameState {
    notStarted, //Game has not yet been started.
    lightOn, //Once game is initialized light turns on.
    lightOff, //Once every player has dealt its pawn light turns off.
    finished //Winner of the current game has been declared.
};

#endif //ATLIR5_BONNE_NUIT_GAMESTATE_HPP

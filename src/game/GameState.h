#ifndef BONNE_NUIT_GAMESTATE_H
#define BONNE_NUIT_GAMESTATE_H

/**
 * All different possible game states.
 */
enum GameState {
    notStarted, //Game has not yet been started.
    lightOn, //Once game is initialized light turns on.
    lightOff, //Once every player has dealt its pawn light turns off.
    finished //Winner of the current game has been declared.
};

#endif //BONNE_NUIT_GAMESTATE_H

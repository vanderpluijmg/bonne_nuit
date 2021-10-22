#ifndef BONNE_NUIT_GAMESTATE_H
#define BONNE_NUIT_GAMESTATE_H

/**
 * All different possible game states.
 */
enum GameState {
    NOTSTARTED, //Game has not yet been started.
    LIGHTON, //Once game is initialized light turns on.
    LIGHTOFF, //Once every player has dealt its pawn light turns off.
};

#endif //BONNE_NUIT_GAMESTATE_H

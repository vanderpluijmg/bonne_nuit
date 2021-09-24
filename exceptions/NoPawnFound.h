//
// Created by greg on 24.09.21.
//

#ifndef ATLIR5_BONNE_NUIT_NOPAWNFOUND_H
#define ATLIR5_BONNE_NUIT_NOPAWNFOUND_H


#include <exception>

/**
 * Exception used when the number of players given is not suitable to play a game.
 */
class NoPawnFoundException : public std::logic_error {
public:
    explicit NoPawnFoundException(std::string mess) : std::logic_error(mess){};
};

#endif //ATLIR5_BONNE_NUIT_NOPAWNFOUND_H

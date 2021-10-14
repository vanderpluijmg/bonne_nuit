#ifndef ATLIR5_BONNE_NUIT_NUMBEROFPLAYERSEXCEPTION_H
#define ATLIR5_BONNE_NUIT_NUMBEROFPLAYERSEXCEPTION_H

#include <exception>

/**
 * Exception used when the number of players given is not suitable to play startWindow game.
 */
class NumberOfPlayersException : public std::logic_error {
public:
    explicit NumberOfPlayersException(std::string mess) : std::logic_error(mess){};
};

#endif //ATLIR5_BONNE_NUIT_NUMBEROFPLAYERSEXCEPTION_H

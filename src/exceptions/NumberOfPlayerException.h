#ifndef BONNE_NUIT_NUMBEROFPLAYEREXCEPTION_H
#define BONNE_NUIT_NUMBEROFPLAYEREXCEPTION_H
#include <exception>

/**
 * Exception used when the number of players given is not suitable to play startWindow game.
 */
class NumberOfPlayerException : public std::logic_error {
public:
    explicit NumberOfPlayerException(std::string mess) : std::logic_error(mess){};
};




#endif //BONNE_NUIT_NUMBEROFPLAYEREXCEPTION_H

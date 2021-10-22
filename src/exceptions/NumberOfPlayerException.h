#ifndef BONNE_NUIT_NUMBEROFPLAYEREXCEPTION_H
#define BONNE_NUIT_NUMBEROFPLAYEREXCEPTION_H
#include <exception>

/**
 * Exception used when the number of players given is not suitable to play startWindow game.
 */
class NumberOfPlayerException : public std::logic_error {
public:

    /**
     * Constructor for exception.
     * @param mess Message to display in exception.
     */
    explicit NumberOfPlayerException(const std::string& mess) : std::logic_error(mess){};
};




#endif //BONNE_NUIT_NUMBEROFPLAYEREXCEPTION_H

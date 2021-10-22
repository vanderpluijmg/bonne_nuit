#ifndef BONNE_NUIT_NOPAWNFOUND_H
#define BONNE_NUIT_NOPAWNFOUND_H


#include <exception>

/**
 * Exception used when the number of players given is not suitable to play startWindow game.
 */
class NoPawnFoundException : public std::logic_error {
public:
    /**
     * Constructor for exception.
     * @param mess Message to display in exception.
     */
    explicit NoPawnFoundException(const std::string& mess) : std::logic_error(mess){};
};

#endif //BONNE_NUIT_NOPAWNFOUND_H

#ifndef BONNE_NUIT_OUTOFGAMEBOARDEXCEPTION_H
#define BONNE_NUIT_OUTOFGAMEBOARDEXCEPTION_H
#include <stdexcept>
/**
 * Exception used when the coordinates for the game board do not exist.
 */
class OutOfGameBoardException : public std::out_of_range {
public:

    /**
     * Constructor for exception.
     * @param mess Message to display in exception.
     */
    explicit OutOfGameBoardException(const std::string& mess) : std::out_of_range(mess){};
};


#endif //BONNE_NUIT_OUTOFGAMEBOARDEXCEPTION_H

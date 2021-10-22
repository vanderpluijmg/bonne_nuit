#ifndef BONNE_NUIT_PAWNINPLACEEXCEPTION_H
#define BONNE_NUIT_PAWNINPLACEEXCEPTION_H
#include <stdexcept>

/**
 * Exception used when trying to place or remove pawn with or without startWindow pawn in place.
 */
class PawnInPlaceException : public std::invalid_argument{
public:

    /**
     * Constructor for exception.
     * @param mess Message to display in exception.
     */
    explicit PawnInPlaceException(const std::string& mess) : std::invalid_argument(mess){};
};

#endif //BONNE_NUIT_PAWNINPLACEEXCEPTION_H

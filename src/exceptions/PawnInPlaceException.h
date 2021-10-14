#ifndef ATLIR5_BONNE_NUIT_PAWNINPLACEEXCEPTION_H
#define ATLIR5_BONNE_NUIT_PAWNINPLACEEXCEPTION_H

#include <stdexcept>

/**
 * Exception used when trying to place or remove pawn with or without startWindow pawn in place.
 */
class PawnInPlaceException : public std::invalid_argument{
public:
    explicit PawnInPlaceException(std::string mess) : std::invalid_argument(mess){};
};
#endif //ATLIR5_BONNE_NUIT_PAWNINPLACEEXCEPTION_H

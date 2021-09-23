//
// Created by greg on 23.09.21.
//

#ifndef ATLIR5_BONNE_NUIT_OUTOFGAMEBOARDEXCEPTION_H
#define ATLIR5_BONNE_NUIT_OUTOFGAMEBOARDEXCEPTION_H

#include <stdexcept>
/**
 * Exception used when the coordinates for the game board do not exist.
 */
class OutOfGameBoardException : public std::out_of_range {
public:
    explicit OutOfGameBoardException(std::string mess) : std::out_of_range(mess){};
};

#endif //ATLIR5_BONNE_NUIT_OUTOFGAMEBOARDEXCEPTION_H

#ifndef ATLIR5_BONNE_NUIT_PAWN_HPP
#define ATLIR5_BONNE_NUIT_PAWN_HPP

/**
 * All different possible colors of a pawn.
 */
enum Color {
    GREEN, BLACK, RED, PURPLE, BLUE, NONE
};

/**
 * All different possible pawn states of a pawn.
 */
enum pawnState {
    SHINING, NOTSHINING, INHAND, NOTDEFINED, OPEN, ROSE
};

class Pawn {
private:
    Color _color;
    pawnState _state;
public:
    /**
     * Default constructor for pawn.
     */
    Pawn() = default;

    /**
     * Constructor for pawn.
     * @param color Color of pawn.
     */
    Pawn(Color color, pawnState state) {
        _color = color;
        _state = state;
    };

    /**
     * Getter for marble color.
     * @return Color of marble.
     */
    Color getColor() {
        return _color;
    }

    /**
     * Getter for the state of the pawn.
     * @return State of the pawn.
     */
    [[nodiscard]] pawnState getState() const {
        return _state;
    }

    /**
     * Equality operator for pawn.
     * @param rhs Pawn that is equal to current.
     * @return True if equal.
     */
    bool operator==(const Pawn &rhs) const {
        return _color == rhs._color &&
               _state == rhs._state;
    }

    /**
   * Equality operator for pawn.
   * @param rhs Pawn that is not equal to current.
   * @return True if not equal.
   */
    bool operator!=(const Pawn &rhs) const {
        return !(rhs == *this);
    }

    /**
     * Setter for the state of the pawn
     * @param state State of the pawn to set to.
     */
    void setState(pawnState state) {
        _state = state;
    }

    /**
     * Setter for marble color.
     * @param color Color of marble.
     */
    void setColor(Color color) {
        _color = color;
    }
};

#endif //ATLIR5_BONNE_NUIT_PAWN_HPP

#ifndef ATLIR5_BONNE_NUIT_PAWN_H
#define ATLIR5_BONNE_NUIT_PAWN_H

enum Color {Green, Black, Red, Purple, Blue};
enum pawnState {returned, hidden, inHand};

class Pawn {
private:
    Color _color;
    pawnState _state;
public:
    /**
     * Default constructor for marble.
     */
    Pawn(void){};

    Pawn(const Pawn &p1) {_color = p1._color; _state = p1._state; }
    /**
     * Constructor for marble.
     * @param color Color of marble object.
     */
    Pawn(Color color, pawnState state){
        _color = color;
        _state = state;
    };
    /**
     * Getter for marble color.
     * @return Color of marble.
     */
    Color getColor(){
        return _color;
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
     * Setter for marble color.
     * @param color Color of marble.
     */
    void setColor (Color color){
        _color = color;
    }

};

#endif //ATLIR5_BONNE_NUIT_PAWN_H

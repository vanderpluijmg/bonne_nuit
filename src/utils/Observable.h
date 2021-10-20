//
// Created by gregory on 10/20/21.
//

#ifndef BONNE_NUIT_OBSERVABLE_H
#define BONNE_NUIT_OBSERVABLE_H
#include <list>
#include <string>
#include <optional>
#include "../game/GameState.h"

/**
 * Modification that have happend in the game to pass to the view
 */
struct Modification{
    std::optional<std::string >description;
    std::optional<int> value;
    std::optional<int> x;
    std::optional<int> y;
    std::optional<int> color;
    std::optional<int> winner;
};
class Observer;

class Observable {
public:

    /**
     * Adds the observer to the list of observable.
     * @param observer The observer that needs to be added.
     */
    virtual void addObserver(Observer *observer) = 0;
    /**
     * Notifies all the list of observers with the field that needs to be changed.
     */
    virtual void notify (Modification m) = 0;

    /**
     * Default destructor of Observable.
     */
    virtual ~Observable()=default;
};

#endif //BONNE_NUIT_OBSERVABLE_H

//
// Created by gregory on 9/27/21.
//

#ifndef ATLIR5_BONNE_NUIT_OBSERVABLE_H
#define ATLIR5_BONNE_NUIT_OBSERVABLE_H

#include <list>
#include <string>

//#include "Observer.h"
struct Modification{
    std::string a;
    int value;
    int x;
    int y;
    int color;
};
class Observer;

class Observable {
public:
    /**
     * Adds the observer to the list of observable
     * @param observer The observer that needs to be added
     */
    virtual void addObserver(Observer *observer) = 0;
    /**
     * Notifies all the list of observers with the field that needs to be changed
     */
    virtual void notify (Modification m) = 0;

    virtual ~Observable()=default;
};
#endif //ATLIR5_BONNE_NUIT_OBSERVABLE_H

//
// Created by gregory on 9/27/21.
//

#ifndef ATLIR5_BONNE_NUIT_OBSERVABLE_H
#define ATLIR5_BONNE_NUIT_OBSERVABLE_H
#include "Observer.h"

class Observable {
private:
    std::list<Observer *> observers;
public:
    /**
     * Adds the observer to the list of observable
     * @param observer The observer that needs to be added
     */
    virtual void addObserver(Observer *observer) {
        observers.push_back(observer);
    }
    /**
     * Notifies all the list of observers with the field that needs to be changed
     */
    virtual void notify (){
        for (auto &obs : observers)
            obs->update(); //Add arguments
    }
};
#endif //ATLIR5_BONNE_NUIT_OBSERVABLE_H

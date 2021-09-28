//
// Created by gregory on 9/27/21.
//

#ifndef ATLIR5_BONNE_NUIT_OBSERVER_H
#define ATLIR5_BONNE_NUIT_OBSERVER_H

#include "Observable.h"

class Observer {
public :
    /**
     * Updates an observer with the changed field.
     * @param obs Observer that  needs to be updated.
     * @param changedField The field that needs to change
     */
    virtual void update (){};
};
#endif //ATLIR5_BONNE_NUIT_OBSERVER_H

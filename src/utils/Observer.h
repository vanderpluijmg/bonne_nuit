#ifndef ATLIR5_BONNE_NUIT_OBSERVER_H
#define ATLIR5_BONNE_NUIT_OBSERVER_H

#include <string_view>
class Observable;
class Observer {
public :

    /**
     * Updates an observer with the changed field.
     * @param obs Observer that  needs to be updated.
     * @param changed The field that needs to change
     */
    virtual void update (Modification m, const Observable * obs)=0;
};
#endif //ATLIR5_BONNE_NUIT_OBSERVER_H

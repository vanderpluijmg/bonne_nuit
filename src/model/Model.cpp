//
// Created by gregory on 9/28/21.
//

#include "Model.h"

void Model::addObserver(Observer *observer) {
    observers.push_front(observer);
}

void Model::notify() {
    for(auto &obs : observers)
        obs->update("f",this);
}
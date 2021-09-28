//
// Created by gregory on 9/27/21.
//

#include <stdexcept>
#include "Controller.h"

/**
 * Constructor for controller of game
 * @param model Model interface of the game.
 * @param view View of the game.
 */
Controller::Controller(Model *model, View *view) : model_{model}, view_{view} {
    if (model == nullptr || view == nullptr) {
        throw std::invalid_argument("Model cannot be null");
    }
    model_->addObserver(view);
}
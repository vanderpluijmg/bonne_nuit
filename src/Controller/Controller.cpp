//
// Created by gregory on 9/27/21.
//

#include <stdexcept>
#include "Controller.h"

Controller::Controller(Model *model, View *view)
        : model_{model}, view_{view} {
    if (model == nullptr || view == nullptr) {
        throw std::invalid_argument("Model cannot be null");
    }
}
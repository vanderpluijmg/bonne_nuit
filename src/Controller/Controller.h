//
// Created by gregory on 9/27/21.
//

#ifndef ATLIR5_BONNE_NUIT_CONTROLLER_H
#define ATLIR5_BONNE_NUIT_CONTROLLER_H
#include "../View/View.h"
#include "../Model/Model.h"
class Controller {
private:
    Model *model_;
    View *view_;
public:
    Controller(Model *model, View *view);

};


#endif //ATLIR5_BONNE_NUIT_CONTROLLER_H

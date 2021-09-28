//
// Created by gregory on 9/27/21.
//

#ifndef ATLIR5_BONNE_NUIT_CONTROLLER_H
#define ATLIR5_BONNE_NUIT_CONTROLLER_H
#include "../View/View.h"
#include "../Model/Game/Game.h"
class Controller {
private:
    Model *model_;
    View *view_;
public:
    /**
     * Constructor for controller.
     * @param model Model of game.
     * @param view View for player.
     */
    Controller(Model *model, View *view);
};


#endif //ATLIR5_BONNE_NUIT_CONTROLLER_H

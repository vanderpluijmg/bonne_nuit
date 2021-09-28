#include <QApplication>
#include <iostream>
#include <list>
#include <QWidget>
#include <QMainWindow>
#include "Model/Game/Pawn.hpp"
#include "Model/Game/Game.h"
#include "Model/Game/Board.h"
#include "../ressources/random.hpp"
#include "View/View.h"
#include "Controller/Controller.h"
#include "Model/Model.h"
int main(int argc, char *argv[]){
    QApplication a (argc,argv);
    View view;
    Game game;
    Model *model =  &game;
    Controller(model,&view);
    model->notify();
    return a.exec();
}

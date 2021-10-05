#include <QApplication>
#include "model/Game/Game.h"
#include "View/View.h"
#include "model/Model.h"
int main(int argc, char *argv[]){
    QApplication application (argc,argv);
    Game game; // How to initialize a game with less than 5 players.
    Model *model = &game;
    View view(nullptr, model);
    view.show();
    return application.exec();
}

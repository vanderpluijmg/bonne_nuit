#include <QApplication>
#include "Model/Game/Game.h"
#include "View/View.h"
#include "Model/Model.h"
int main(int argc, char *argv[]){
    QApplication application (argc,argv);
    Game game;
    Model *model =  &game;
    View view(nullptr,model);
    view.show();
    return application.exec();
}

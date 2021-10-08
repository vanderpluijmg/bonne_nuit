#include <QApplication>
#include "model/Game/Game.h"
#include "View/View.h"
#include "model/Model.h"
#include "ressources/random.hpp"

int main(int argc, char *argv[]){
    nvs::randomize();
    QApplication application (argc,argv);
    View view(nullptr);
    view.show();
    return application.exec();
}

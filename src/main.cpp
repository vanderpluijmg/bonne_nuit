#include <QApplication>
#include "model/Game.h"
#include "view/View.h"
#include "ressources/random.hpp"

int main(int argc, char *argv[]){
    nvs::randomize();
    QApplication application (argc,argv);
    View view(nullptr);
    view.show();
    return application.exec();
}

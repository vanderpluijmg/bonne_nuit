#include <QApplication>
#include "model/Game/Game.h"
#include "View/View.h"
#include "model/Model.h"
int main(int argc, char *argv[]){
    QApplication application (argc,argv);
    View view(nullptr);
    view.show();
    return application.exec();
}

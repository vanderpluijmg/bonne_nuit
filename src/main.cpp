#include <QApplication>
#include <iostream>
#include <list>
#include <QWidget>
#include "Model/Game/Pawn.hpp"
#include "Model/Game/Game.h"
#include "Model/Game/Board.h"
#include "../ressources/random.hpp"
#include "View/View.h"
#include "Controller/Controller.h"


using namespace std;

   int main(int argc, char *argv[])
{
    QApplication EditorApp(argc, argv);
    Model model{};
    View view {};
    Controller controller{&model, &view};
}

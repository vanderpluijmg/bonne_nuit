//
// Created by gregory on 9/27/21.
//

#include <QMainWindow>
#include "View.h"
#include "windows/startwindow.h"
#include "../Model/Model.h"

View::View(QWidget *parent) : QMainWindow(parent) {
    a = new Ui_MainWindow;
    a->setupUi(this);
}

void View::update(const Observable *obs) {
    auto model = dynamic_cast<const Model *>(obs);
    model->getGameState();
}



/** QWidget c;
 QMainWindow b;
 Ui_MainWindow a;
 a.setupUi(&b);
 b.show();*/

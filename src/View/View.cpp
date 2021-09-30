//
// Created by gregory on 9/27/21.
//

#include <QMainWindow>
#include <iostream>
#include <QSpinBox>
#include "View.h"
#include "windows/test.hpp"
#include "../Model/Model.h"

View::View(QWidget *parent) : QMainWindow(parent) {
    a = new Ui_MainWindow;
    a->setupUi(this);
    //QObject::connect(a->pushButton, SIGNAL(clicked(bool)), this , SLOT(View::onAddWidget()));
    QObject::connect(a->pushButton, &QPushButton::clicked, this , &View::onAddWidget);
}


void View::update(const Observable *obs) {
    auto model = dynamic_cast<const Model *>(obs);
}

void View::onAddWidget() {
    a->pushButton->setText("test");
    a.
}



/** QWidget c;
 QMainWindow b;
 Ui_MainWindow a;
 a.setupUi(&b);
 b.show();*/

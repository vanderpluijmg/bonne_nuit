//
// Created by gregory on 9/27/21.
//

#include <QMainWindow>
#include <iostream>
#include <QSpinBox>
#include <QInputDialog>
#include "View.h"
#include "windows/application.hpp"
#include "windows/playerInfo.hpp"
#include "windows/test.hpp"
#include <QtGlobal>

View::View(QWidget *parent, Model *model) : QWidget(parent) {
    if (model == nullptr)
        throw std::invalid_argument("model can't be null");
    model->addObserver(this);
    auto form  = new Ui_Form ();
    form->setupUi(this);
    QVBoxLayout* a = qobject_cast<QVBoxLayout *>(form->frame->layout());
    QWidget* player = new QWidget();
    QHBoxLayout* verticalLayout = new QHBoxLayout(player);
    verticalLayout->addWidget(new QLabel("How old are you"));
    auto edit = new QLineEdit();
    verticalLayout->addWidget(edit);
    a->insertWidget(0,player);


    //Sets up the application
    //applicationWindow->setupUi(this);
    //Insert game and player widget into stacked widgets.
    //applicationWindow->stackedWidget->insertWidget(1, nbf);
    //applicationWindow->stackedWidget->insertWidget(2, game);
    //Sets up ui for both widgets
    //Connects home buttons to different window of game.
    //QObject::connect(applicationWindow->players, &QPushButton::clicked, this, &View::changeToPlayerWindow);
    //QObject::connect(nbf->startGame, &QPushButton::clicked, this, &View::changeToGameWindow);
}
void View::update(std::string_view ,const Observable *obs) {
    auto model = dynamic_cast<const Model *>(obs);
}

void View::changeToPlayerWindow() {
    applicationWindow->stackedWidget->setCurrentIndex(1);
}

void View::changeToGameWindow() {
    applicationWindow->stackedWidget->setCurrentIndex(2);
}

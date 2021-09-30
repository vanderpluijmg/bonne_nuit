//
// Created by gregory on 9/27/21.
//

#include <QMainWindow>
#include <iostream>
#include <QSpinBox>
#include <QInputDialog>
#include "View.h"
#include "windows/test.hpp"
#include "../Model/Model.h"
#include <QList>

View::View(QWidget *parent, Model *m) : QMainWindow(parent) {
    m->addObserver(this);
    a = new Ui_MainWindow;
    //QObject::connect(a->pushButton, SIGNAL(clicked(bool)), this , SLOT(View::onAddPlayer()));
    QObject::connect(a->plusPlayer, &QPushButton::clicked, this , &View::onAddPlayer);
    QObject::connect(a->minusPlayer, &QPushButton::clicked, this , &View::onRemovePlayer);

}


void View::update(const Observable *obs) {
    auto model = dynamic_cast<const Model *>(obs);
}

QWidget* View::newPlayer() {
    QWidget* player = new QWidget();
    QHBoxLayout* verticalLayout = new QHBoxLayout(player);
    //Name
    QString playerName = tr("Hello Player %1").arg(a->numberOfPlayers->intValue());
    auto name = new QLabel(playerName);
    verticalLayout->addWidget(name);
    //Age
    verticalLayout->addWidget(new QLabel("How old are you"));
    QLineEdit *edit = new QLineEdit(nullptr);
    verticalLayout->addWidget(edit);
    return player;
}


void View::onAddPlayer() {
    a->numberOfPlayers->display(a->numberOfPlayers->intValue() + 1);
    auto layout = qobject_cast<QVBoxLayout *>(a->frame->layout());
    layout->insertWidget(0, newPlayer());
}

void View::onRemovePlayer() {
    a->numberOfPlayers->display(a->numberOfPlayers->intValue() + -1);
    //QList<QWidget *> Widgets = a->frame->layout()->widget()->findChildren<QWidget *>();
    //delete Widgets.first();
}
/**

    QWidget* playerInfo = new QWidget();
    QHBoxLayout* verticalLayout = new QHBoxLayout(playerInfo);
    //name

    //age
    auto question_age = new QLabel();
    question_age->setText("How old are you?");
    verticalLayout->addWidget(question_age);
    //Insert age
    //auto age = new QLineEdit();
    //verticalLayout->addWidget(age);

    ;*/



/** QWidget c;
 QMainWindow b;
 Ui_MainWindow a;
 a.setupUi(&b);
 b.show();*/

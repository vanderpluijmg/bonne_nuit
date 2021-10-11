//
// Created by gregory on 10/9/21.
//

#include <QLabel>
#include <QLineEdit>
#include <iostream>
#include <QIcon>
#include <QPushButton>
#include "newPlayerWidget.h"

newPlayerWidget::newPlayerWidget(int nbr){
    setUp(this,nbr);
}

void newPlayerWidget::setUp(QWidget* parent, int name) {
    std::cout<<name;
    verticalLayoutManager = new QHBoxLayout(parent);
    auto playerNameLabel = tr("Player %1").arg(name);
    qDebug()<<playerNameLabel;
    verticalLayoutManager->addWidget(new QLabel(playerNameLabel));
    verticalLayoutManager->addWidget(new QLabel("How old are you"));
    auto edit = new QLineEdit();
    edit->setMaximumWidth(100);
    verticalLayoutManager->addWidget(edit);
    edit->setStyleSheet("border: 1px solid red");
    auto color = new QPushButton();
    auto verticalSpacer = new QSpacerItem(20, 448, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayoutManager->addSpacerItem(verticalSpacer);
    verticalLayoutManager->addWidget(color);
    QIcon icon1;
    switch (name){
        case 1:icon1.addFile(QString::fromUtf8(":/images/img/star_black.png"), QSize(), QIcon::Normal, QIcon::Off);break;
        case 2:icon1.addFile(QString::fromUtf8(":/images/img/star_green.png"), QSize(), QIcon::Normal, QIcon::Off);break;
        case 3:icon1.addFile(QString::fromUtf8(":/images/img/star_purple.png"), QSize(), QIcon::Normal, QIcon::Off);break;
        case 4:icon1.addFile(QString::fromUtf8(":/images/img/star_blue.png"), QSize(), QIcon::Normal, QIcon::Off);break;
        case 5:icon1.addFile(QString::fromUtf8(":/images/img/star_red.png"), QSize(), QIcon::Normal, QIcon::Off);break;
    }
    color->setIcon(icon1);

}

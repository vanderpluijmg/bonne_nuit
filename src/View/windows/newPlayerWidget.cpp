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
    horizontalLayoutManager = new QHBoxLayout(parent);
    //Name of player
    auto playerNameLabel = tr("Player %1").arg(name);
    auto nameOfPlayer = new QLabel(playerNameLabel);
    horizontalLayoutManager->addWidget(nameOfPlayer);
    // End of name of player
    //Spacer
    auto spacerNameAge = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    //Age of player
    horizontalLayoutManager->addItem(spacerNameAge);
    auto ageQuestion = new QLabel("How old are you?");
    horizontalLayoutManager->addWidget(ageQuestion);
    auto ageResp = new QTextEdit();
    ageResp->setMaximumSize(QSize(100, 33));
    horizontalLayoutManager->addWidget(ageResp);
    //End age of player
    auto colorPlayer = new QLabel("Your color is : ");
    horizontalLayoutManager->addWidget(colorPlayer);
    auto colorPic = new QLabel();
    colorPic->setText(QCoreApplication::translate("Form", "<html><head/><body><p><img src=\":/images/img/star_black.png\"/></p></body></html>", nullptr));
    horizontalLayoutManager->addWidget(colorPic);
    auto spaceColorEnd = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    //Spacer
    horizontalLayoutManager->addItem(spaceColorEnd);
}

//
// Created by gregory on 10/9/21.
//

#include <QLabel>
#include <QLineEdit>
#include <iostream>
#include <QIcon>
#include <QPushButton>
#include "newPlayerWidget.h"

newPlayerWidget::newPlayerWidget(int nbr) {
    setUp(this, nbr);
}

void newPlayerWidget::setUp(QWidget *parent, int name) {
    horizontalLayoutManager = new QHBoxLayout(parent);
    auto playerNameLabel = tr("Player %1").arg(name);
    auto nameOfPlayer = new QLabel(playerNameLabel);
    horizontalLayoutManager->addWidget(nameOfPlayer);
    auto spacerNameAge = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    horizontalLayoutManager->addItem(spacerNameAge);
    auto ageQuestion = new QLabel("How old are you?");
    horizontalLayoutManager->addWidget(ageQuestion);
    ageResp = new QLineEdit();
    ageResp->setMaximumSize(QSize(100, 33));
    horizontalLayoutManager->addWidget(ageResp);
    auto colorPlayer = new QLabel("Your color is : ");
    horizontalLayoutManager->addWidget(colorPlayer);
    auto colorPic = new QLabel();
    switch (name) {
        case 1 :
            colorPic->setText(QCoreApplication::translate("Form",
                                                          "<html><head/><body><p><img src=\":/images/img/star_green.png\"/></p></body></html>",
                                                          nullptr));
            break;
        case 2 :
            colorPic->setText(QCoreApplication::translate("Form",
                                                          "<html><head/><body><p><img src=\":/images/img/star_black.png\"/></p></body></html>",
                                                          nullptr));
            break;
        case 3 :
            colorPic->setText(QCoreApplication::translate("Form",
                                                          "<html><head/><body><p><img src=\":/images/img/star_red.png\"/></p></body></html>",
                                                          nullptr));
            break;
        case 4 :
            colorPic->setText(QCoreApplication::translate("Form",
                                                          "<html><head/><body><p><img src=\":/images/img/star_blue.png\"/></p></body></html>",
                                                          nullptr));
            break;
        case 5 :
            colorPic->setText(QCoreApplication::translate("Form",
                                                        "<html><head/><body><p><img src=\":/images/img/star_purple.png\"/></p></body></html>",
                                                        nullptr));
            break;
    }
    horizontalLayoutManager->addWidget(colorPic);
    auto spaceColorEnd = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    horizontalLayoutManager->addItem(spaceColorEnd);
}

int newPlayerWidget::getAge() {
    return ageResp->text().toInt();
}

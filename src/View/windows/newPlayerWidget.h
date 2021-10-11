//
// Created by gregory on 10/9/21.
//

#ifndef ATLIR5_BONNE_NUIT_NEWPLAYERWIDGET_H
#define ATLIR5_BONNE_NUIT_NEWPLAYERWIDGET_H


#include <QWidget>
#include <QHBoxLayout>

class newPlayerWidget : public QWidget{
private:
    int playerName;
    QHBoxLayout* verticalLayoutManager;
public:
    newPlayerWidget(int nbr);
    void setUp(QWidget* parent, int number);
};


#endif //ATLIR5_BONNE_NUIT_NEWPLAYERWIDGET_H

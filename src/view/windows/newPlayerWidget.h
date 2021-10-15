//
// Created by gregory on 10/9/21.
//

#ifndef ATLIR5_BONNE_NUIT_NEWPLAYERWIDGET_H
#define ATLIR5_BONNE_NUIT_NEWPLAYERWIDGET_H


#include <QWidget>
#include <QHBoxLayout>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

class newPlayerWidget : public QWidget{
private:
    QHBoxLayout* horizontalLayoutManager;
    int ageResp;
    int name_;
public:

    newPlayerWidget(int nbr);
    void setUp(QWidget* parent, int number);

    int getAgeResp() const;

    int getName() const;
};


#endif //ATLIR5_BONNE_NUIT_NEWPLAYERWIDGET_H

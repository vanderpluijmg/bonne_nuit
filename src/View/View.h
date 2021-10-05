//
// Created by gregory on 9/27/21.
//

#ifndef ATLIR5_BONNE_NUIT_VIEW_H
#define ATLIR5_BONNE_NUIT_VIEW_H
#include <QWidget>
#include <QLayout>
#include <QStackedWidget>
#include <QMainWindow>
#include "../Utils/Observable.h"
#include "../Utils/Observer.h"
#include "../model/Model.h"
#include "windows/gameWindow.hpp"
#include "windows/application.hpp"
#include "windows/playerInfo.hpp"
#include "windows/test.hpp"


class View : public QWidget, public Observer {
private:

    Model *model_;
    Ui_Form* form  = new Ui_Form ();

public:

    void onAddPlayer();
    void onRemovePlayer();

    /**
     * Default constructor for view of game.
     * @param parent
     */
    explicit View(QWidget * parent = nullptr, Model * m = nullptr);

    /**
     * Default destructor
     */
    ~View() override =default;

    void changeToGameWindow();

    void update(std::string_view, const Observable *obs) override;

    QWidget *newPlayer();

};

#endif //ATLIR5_BONNE_NUIT_VIEW_H

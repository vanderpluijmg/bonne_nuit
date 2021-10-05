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


class View : public QWidget, public Observer {
private:

    /**
    * Connects start window with necessary buttons
    *
    void initStartWindow();

    gameWindow *gameWidget;
    QStackedWidget* stackedWidget;
    startWindow *startWidget;

*/
    NumberOfPlayers*  nbf = new NumberOfPlayers();
    Application* applicationWindow = new Application;
    gameWindow* game = new gameWindow();

public:
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

    void changeToPlayerWindow();

    void update(std::string_view, const Observable *obs) override;
/**
    void onAddPlayer();

    void onRemovePlayer();

   QWidget* newPlayer();

   void changeToGameWindow();
*/
};

#endif //ATLIR5_BONNE_NUIT_VIEW_H

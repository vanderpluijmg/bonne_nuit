//
// Created by gregory on 9/27/21.
//

#ifndef ATLIR5_BONNE_NUIT_VIEW_H
#define ATLIR5_BONNE_NUIT_VIEW_H
#include <QWidget>
#include <QLayout>

#include "../Utils/Observable.h"

#include "../Utils/Observer.h"
#include "windows/test.hpp"

class View : public QMainWindow, public Observer {
private:
    Ui_MainWindow *a;
public:
    /**
     * Default constructor for view of game.
     * @param parent
     */
    View(QWidget * parent = nullptr);
    /**
     * Default destructor
     */
    ~View()=default;

    void update(const Observable *obs) override;

    void onAddWidget();
};

#endif //ATLIR5_BONNE_NUIT_VIEW_H

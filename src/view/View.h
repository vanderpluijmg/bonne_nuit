
#ifndef BONNE_NUIT_VIEW_H
#define BONNE_NUIT_VIEW_H


#include <QWidget>
#include <QLayout>
#include <QStackedWidget>
#include <QMainWindow>
#include "../utils/Observable.h"
#include "../utils/Observer.h"
#include "windows/mainWindow.h"
#include "../game/Game.h"


class View : public QWidget, public Observer {
Q_OBJECT
private:
    int firstPlayer=0;
    int smallestAge=100;
    int currentRosePlace_ = 0;
    std::optional<Game> game;
    Ui_Form* mainWindow  = new Ui_Form ();
public:

    /**
     * Default constructor for view of game.
     * @param parent Parent of main Window;
     */
    explicit View(QWidget * parent = nullptr);

    /**
     * Default destructor
     */
    ~View() override =default;

    /**
     * Changes to game window when start button is pressed in GUI.
     */
    void changeToGameWindow();

    /**
     * Updates the view when the model has changed.
     * @param m Modification that have been made in the model.
     * @param obs Model that has been changed.
     */
    void update(Modification m, const Observable *obs) override;

    /**
     * Plays description turn for the current player
     */
    void rollDiceMoveRose();
    /**
     * Moves the ROSE in the view.
     */
    void updateRoseView();

    /**
     * When add players button in GUI is clicked.
     */
    void onAddPlayer();

    /**
     * When remove player button in GUI is clicked.
     */
    void onRemovePlayer();

    /**
     * Places description pawn in the GUI.
     * @param x X coordinates of the pawn.
     * @param y Y coordinates of the pawn.
     * @param c Color of the pawn.
     */
    void placePawn(int x, int y, int c);

    /**
     * Removes or adds description start to the GUI depending of the state of the game.
     */
    void onAddStarOrRemove();

    /**
     * Updates the state of the game in the GUI.
     * @param gs
     */
    void updateGameState();

    /**
     * Changes game from day ton night.
     */
    void goIntoNight();

    /**
     * Updates the current player in the GUI.
     */
    void updateCurrentPlayer();

    /**
     * Applies the current picture of the correct star to the icon.
     * @param c Color of star.
     */
    static void getStarPicture(int c, QIcon&);

    /**
     * Sets the instruction label with a specific message.
     * @param msg Message to display.
     */
    void setMessageGuiding(const QString& msg);

    /**
     * Affect all the stars on the board with the desired action.
     * @param connectStars Connects all the stars to a specific action.
     * @param disableNotOnRose Disable all button that are not on same axis as rose.
     * @param activateAll Activates or deactivates all buttons.
     * @param rosePlace place of rose.
     * @param activate Either to activate or disable all buttons.
     */
    void affectAllStars(bool connectStars, bool disableNotOnRose, bool activateAll, int rosePlace=0, bool disactivate=false);

    void affectAllRoses(bool);

    /**
     * Display the winner of the current game
     */
    static void displayWinner(int winner);
};



#endif //BONNE_NUIT_VIEW_H

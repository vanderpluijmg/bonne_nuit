#ifndef BONNE_NUIT_WINNERWIDGET_H
#define BONNE_NUIT_WINNERWIDGET_H


#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

class winnerWidget : public QWidget {
public:
    QLabel *congratulations;
    QLabel* name;
    QLabel* label;
    QPushButton *color;
    QLabel *win;
    QPushButton *quit;

    /**
     * Constructor for winner widget.
     * @param winnerN Name of winner.
     */
    explicit winnerWidget(int winnerN);

    /**
     * Sets up winner widget.
     * @param winner Parent to setup to.
     * @param winnerN Name of winner.
     */
    void setUp(QWidget *winner, int winnerN);

    /**
     * Translates ui to text.
     * @param winner Parent widget.
     */
    void retranslateUi(QWidget *winner) const;

    /**
     * Quits the game back to the desktop.
     */
    static void quitGame();

};


#endif //BONNE_NUIT_WINNERWIDGET_H
#ifndef BONNE_NUIT_NEWPLAYERWIDGET_H
#define BONNE_NUIT_NEWPLAYERWIDGET_H


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

    /**
     * Constructor for a new player widget.
     * @param nbr Name of player to create widget for.
     */
    explicit newPlayerWidget(int nbr);

    /**
     * Sets up the player widget.
     * @param parent Parent of the player widget.
     * @param number Name of the player.
     */
    void setUp(QWidget* parent, int number);

    /**
     * Gets age of player.
     * @return Age of player.
     */
    [[nodiscard]] int getAgeResp() const;

    /**
     * Gets name of player.
     * @return Name of player.
     */
    [[nodiscard]] int getName() const;
};



#endif //BONNE_NUIT_NEWPLAYERWIDGET_H

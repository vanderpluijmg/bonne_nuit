#ifndef TEST_H
#define TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>


class Ui_Form {
public:
    QStackedWidget *stackedWidget;
    QWidget *gameIntro;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *numberOfPlayerLayout;
    QLabel *label;
    QLCDNumber *numberOfPlayers;
    QPushButton *addPlayer;
    QPushButton *removePlayer;
    QFrame *centralFrame;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QWidget *verticalLayoutWidget;
    QHBoxLayout *startGameLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *startGame;
    QSpacerItem *horizontalSpacer;
    QWidget *page_2;
    QWidget *cases;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *caseRose8;
    QPushButton *pushButton_7;
    QWidget *verticalLayoutWidget_9;
    QVBoxLayout *caseRose3;
    QPushButton *pushButton_4;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *caseRose0;
    QPushButton *pushButton;
    QWidget *verticalLayoutWidget_11;
    QVBoxLayout *caseRose4;
    QPushButton *pushButton_5;
    QWidget *verticalLayoutWidget_8;
    QVBoxLayout *caseRose2;
    QPushButton *pushButton_3;
    QWidget *verticalLayoutWidget_12;
    QVBoxLayout *caseRose5;
    QPushButton *pushButton_10;
    QWidget *verticalLayoutWidget_10;
    QVBoxLayout *caseRose7;
    QPushButton *pushButton_9;
    QWidget *verticalLayoutWidget_13;
    QVBoxLayout *caseRose6;
    QPushButton *pushButton_6;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *caseRose1;
    QPushButton *pushButton_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *caseStar0;
    QPushButton *star00;
    QPushButton *star01;
    QPushButton *star02;
    QPushButton *star03;
    QPushButton *star04;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *caseStar8;
    QPushButton *star80;
    QPushButton *star81;
    QPushButton *star82;
    QPushButton *star83;
    QPushButton *star84;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *caseStar7;
    QPushButton *star70;
    QPushButton *star71;
    QPushButton *star72;
    QPushButton *star73;
    QPushButton *star74;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *caseStar6;
    QPushButton *star60;
    QPushButton *star61;
    QPushButton *star62;
    QPushButton *star63;
    QPushButton *star64;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *caseStar5;
    QPushButton *star50;
    QPushButton *star51;
    QPushButton *star52;
    QPushButton *star53;
    QPushButton *star54;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *caseStar2;
    QPushButton *star20;
    QPushButton *star21;
    QPushButton *star22;
    QPushButton *star23;
    QPushButton *star24;
    QWidget *horizontalLayoutWidget_8;
    QHBoxLayout *caseStar4;
    QPushButton *star40;
    QPushButton *star41;
    QPushButton *star42;
    QPushButton *star43;
    QPushButton *star44;
    QWidget *horizontalLayoutWidget_9;
    QHBoxLayout *caseStar3;
    QPushButton *star30;
    QPushButton *star31;
    QPushButton *star32;
    QPushButton *star33;
    QPushButton *star34;
    QWidget *horizontalLayoutWidget_10;
    QHBoxLayout *caseStar1;
    QPushButton *star10;
    QPushButton *star11;
    QPushButton *star12;
    QPushButton *star13;
    QPushButton *star14;
    QWidget *verticalLayoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *rollDice;
    QLCDNumber *rollDiceValue;
    QLabel *currentPlayer;

    void setupUi(QWidget *Form);

    void retranslateUi(QWidget *Form) const;
};



#endif // TEST_H

//
// Created by gregory on 9/28/21.
//

#ifndef ATLIR5_BONNE_NUIT_MODEL_H
#define ATLIR5_BONNE_NUIT_MODEL_H

#include "../Utils/Observable.h"
#include "Game/Player.hpp"
#include "Game/GameState.hpp"
#include "../Utils/Observer.h"


class Model : public Observable{
private:
    std::list<Observer *> observers;
public:
    [[nodiscard]] virtual GameState getGameState() const =0;
    virtual void playTurnLightOn(int) =0;
    virtual void playTurnLightOff(int,int)=0;
    virtual void turnLightOff()=0;
    virtual void turnLightOn()=0;
    virtual int getRosePlace()=0;
    virtual bool isDone()=0;
    virtual int rollDice()=0;
    virtual void moveRose(int value)=0;
    virtual bool isFinished()=0;
    [[nodiscard]] virtual const Player getCurrentPlayer() const=0;
    void addObserver(Observer *observer) override;
    void notify(Modification m) override;

};


#endif //ATLIR5_BONNE_NUIT_MODEL_H

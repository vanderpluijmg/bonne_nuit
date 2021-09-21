//
// Created by root on 18.09.21.
//

#include "GoodNight.h"
#include "Game.h"

void GoodNight::startGame(){
        Game game(5);
        game.turnLightOn();
        while (game.getGameState() == lightOn){
            game.playTurnLightOn();
            if(game.isDone())
                game.turnLightOff();
        }
        while (game.getGameState() == lightOff){
            game.playTurnLightOff();
        }

};
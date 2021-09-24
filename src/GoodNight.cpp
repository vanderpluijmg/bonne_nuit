//
// Created by root on 18.09.21.
//

#include "GoodNight.h"
#include "Game.h"
#include "../exceptions/PawnInPlaceException.h"

void GoodNight::startGame(int numberOfPlayers){
        Game game(numberOfPlayers);
        game.turnLightOn();
        while (game.getGameState() == lightOn){
            try {
                game.playTurnLightOn(1);
            }
            catch (PawnInPlaceException& e){
                std::cout<<e.what()<<std::endl;
                //Get new y coordinates from user
            }
            if(game.isDone())
                game.turnLightOff();
        }
        while (game.getGameState() == lightOff){
            game.playTurnLightOff(1,1);
            if(game.isDone())
                game.setGameState(finished);
        }
        game.getWinner();
};
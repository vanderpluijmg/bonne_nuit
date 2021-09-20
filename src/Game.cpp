//
// Created by greg on 17.09.21.
//

#include "Game.h"
#include "../ressources/random.hpp"
#include "Board.h"


Game::Game(int numberOfPlayers) {
    gameState = notStarted;
    board.initGameBoard();
    addPawnsToPlace(numberOfPlayers);
    currentPlayer = players[0];

}

std::list<Player> Game::populateGame(int numberOfPlayers) {
    unsigned int i;
    for (i = 0; i < numberOfPlayers; i++) {
        players.emplace_back(Player(i + 1, Color(i)));
    }
    std::list<Player> pawnToPlace;
    for (; i < 5; i++)
        pawnToPlace.emplace_back(Player(0, Color(i)));
    return pawnToPlace;
}

void Game::setGameState(GameState gameState) {
    Game::gameState = gameState;
}

GameState Game::getGameState() const {
    return gameState;
}

std::list<Pawn> Game::getPlayerHand(int player) {
    return players.at(player).getPawns();
}

std::vector<Player> Game::getPlayers() {
    return players;
}

const Player &Game::getCurrentPlayer() const {
    return currentPlayer;
}

void Game::nextPlayer() {
    currentPlayer.getName() < players.size() ?
            currentPlayer = players.at(currentPlayer.getName()) : currentPlayer = players.at(0);
}

void Game::moveRose() {
    board.moveRose(nvs::random_value(1,3));
}

void Game::addPawnsToPlace( int numberOfPlayers) {
    std::list<Color>pawnsToPlace_color;
    std::list<Player> player = populateGame(numberOfPlayers);
    for (auto &x: player)
       pawnsToPlace_color.emplace_back(x.getColor());
    board.placePawnsBeg(pawnsToPlace_color);
}

bool Game::placePawn(int x, int y) {
    if ((x < 8 && x > 0) && (y < 5 && y > 0) && (board.getCase(x,y).getColor()==Color::None)) {
        board.placePawn(x, y, currentPlayer.getColor());
        return true;
    } return false;
}

Board &Game::getBoard() {
    return board;
}

void Game::playTurn() {
    moveRose();
    playMove(currentPlayer);
    nextPlayer();
}
bool Game::isDone(){
    return players.end()->getPawns().empty();
}
void Game::playMove(Player player){
    //Get coordinates from user.
    int x = board.getRosePlace();
    int y = 4;
    //Give them to placePawn()
    while (!placePawn(x,y)) {
        //re-ask for valid y coordinates
        y += 1;
    }
}

void Game::turnLightOff() {
    setGameState(lightOff);
}
void Game::turnLightOn() {
    setGameState(lightOn);
}





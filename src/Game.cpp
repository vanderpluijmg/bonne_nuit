//
// Created by greg on 17.09.21.
//

#include "Game.h"
#include "../ressources/random.hpp"
#include "Board.h"
#include "../exceptions/NumberOfPlayersException.h"

Game::Game(int numberOfPlayers) {
    if (numberOfPlayers <= 0 || numberOfPlayers > 5)
        throw NumberOfPlayersException(
                "The number of players should be between 1-5, you provided " + std::to_string(numberOfPlayers));
    gameState = notStarted;
    board.initGameBoard();
    addPawnsToPlace(numberOfPlayers);
    currentPlayer = players[0];
}

void Game::populateGame(int numberOfPlayers) {
    unsigned int i;
    for (i = 0; i < numberOfPlayers; i++) {
        players.emplace_back(Player(i + 1, Color(i)));
    }
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
    board.moveRose(nvs::random_value(1, 3));
}

void Game::addPawnsToPlace(int numberOfPlayers) {
    populateGame(numberOfPlayers);
    for (auto &x: players)
        board.placePawnsBeg(x.getColor());
}

bool Game::placePawn(int x, int y) {
    return getBoard().placePawn(x,y,currentPlayer.getColor());
}

Board &Game::getBoard() {
    return board;
}

void Game::playTurnLightOn(int y) {
    moveRose();
    playMove(currentPlayer, y);
    nextPlayer();
}

bool Game::isDone() {
    return players.end()->getPawns().empty();
}

void Game::playMove(Player player, int y) {
    //Get coordinates from user.
    //Give them to placePawn()
    while (!placePawn(board.getRosePlace(), y)) {
        y += 1;
    }
    board.getCase(board.getRosePlace(), y).setState(shining);
}

void Game::turnLightOff() {
    setGameState(lightOff);
}

void Game::turnLightOn() {
    setGameState(lightOn);
}

void Game::playTurnLightOff(int x, int y) {
    returnPawn(x, y);
}

bool Game::returnPawn(int x, int y) {
    if ((x < 8 && x >= 0))
        if (y < 5 && y > 0)
            if (board.getCase(x, y).getColor() != Color::None) {
                board.removePawn(x, y);
                return true;
            }
    return false;
}





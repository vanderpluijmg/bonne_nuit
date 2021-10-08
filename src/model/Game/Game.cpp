//
// Created by greg on 17.09.21.
//

#include "Game.h"
#include "Board.h"
#include "../../ressources/random.hpp"
#include "../../exceptions/NumberOfPlayersException.h"
#include "../../exceptions/OutOfGameBoardException.h"

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
    for (int i = 0; i < numberOfPlayers; i++) {
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

const Player Game::getCurrentPlayer() const {
    return currentPlayer;
}

void Game::nextPlayer() {
    currentPlayer.getName() < players.size() ?
            currentPlayer = players.at(currentPlayer.getName()) : currentPlayer = players.at(0);
}

void Game::moveRose(int value) {
    board.moveRose(value);
    Modification m;
    m.a = "rose move";
    m.value = board.getRosePlace();
    notify(m);
}

int Game::rollDice(){
    return nvs::random_value(1, 3);
}

void Game::addPawnsToPlace(int numberOfPlayers) {
    std::vector<Player> npc;
    populateGame(numberOfPlayers);
    for (int i=players.size(); i<5; i++)
        npc.emplace_back(Player(i,Color(i)));
    npc_=npc;
    for (auto &x: npc)
        board.placePawnsBeg(x.getColor());
}

const std::vector<Player> &Game::getNpc() const {
    return npc_;
}

bool Game::placePawn(int x, int y) {
    return getBoard().placePawn(x,y,currentPlayer.getColor());
}

Board &Game::getBoard() {
    return board;
}

void Game::playTurnLightOn(int y) {
    playMove(currentPlayer, y);
    nextPlayer();
}

bool Game::isDone() {
    return players.back().hasPawns();
    }

void Game::playMove(Player player, int y) {
    placePawn(board.getRosePlace(), y);
    player.removePawn();
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
        if (y < 5 && y > 0) {
            board.removePawn(x, y);
            return true;
        }
    throw OutOfGameBoardException("Sorry the coordinates are not in the game board");
}

void Game::autofill(){
    int nbNpc= 5-players.size();
    for (; nbNpc<=5;nbNpc++)
        board.placePawnsBeg(Color(nbNpc));
    for (auto& x : players)
            while (!x.getPawns().empty())
                x.removePawn();
}

bool Game::isFinished(){
    return true;// players.back().full();
}

Player Game::getWinner() {
    return currentPlayer;
}

int Game::getRosePlace() {
    return board.getRosePlace();
}

void Game::addObserver(Observer *observer) {
    observers.push_front(observer);
}

void Game::notify(Modification m) {
    for(auto &obs : observers)
        obs->update(m,this);
}






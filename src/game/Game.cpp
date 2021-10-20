#include "Game.h"
#include "Board.h"
#include "../ressources/random.hpp"
#include "../exceptions/NumberOfPlayerException.h"
#include "../exceptions/OutOfGameBoardException.h"
#include "../utils/Observer.h"

Game::Game() {
    gameState_ = notStarted;
    board.initGameBoard();
    returnedPawns=0;
}

void Game::initGame(int numberOfPlayers, int firstPlayer) {
    if (numberOfPlayers <= 0 || numberOfPlayers > 5)
        throw NumberOfPlayerException (
                "The number of players should be between 1-5, you provided " + std::to_string(numberOfPlayers));
    addPawnsToPlace(numberOfPlayers);
    firstPlayer--;
    currentPlayer.setPlayer(players[firstPlayer]);
    Modification m;
    m.description = "currentPlayer";
    notify(m);
};

void Game::populateGame(int numberOfPlayers) {
    for (int i = 0; i < numberOfPlayers; i++)
        players.emplace_back(Player(i + 1, Color(i)));
}

void Game::setGameState(GameState gameState) {
    gameState_ = gameState;
}

GameState Game::getGameState() const {
    return gameState_;
}

std::vector<Player> Game::getPlayers() {
    return players;
}

Player Game::getCurrentPlayer() {
    return currentPlayer;
}

void Game::nextPlayer() {
    currentPlayer.getName() < players.size() ?
            currentPlayer = players.at(currentPlayer.getName()) : currentPlayer = players.at(0);
    Modification m;
    m.description = "currentPlayer";
    notify(m);
}

void Game::moveRose(int value) {
    board.moveRose(value);
    Modification m;
    m.description = "ROSE move";
    m.value = board.getRosePlace();
    notify(m);
}

int Game::rollDice() {
    nvs::randomize();
    return nvs::random_value(1, 3);
}

void Game::addPawnsToPlace(int numberOfPlayers) {
    std::vector<Player> npc;
    populateGame(numberOfPlayers);
    for (auto i = players.size(); i < 5; i++)
        npc.emplace_back(Player(i, Color(i)));
    npc_ = npc;
    for (auto &x: npc)
        board.placePawnsNpcPlayers(x.getColor());
    notifyStartingNpcPawn();
}

void Game::notifyStartingNpcPawn() {
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 6; y++) {
            Modification m;
            if (getBoard().getCase(x, y).getColor() != NONE){
                m.description = "pawnsBeginning";
                m.x = x;
                m.y = y;
                m.color = getBoard().getCase(x, y).getColor();
                notify(m);}
        }
    }
}

const std::vector<Player> &Game::getNpc() const {
    return npc_;
}

bool Game::placePawn(int x, int y) {
    return getBoard().placePawn(x, y, currentPlayer.getColor());
}

Board &Game::getBoard() {
    return board;
}

void Game::dayDone() {
    if (players.back().hasPawns()) {
        turnLightOff();
        Modification m;
        m.description = "turnLightOff";
        notify(m);
    }
}

void Game::playMove(int y) {
    placePawn(board.getRosePlace(), y);
    removePawnCurrentPlayer();
}

void Game::turnLightOff() {
    setGameState(lightOff);
}

void Game::turnLightOn() {
    setGameState(lightOn);
}

void Game::returnPawn(int x, int y) {
    ((x <= 8 && x >= 0) && (y <= 5 && y >= 0)) ? board.removePawn(x, y) :
    throw OutOfGameBoardException("Sorry the coordinates are not in the game board");
    returnedPawns++;
    nextPlayer();
}

void Game::isFinished() {
    if (returnedPawns==14){
        Modification m;
        m.description = "winner";
        m.winner = determineWinner();
        notify(m);
    }
}

int Game::getRosePlace() {
    return board.getRosePlace();
}

void Game::addObserver(Observer *observer) {
    observers.push_front(observer);
}

void Game::notify(Modification m) {
    for (auto &obs: observers) {
        obs->update(m, this);
    }
}

void Game::removePawnCurrentPlayer() {
    players[currentPlayer.getName() - 1].getPawns().pop_back();
}

int Game::determineWinner() {
    for (int x = 0; x < 9; x++)
        for (int y = 0; y < 6; y++)
            if(getBoard().getCase(x,y).getState()==SHINING)
                return getBoard().getCase(x,y).getColor();
    return 0;
}






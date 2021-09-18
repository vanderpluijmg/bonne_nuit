//
// Created by greg on 17.09.21.
//

#include "Game.h"

std::list<Player> Game::populateGame(int numberOfPlayers) {
    unsigned int i;
    for (i = 0; i < numberOfPlayers; i++) {
        players.emplace_back(Player(i + 1, Color(i)));
    }
    std::list<Player> pawnToPlace;
    for (; i < 5; i++)r|
        pawnToPlace.emplace_back(Player(0, Color(i)));
    return pawnToPlace;
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

int Game::rollDice() {
    return 1 + (rand() % 6);
}

void Game::addListener(Listener *lis) {
    listeners.emplace_back(lis);
}

void Game::notify(Turn t) {
    for (Listener *lis: listeners)
        lis->onEvent(t);
}

void Game::moveRose(Turn t) {
    t.diceRoll = 2;//rollDice();
    notify(t);
}

void Game::addPawnsToPlace(Turn t) {
    std::list<Player> player = populateGame(5);
    for (auto &x: player)
        t.pawnsToPlace_color.emplace_back(x.getColor());
    notify(t);
}



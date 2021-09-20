//
// Created by greg on 17.09.21.
//
#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../src/Game.h"


std::list<Pawn> blackHand (){
    std::list<Pawn> pawns;
    for (auto i = 0; i<5; i++)
        pawns.push_back(Pawn(Black,inHand));
    return pawns;
}

TEST_CASE( "Populating hands of players with 5 players", "[hand]" ) {
    Game game(5);
    std::list<Color> colorInUse;
    REQUIRE(game.getPlayers().size() == 5);
    REQUIRE(game.getGameState() == GameState::notStarted);
    for (auto x : game.getPlayers()){
        REQUIRE (x.getPawns().size() == 3);
        colorInUse.emplace_back(x.getColor());
        for (auto y : x.getPawns())
            REQUIRE (y.getColor() == x.getColor());
    }
    colorInUse.unique();
    REQUIRE(colorInUse.size() == 5);
}
TEST_CASE( "Populating hands of players with 4 players", "[hand]" ) {
    std::list<Color> colorInUse;
    Game game(4);
    REQUIRE(game.getPlayers().size() == 4);
    for (auto x : game.getPlayers()) {
        REQUIRE (x.getPawns().size() == 3);
        colorInUse.emplace_back(x.getColor());
    }
    colorInUse.unique();
    REQUIRE(colorInUse.size() == 4);
}
TEST_CASE( "Populating hands of players with 3 players", "[hand]" ) {
    std::list<Color> colorInUse;
    Game game(3);
    REQUIRE(game.getPlayers().size() == 3);
    for (auto x : game.getPlayers()) {
        REQUIRE (x.getPawns().size() == 3);
        colorInUse.emplace_back(x.getColor());
    }
    colorInUse.unique();
    REQUIRE(colorInUse.size() == 3);
}
TEST_CASE( "Populating hands of players with 2 players", "[hand]" ) {
    std::list<Color> colorInUse;
    Game game(2);
    REQUIRE(game.getPlayers().size() == 2);
    for (auto x : game.getPlayers()) {
        REQUIRE (x.getPawns().size() == 3);
        colorInUse.emplace_back(x.getColor());
    }
    colorInUse.unique();
    REQUIRE(colorInUse.size() == 2);
}
TEST_CASE( "Populating hands of players with 1 players", "[hand]" ) {
    std::list<Color> colorInUse;
    Game game(1);
    REQUIRE(game.getPlayers().size() == 1);
    for (auto x : game.getPlayers()) {
        REQUIRE (x.getPawns().size() == 3);
        colorInUse.emplace_back(x.getColor());
    }
    colorInUse.unique();
    REQUIRE(colorInUse.size() == 1);
}

TEST_CASE("Correctly placed rose", "[rose]"){
}

TEST_CASE("next player"){
    Game game(4);
    game.nextPlayer();
    REQUIRE(game.getPlayers()[1].getColor() == game.getCurrentPlayer().getColor());
    game.nextPlayer();
    REQUIRE(game.getPlayers()[2].getColor() == game.getCurrentPlayer().getColor());
    game.nextPlayer();
    REQUIRE(game.getPlayers()[3].getColor() == game.getCurrentPlayer().getColor());
    game.nextPlayer();
    REQUIRE(game.getPlayers()[0].getColor() == game.getCurrentPlayer().getColor());
}

TEST_CASE("populating table"){
    Game g(3);
    int index=0;
    for (int x =0; x<9;x++) {
        for (int y = 0; y <= 5; y++) {
            if (g.getBoard().getCase(x, y).getColor() != None) {
                index++;
            }
        }
    }
    REQUIRE(index==6);
}

TEST_CASE("place pawn without pawn", "[placePawn]"){
    Game g (4);
    REQUIRE(g.placePawn(4,4));
}

TEST_CASE("place pawn with pawn in place", "[placePawn]"){
    Game g (4);
    g.placePawn(4,4);
    REQUIRE_FALSE(g.placePawn(4,4));
}

TEST_CASE("place pawn out of bounds y", "[placePawn]"){
    Game g (4);
    REQUIRE_FALSE(g.placePawn(4,7));
}

TEST_CASE("place pawn out of bounds x", "[placePawn]"){
    Game g (4);
    REQUIRE_FALSE(g.placePawn(10,4));
}

TEST_CASE("place pawn out of bounds X and Y", "[placePawn]"){
    Game g (4);
    REQUIRE_FALSE(g.placePawn(10,7));
}

TEST_CASE("move rose", "[rose]"){
    Game g(5);
    g.moveRose();
    int index= 0;
    for (int y = 0; y<5; y++) {
        for (int x = 0; x < 9; x++) {
            if (g.getBoard().getCase(x, 0).getColor() == None && g.getBoard().getCase(x, 0).getState() == rose)
                index++;
        }
        REQUIRE(index == 1);
        index=0;
    }
}

TEST_CASE("play move", "[game mechanics]"){
    Game g(5);
    Player playingPlayer = g.getCurrentPlayer();
    g.playTurn();
    REQUIRE((g.getBoard().getCase(g.getBoard().getRosePlace(), 4).getColor()) == (playingPlayer.getColor()));
    REQUIRE((g.getBoard().getCase(g.getBoard().getRosePlace(), 4).getState())
    == (playingPlayer.getPawns().begin()->getState()));
    REQUIRE(g.getPlayers().at(1).getName() == g.getCurrentPlayer().getName());
}



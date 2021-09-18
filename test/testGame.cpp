//
// Created by greg on 17.09.21.
//
#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../Game.h"


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



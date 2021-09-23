//
// Created by greg on 17.09.21.
//

#include "../catch2/catch.hpp"
#include "../src/Game.h"
#include "../exceptions/NumberOfPlayersException.h"
#include "../exceptions/OutOfGameBoardException.h"
#include "../exceptions/PawnInPlaceException.h"


std::list<Pawn> blackPlayerHand (){
    std::list<Pawn> pawns;
    for (auto i = 0; i<5; i++)
        pawns.push_back(Pawn(Black,inHand));
    return pawns;
}

TEST_CASE( "Populating hands of players with 5 players", "[hand]" ) {
    Game game;
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

TEST_CASE("Populating hand 0 players", "[hand]"){

}
TEST_CASE("Populating hand 6 players", "[hand]"){
    REQUIRE_THROWS_AS(Game(0), NumberOfPlayersException);
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

TEST_CASE("Correctly number of rose", "[rose]"){
    Game game;
    auto index = 0;
    game.moveRose();
    for (int x = 0; x<  9; x++) {
        if (game.getBoard().getCase(x, 0).getState() == rose)
            index++;
    }
    REQUIRE(index==1);
}

TEST_CASE("Correctly placed number of rose", "[rose]") {
    Game g;
    int place = g.getBoard().getRosePlace();
    g.moveRose();
    REQUIRE_FALSE(place==g.getBoard().getRosePlace());
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
    REQUIRE(index==9);
}

TEST_CASE("place pawn without pawn", "[placePawn]"){
    Game g (5);
    REQUIRE(g.placePawn(4,4));
}

TEST_CASE("place pawn with pawn in place", "[placePawn]"){
    Game g (4);
    g.placePawn(4,4);
    //REQUIRE_FALSE(g.placePawn(4,4));
    REQUIRE_THROWS_AS(g.placePawn(4,4), PawnInPlaceException);

}

TEST_CASE("place pawn out of bounds y", "[placePawn]"){
    Game g (4);
    //REQUIRE_FALSE(g.placePawn(4,7));
    REQUIRE_THROWS_AS(g.placePawn(4,7), OutOfGameBoardException);
}

TEST_CASE("place pawn out of bounds x", "[placePawn]"){
    Game g (4);
    //REQUIRE_FALSE(g.placePawn(10,4));
    REQUIRE_THROWS_AS(g.placePawn(10,4), OutOfGameBoardException);
}

TEST_CASE("place pawn out of bounds X and Y", "[placePawn]"){
    Game g (4);
    //REQUIRE_FALSE(g.placePawn(10,7));
    REQUIRE_THROWS_AS(g.placePawn(10,7), OutOfGameBoardException);

}

TEST_CASE("move rose", "[rose]"){
    Game g;
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

TEST_CASE("play moves lights on", "[game mechanics]"){
    Game g;
    Player playingPlayer = g.getCurrentPlayer();
    g.playTurnLightOn(4);
    REQUIRE((g.getBoard().getCase(g.getBoard().getRosePlace(), 4).getColor()) == (playingPlayer.getColor()));
    REQUIRE((g.getBoard().getCase(g.getBoard().getRosePlace(), 4).getState())
            == (shining));
    REQUIRE(g.getPlayers().at(1).getName() == g.getCurrentPlayer().getName());
}

TEST_CASE("remove current player pawn","[remove pawn]") {
    Game g(4);
    g.placePawn(g.getBoard().getRosePlace(), 4);
    g.returnPawn(g.getBoard().getRosePlace(),4);
    REQUIRE(g.getBoard().getCase(g.getBoard().getRosePlace(),4).getState() == notShining);
}

TEST_CASE("autofill"){
    Game g(1);
    g.setGameState(lightOff);
}


/**
TEST_CASE("fully populating", "[play whole game]"){
    Game game(3);
    game.turnLightOn();
    while (game.getGameState() == lightOn){
        game.playTurnLightOn();
        if(game.isDone())
            game.turnLightOff();
    }
    for (auto &x: game.getPlayers())
        REQUIRE(x.getPawns().empty());
    REQUIRE(game.getGameState() == lightOff);
}*/

//Create autofill




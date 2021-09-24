//
// Created by greg on 17.09.21.
//

#include "../catch2/catch.hpp"
#include "../src/Game.h"
#include "../exceptions/NumberOfPlayersException.h"
#include "../exceptions/OutOfGameBoardException.h"
#include "../exceptions/PawnInPlaceException.h"
#include "../exceptions/NoPawnFound.h"


std::list<Pawn> blackPlayerHand (){
    std::list<Pawn> pawns;
    for (auto i = 0; i<5; i++)
        pawns.push_back(Pawn(Black,inHand));
    return pawns;
}

TEST_CASE( "Populating hands of players with 5 players", "[hand]" "[sunUp]") {
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
TEST_CASE( "Populating hands of players with 4 players", "[hand]" "[sunUp]") {
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
TEST_CASE( "Populating hands of players with 3 players", "[hand]" "[sunUp]") {
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
TEST_CASE( "Populating hands of players with 2 players", "[hand]" "[sunUp]") {
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

TEST_CASE("Populating hand 0 players", "[hand]" "[sunUp]"){

}
TEST_CASE("Populating hand 6 players", "[hand]" "[sunUp]"){
    REQUIRE_THROWS_AS(Game(0), NumberOfPlayersException);
}



TEST_CASE( "Populating hands of players with 1 players", "[hand]" "[sunUp]" ) {
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

TEST_CASE("Correctly number of rose", "[rose]" "[sunUp]"){
    Game game;
    auto index = 0;
    game.moveRose();
    for (int x = 0; x<  9; x++) {
        if (game.getBoard().getCase(x, 0).getState() == rose)
            index++;
    }
    REQUIRE(index==1);
}

TEST_CASE("Correctly placed number of rose", "[rose]" "[sunUp]") {
    Game g;
    int place = g.getBoard().getRosePlace();
    g.moveRose();
    REQUIRE_FALSE(place==g.getBoard().getRosePlace());
}

TEST_CASE("next player" "[sunUp]" "[sunDown]"){
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

TEST_CASE("populating table" "[sunUp]"){
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

TEST_CASE("place pawn without pawn", "[placePawn]" "[sunUp]"){
    Game g;
    REQUIRE(g.placePawn(g.getBoard().getRosePlace(),4));
}

TEST_CASE("place pawn with pawn in place", "[placePawn]" "[sunUp]"){
    Game g;
    g.playMove(g.getCurrentPlayer(), 4);
    REQUIRE_THROWS_AS(  g.playMove(g.getCurrentPlayer(), 4)
    ,PawnInPlaceException);
}

TEST_CASE("place pawn out of bounds y", "[placePawn]" "[sunUp]"){
    Game g (4);
    //REQUIRE_FALSE(g.placePawn(4,7));
    REQUIRE_THROWS_AS(g.placePawn(4,7), OutOfGameBoardException);
}

TEST_CASE("place pawn out of bounds x", "[placePawn]" "[sunUp]"){
    Game g (4);
    //REQUIRE_FALSE(g.placePawn(10,4));
    REQUIRE_THROWS_AS(g.placePawn(10,4), OutOfGameBoardException);
}

TEST_CASE("place pawn out of bounds X and Y", "[placePawn]" "[sunUp]"){
    Game g (4);
    //REQUIRE_FALSE(g.placePawn(10,7));
    REQUIRE_THROWS_AS(g.placePawn(10,7), OutOfGameBoardException);

}

TEST_CASE("move rose", "[rose]" "[sunUp]"){
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

TEST_CASE("play moves lights on", "[game mechanics]" "[sunUp]"){
    Game g;
    Player playingPlayer = g.getCurrentPlayer();
    g.playTurnLightOn(4);
    REQUIRE((g.getBoard().getCase(g.getBoard().getRosePlace(), 4).getColor()) == (playingPlayer.getColor()));
    REQUIRE((g.getBoard().getCase(g.getBoard().getRosePlace(), 4).getState())
            == (shining));
    REQUIRE(g.getPlayers().at(1).getName() == g.getCurrentPlayer().getName());
}

TEST_CASE("remove current player pawn","[remove pawn]" "[sunDown]") {
    Game g;
    g.placePawn(g.getBoard().getRosePlace(), 4);
    g.returnPawn(g.getBoard().getRosePlace(),4);
    REQUIRE(g.getBoard().getCase(g.getBoard().getRosePlace(),4).getState() == notShining);
}
TEST_CASE("remove current pawn with no pawn","[remove pawn]" "[sunDown]") {
    Game g;
    REQUIRE_THROWS_AS(g.returnPawn(g.getBoard().getRosePlace(),4), NoPawnFoundException);
}
TEST_CASE("remove current pawn out of bounds","[remove pawn]" "[sunDown]") {
    Game g;
    REQUIRE_THROWS_AS(g.returnPawn(g.getBoard().getRosePlace(),8), OutOfGameBoardException);
}

TEST_CASE("autofill", "[sunDown]") {
    Game g(1);
    int index = 0;
    g.autofill();
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x <= 5; x++) {
            if (g.getBoard().getCase(y, x).getColor() != Color::None)
                index++;
        }
    }
    REQUIRE (index == 15);
}

TEST_CASE("isDone", "[sunUp]"){
    Game g(1);
    g.autofill();
    REQUIRE(g.isDone());
}

TEST_CASE("isFinished", "[sunDown]"){
    Game g(1);
    g.autofill();

}

//Create autofill*/




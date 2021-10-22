/**#include "../src/game/Game.h"
#include "../src/exceptions/NumberOfPlayerException.h"
#include "../src/exceptions/OutOfGameBoardException.h"
#include "../src/exceptions/PawnInPlaceException.h"
#include "../src/exceptions/NoPawnFound.h"
#include "catch2/catch.hpp"

TEST_CASE( "Populating hands of players with 5 players", "[hand]" "[sunUp]") {
    Game game;
    game.initGame(5,1);
    std::list<Color> colorInUse;
    REQUIRE(game.getPlayers().size() == 5);
    REQUIRE(game.getGameState() == GameState::NOTSTARTED);
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
    Game game;
    game.initGame(4,1);
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
    Game game;
    game.initGame(3,1);
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
    Game game;
    game.initGame(2,1);
    REQUIRE(game.getPlayers().size() == 2);
    for (auto x : game.getPlayers()) {
        REQUIRE (x.getPawns().size() == 3);
        colorInUse.emplace_back(x.getColor());
    }
    colorInUse.unique();
    REQUIRE(colorInUse.size() == 2);
}

TEST_CASE("Populating hand 6 players", "[hand]" "[sunUp]"){
    Game game;
    REQUIRE_THROWS_AS(game.initGame(6,1), NumberOfPlayerException);
}

TEST_CASE( "Populating hands of players with 1 players", "[hand]" "[sunUp]" ) {
    std::list<Color> colorInUse;
    Game game;
    game.initGame(1,1);
    REQUIRE(game.getPlayers().size() == 1);
    for (auto x : game.getPlayers()) {
        REQUIRE (x.getPawns().size() == 3);
        colorInUse.emplace_back(x.getColor());
    }
    colorInUse.unique();
    REQUIRE(colorInUse.size() == 1);
}

TEST_CASE("Correctly number of ROSE", "[ROSE]" "[sunUp]"){
    Game game;
    auto index = 0;
    game.moveRose(game.rollDice());
    for (int x = 0; x<  9; x++) {
        if (game.getBoard().getCase(x, 0).getState() == ROSE)
            index++;
    }
    REQUIRE(index==1);
}

TEST_CASE("Correctly placed number of ROSE", "[ROSE]" "[sunUp]") {
    Game g;
    int place = g.getBoard().getRosePlace();
    g.moveRose(g.rollDice());
    REQUIRE_FALSE(place==g.getBoard().getRosePlace());
}

TEST_CASE("next player" ,"[sunUp]" "[sunDown]"){
    Game game;
    game.initGame(4,1);
    game.nextPlayer();
    REQUIRE(game.getPlayers()[1].getColor() == game.getCurrentPlayer().getColor());
    game.nextPlayer();
    REQUIRE(game.getPlayers()[2].getColor() == game.getCurrentPlayer().getColor());
    game.nextPlayer();
    REQUIRE(game.getPlayers()[3].getColor() == game.getCurrentPlayer().getColor());
    game.nextPlayer();
    REQUIRE(game.getPlayers()[0].getColor() == game.getCurrentPlayer().getColor());
}

TEST_CASE("populating table", "[sunUp]"){
    Game game;
    game.initGame(3,1);
    int index=0;
    for (int x =0; x<9;x++) {
        for (int y = 0; y <= 5; y++) {
            if (game.getBoard().getCase(x, y).getColor() != NONE) {
                index++;
            }
        }
    }
    REQUIRE(index==6);
}

TEST_CASE("place pawn without pawn", "[placePawn]" "[sunUp]"){
    Game g;
    g.initGame(5,1);
    REQUIRE(g.placePawn(g.getBoard().getRosePlace(),4));
}

TEST_CASE("place pawn with pawn in place", "[placePawn]" "[sunUp]"){
    Game g;
    g.initGame(5,1);
    g.playMove(4);
    REQUIRE_THROWS_AS(  g.playMove(4)
    ,PawnInPlaceException);
}

TEST_CASE("place pawn out of bounds y", "[placePawn]" "[sunUp]"){
    Game game;
    game.initGame(3,1);
    REQUIRE_THROWS_AS(game.placePawn(4,7), OutOfGameBoardException);
}

TEST_CASE("place pawn out of bounds x", "[placePawn]" "[sunUp]"){
    Game g;
    g.initGame(4,1);
//REQUIRE_FALSE(g.placePawn(10,4));
    REQUIRE_THROWS_AS(g.placePawn(10,4), OutOfGameBoardException);
}

TEST_CASE("place pawn out of bounds X and Y", "[placePawn]" "[sunUp]"){
    Game game;
    game.initGame(1,1);
//REQUIRE_FALSE(g.placePawn(10,7));
    REQUIRE_THROWS_AS(game.placePawn(10,7), OutOfGameBoardException);

}

TEST_CASE("move ROSE", "[ROSE]" "[sunUp]"){
    Game g;
    g.moveRose(g.rollDice());
    int index= 0;
    for (int y = 0; y<5; y++) {
        for (int x = 0; x < 9; x++) {
            if (g.getBoard().getCase(x, 0).getColor() == NONE && g.getBoard().getCase(x, 0).getState() == ROSE)
                index++;
        }
        REQUIRE(index == 1);
        index=0;
    }
}

TEST_CASE("play moves lights on", "[game mechanics]" "[sunUp]"){
    Game g;
    g.initGame(5,1);
    Player playingPlayer = g.getCurrentPlayer();
    g.playMove(4);
    REQUIRE((g.getBoard().getCase(g.getBoard().getRosePlace(), 4).getColor()) == (playingPlayer.getColor()));
    REQUIRE((g.getBoard().getCase(g.getBoard().getRosePlace(), 4).getState())
            == (SHINING));
    REQUIRE(g.getPlayers().at(1).getName() == g.getCurrentPlayer().getName());
}

TEST_CASE("remove current player pawn","[remove pawn]" "[sunDown]") {
    Game g;
    g.initGame(5,1);
    g.placePawn(g.getBoard().getRosePlace(), 4);
    g.returnPawn(g.getBoard().getRosePlace(),4);
    REQUIRE(g.getBoard().getCase(g.getBoard().getRosePlace(),4).getState() == NOTSHINING);
}
TEST_CASE("remove current pawn with no pawn","[remove pawn]" "[sunDown]") {
    Game g;
    REQUIRE_THROWS_AS(g.returnPawn(g.getBoard().getRosePlace(),4), NoPawnFoundException);
}
TEST_CASE("remove current pawn out of bounds","[remove pawn]" "[sunDown]") {
    Game g;
    REQUIRE_THROWS_AS(g.returnPawn(g.getBoard().getRosePlace(),8), OutOfGameBoardException);
}*/

cmake_minimum_required(VERSION 3.19)
project(atlir5_Bonne_nuit)

add_executable(atlir5_Bonne_nuit src/main.cpp src/Pawn.hpp src/Player.hpp src/Game.cpp src/Game.h src/Board.cpp src/Board.h src/GoodNight.cpp src/GoodNight.h exceptions/NumberOfPlayersException.h exceptions/OutOfGameBoardException.h exceptions/PawnInPlaceException.h exceptions/NoPawnFound.h)

add_executable(atlir5_Bonne_nuit-Tests test/mainTest.cpp src/Pawn.hpp src/Player.hpp src/Game.cpp src/Game.h src/Board.cpp test/testGame.cpp)
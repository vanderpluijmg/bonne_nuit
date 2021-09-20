cmake_minimum_required(VERSION 3.20)
project(atlir5_Bonne_nuit)

set(CMAKE_CXX_STANDARD 17)

add_executable(atlir5_Bonne_nuit src/main.cpp src/Pawn.hpp src/Player.hpp src/Game.cpp src/Game.h src/Board.cpp src/Board.h src/GoodNight.cpp src/GoodNight.h)

add_executable(atlir5_Bonne_nuit-Tests src/Pawn.hpp src/Player.hpp src/Game.cpp src/Game.h src/Board.cpp test/testGame.cpp)

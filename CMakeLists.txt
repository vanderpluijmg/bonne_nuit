cmake_minimum_required(VERSION 3.20)
project(atlir5_Bonne_nuit)

set(CMAKE_CXX_STANDARD 17)

add_executable(atlir5_Bonne_nuit main.cpp Pawn.h Player.cpp Player.h Game.cpp Game.h Board.cpp Board.h GoodNight.cpp GoodNight.h)

add_executable(atlir5_Bonne_nuit-Tests Pawn.h Player.cpp Player.h Game.cpp Game.h test/testGame.cpp)

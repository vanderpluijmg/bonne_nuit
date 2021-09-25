cmake_minimum_required(VERSION 3.19)
project(atlir5_Bonne_nuit)

set(CMAKE_CXX_STANDARD 17)

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Widgets SvgWidgets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Widgets Qt6::SvgWidgets)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_executable(atlir5_Bonne_nuit src/main.cpp src/Pawn.hpp src/Player.hpp src/Game.cpp src/Game.h src/Board.cpp src/Board.h src/GoodNight.cpp src/GoodNight.h exceptions/NumberOfPlayersException.h exceptions/OutOfGameBoardException.h exceptions/PawnInPlaceException.h exceptions/NoPawnFound.h)

add_executable(atlir5_Bonne_nuit-Tests test/mainTest.cpp src/Pawn.hpp src/Player.hpp src/Game.cpp src/Game.h src/Board.cpp test/testGame.cpp)
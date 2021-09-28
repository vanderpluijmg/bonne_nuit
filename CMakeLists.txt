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
SET ( UIS
        StartWindow.ui)
qt_wrap_ui(StartWindow.ui)
add_executable(atlir5_Bonne_nuit src/main.cpp src/Model/Game/Pawn.hpp src/Model/Game/Player.hpp src/Model/Game/Game.cpp src/Model/Game/Game.h src/Model/Game/Board.cpp src/Model/Game/Board.h src/Model/Game/GoodNight.cpp src/Model/Game/GoodNight.h src/exceptions/NumberOfPlayersException.h src/exceptions/OutOfGameBoardException.h src/exceptions/PawnInPlaceException.h src/exceptions/NoPawnFound.h src/View/View.cpp src/View/View.h src/Controller/Controller.cpp src/Controller/Controller.h src/Utils/Observable.h src/Utils/Observer.h src/View/windows/startwindow.h src/Model/Game/GameState.hpp src/Model/Model.h src/Model/Model.cpp)

add_executable(atlir5_Bonne_nuit-Tests test/mainTest.cpp src/Model/Game/Pawn.hpp src/Model/Game/Player.hpp src/Model/Game/Game.cpp src/Model/Game/Game.h src/Model/Game/Board.cpp test/testGame.cpp)

target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
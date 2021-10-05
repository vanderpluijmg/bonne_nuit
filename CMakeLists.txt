cmake_minimum_required(VERSION 3.19)
project(atlir5_Bonne_nuit)

set(CMAKE_CXX_STANDARD 17)

# https://digitalkarabela.com/mingw-w64-how-to-fix-file-too-big-too-many-sections/
#set(CMAKE_CXX_FLAGS -Wa,-mbig-obj)    # rnvs

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Widgets SvgWidgets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Widgets Qt6::SvgWidgets)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_executable(atlir5_Bonne_nuit src/main.cpp src/model/Game/Pawn.hpp src/model/Game/Player.hpp src/model/Game/Game.cpp src/model/Game/Game.h src/model/Game/Board.cpp src/model/Game/Board.h src/model/Game/GoodNight.cpp src/model/Game/GoodNight.h src/exceptions/NumberOfPlayersException.h src/exceptions/OutOfGameBoardException.h src/exceptions/PawnInPlaceException.h src/exceptions/NoPawnFound.h src/View/View.cpp src/View/View.h src/Utils/Observable.h src/Utils/Observer.h src/model/Game/GameState.hpp src/model/Model.h src/model/Model.cpp)

add_executable(atlir5_Bonne_nuit-Tests test/mainTest.cpp src/model/Game/Pawn.hpp src/model/Game/Player.hpp src/model/Game/Game.cpp src/model/Game/Game.h src/model/Game/Board.cpp test/testGame.cpp src/Utils/Observable.h src/Utils/Observer.h src/Utils/Observable.h src/Utils/Observable.h src/model/Model.cpp src/model/Model.h)

target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
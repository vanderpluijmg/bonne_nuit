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

add_executable(atlir5_Bonne_nuit src/main.cpp src/model/Pawn.hpp src/model/Player.hpp src/model/Game.cpp src/model/Game.h src/model/Board.cpp src/model/Board.h src/exceptions/NumberOfPlayersException.h src/exceptions/OutOfGameBoardException.h src/exceptions/PawnInPlaceException.h src/exceptions/NoPawnFound.h src/view/View.cpp src/view/View.h src/utils/Observable.h src/utils/Observer.h src/model/GameState.hpp src/ressources/images.qrc src/view/windows/newPlayerWidget.cpp src/view/windows/newPlayerWidget.h src/view/windows/mainWindow.cpp)

add_executable(atlir5_Bonne_nuit-Tests test/mainTest.cpp src/model/Pawn.hpp src/model/Player.hpp src/model/Game.cpp src/model/Game.h src/model/Board.cpp test/testGame.cpp src/utils/Observable.h src/utils/Observer.h src/utils/Observable.h src/utils/Observable.h)

target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
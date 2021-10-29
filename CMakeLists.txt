cmake_minimum_required(VERSION 3.20)
project(bonne_nuit)

set(CMAKE_CXX_STANDARD 17)

# https://digitalkarabela.com/mingw-w64-how-to-fix-file-too-big-too-many-sections/
#set(CMAKE_CXX_FLAGS -Wa,-mbig-obj)    # rnvs


# QT6 #
set(QT_VERSION 6)
set(REQUIRED_LIBS Core Widgets SvgWidgets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Widgets Qt6::SvgWidgets)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Catch2 QUIET)
if (NOT Catch2_FOUND)
    message("Catch not found, downloading from git.")
    Include(FetchContent)
    FetchContent_Declare(
            Catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
            GIT_TAG v2.13.6)
    FetchContent_MakeAvailable(Catch2)
endif ()

include(CTest)

# Main executable #
add_executable(bonne_nuit src/main.cpp src/game/Board.cpp src/game/Board.h src/game/Pawn.h src/game/Player.h src/game/GameState.h src/game/Game.cpp src/game/Game.h src/exceptions/NoPawnFound.h src/exceptions/NumberOfPlayerException.h src/exceptions/OutOfGameBoardException.h src/exceptions/PawnInPlaceException.h src/ressources/random.hpp src/utils/Observable.h src/utils/Observer.h src/view/View.cpp src/view/View.h src/view/windows/mainWindow.cpp src/view/windows/mainWindow.h src/view/windows/newPlayerWidget.cpp src/view/windows/newPlayerWidget.h src/ressources/images.qrc src/view/windows/winnerWidget.cpp src/view/windows/winnerWidget.h)
add_executable(atlir5_Bonne_nuit-Tests test/mainTest.cpp src/game/Pawn.h src/game/Player.h src/game/Game.cpp src/game/Game.h src/game src/game/Board.cpp test/testGame.cpp src/utils/Observable.h src/utils/Observer.h src/utils/Observable.h src/utils/Observable.h)
# Test executable #
#set_property(SOURCE src/main.cpp PROPERTY COMPILE_DEFINITIONS "CATCH_CONFIG_RUNNER")
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})

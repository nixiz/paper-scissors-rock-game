# CMakeList.txt : CMake project for MemControllerService, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("RockPaperScissorsGame")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(header_files 
    "game/GameData.h" 
    "game/RPSGame.h" 
    "game/Selections.h" 
    "console/GameConsole.h" 
    "console/language_support.h"
    "utils/keyboard_helper.hpp"
    "utils/CommandLineParser.h"
    "states/GameState.h"
    "states/GameEnterState.h"
    "states/GameInitializationState.h"
    "states/SelectDifficultyState.h"
    "states/GamePlayingState.h"
    "states/GameOverState.h"
    "states/GameStateMachine.h")
set(source_files 
    "game/RPSGame.cpp" 
    "console/GameConsole.cpp" 
    "utils/CommandLineParser.cpp"
    "states/GameState.cpp"
    "states/GameEnterState.cpp"
    "states/GameInitializationState.cpp"
    "states/SelectDifficultyState.cpp"
    "states/GamePlayingState.cpp"
    "states/GameOverState.cpp"
    "states/GameStateMachine.cpp"
    "main.cpp")
# Add source to this project's executable.
add_executable (${PROJECT_NAME} ${source_files} ${header_files})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})

# target_link_libraries(${PROJECT_NAME} pthread)

# TODO: Add tests and install targets if needed.

cmake_minimum_required(VERSION 3.14)
project(battleship_CPU)

set(CMAKE_CXX_STANDARD 17)

add_executable(battleship_CPU main.cpp attacklogic.h attackphase.h
        checkOutputs.h formatcoordinates.h game_setup.h handshakephase.h
        IncludeHeaders.h inputtovals.h parseOutput.h parseScope.h placefleet.h
        sendCommands.h storeresult.h validateattack.h)
cmake_minimum_required(VERSION 3.12)
project(Chess)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_CXX_STANDARD 17)

add_executable(Chess main.cpp Figures/Bishop.cpp Figures/Bishop.h Figures/Castle.cpp Figures/Castle.h Figures/Figure.cpp Figures/Figure.h Figures/King.cpp Figures/King.h Figures/Knight.cpp Figures/Knight.h Figures/Pawn.cpp Figures/Pawn.h Figures/Queen.cpp Figures/Queen.h Coordinates.cpp Coordinates.h Desk.cpp Desk.h Move.cpp Move.h Game/Game.cpp Game/Game.h Game/PVP_GAME.cpp Game/PVP_GAME.h LogsWriter/FiguresPossibleMovesWriter.cpp LogsWriter/FiguresPossibleMovesWriter.h LogsWriter/GameLogsWriter.cpp LogsWriter/GameLogsWriter.h)
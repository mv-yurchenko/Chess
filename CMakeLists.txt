cmake_minimum_required(VERSION 3.12)
project(Chess)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_CXX_STANDARD 17)

add_executable(Chess main.cpp Figures/Figure.cpp Figures/Figure.h Coordinates.cpp Coordinates.h Move.cpp Move.h Figures/King.cpp Figures/King.h Figures/Pawn.cpp Figures/Pawn.h Figures/Knight.cpp Figures/Knight.h Figures/Castle.cpp Figures/Castle.h)
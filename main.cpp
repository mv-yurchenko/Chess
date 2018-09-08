//
// Created by Max Yurchenko on 24.08.2018.
//

#include <iostream>
#include "Game/PVP_GAME.h"
#include "LogsWriter/FiguresPossibleMovesWriter.h"
#include "Graphics/ChessGraphic.h"

using namespace std;


int main (){

    PVP_GAME pvp_game;
    FiguresPossibleMovesWriter possibleMovesWriter;

    pvp_game.initialize_game();

    Desk *desk = pvp_game.getCurrent_desk();

    possibleMovesWriter.write_all_figures_possible_moves(desk);

//    pvp_game.pvp_game();
};
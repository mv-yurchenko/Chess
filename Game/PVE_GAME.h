//
// Created by Max Yurchenko on 19.09.2018.
//

#ifndef CHESS_PVE_GAME_H
#define CHESS_PVE_GAME_H


#include "Game.h"
#include "../Graphics/ChessGraphic.h"
#include "../LogsWriter/FiguresPossibleMovesWriter.h"
#include "../Engine/Engine.h"

class PVE_GAME : public Game{

    bool is_player_turn;
    bool player_side;
    bool engine_side;
    GameLogsWriter gameLogsWriter;
    ChessGraphic chessGraphic;
    FiguresPossibleMovesWriter figuresPossibleMovesWriter;
public:
    PVE_GAME();

    void write_desk();

    void pve_game();

    void human_turn(bool is_white_turn);

    void engine_turn(bool side);
};


#endif //CHESS_PVE_GAME_H

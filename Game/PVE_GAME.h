//
// Created by Max Yurchenko on 19.09.2018.
//

#ifndef CHESS_PVE_GAME_H
#define CHESS_PVE_GAME_H


#include "Game.h"
#include "../Graphics/ChessGraphic.h"

class PVE_GAME : public Game{

    bool is_player_turn;
    bool player_side;
    bool engine_side;
    GameLogsWriter gameLogsWriter;
    ChessGraphic chessGraphic;
public:
    PVE_GAME();

    void write_desk(){
        gameLogsWriter.write_current_desk(getCurrent_desk(), false);
    }

    void pve_game();


    void engine_turn(bool side);
};


#endif //CHESS_PVE_GAME_H

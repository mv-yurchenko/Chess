//
// Created by Max Yurchenko on 05.09.2018.
//

#ifndef CHESS_PVP_GAME_H
#define CHESS_PVP_GAME_H

#include "Game.h"
#include "../Graphics/ChessGraphic.h"

class PVP_GAME : public Game{

    bool player1_side;
    bool player2_side;
    ChessGraphic chessGraphic{};
public:

    void pvp_game();
};


#endif //CHESS_PVP_GAME_H

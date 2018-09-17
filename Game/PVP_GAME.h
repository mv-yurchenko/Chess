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

    bool player_turn(bool is_white_move, Coordinates old_coordinates, Coordinates new_coordinates);

    void local_game();

    void pvp_game(bool is_game_online);
};


#endif //CHESS_PVP_GAME_H

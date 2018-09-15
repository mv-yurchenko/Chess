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

    bool player_turn(bool is_white_move, Coordinates old_coordinates, Coordinates new_coordinates)  {
        if (getCurrent_desk()->get_figure_by_coordinates(old_coordinates.getX(), old_coordinates.getY())->getSide() == is_white_move){
            return move_figure(old_coordinates.getX(), old_coordinates.getY(), new_coordinates.getX(), new_coordinates.getY());
        }
        else{
            return false;
        }
    }

    void pvp_game(bool is_game_online);
};


#endif //CHESS_PVP_GAME_H

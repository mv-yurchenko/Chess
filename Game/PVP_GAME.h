//
// Created by Max Yurchenko on 05.09.2018.
//

#ifndef CHESS_PVP_GAME_H
#define CHESS_PVP_GAME_H

#include "Game.h"

class PVP_GAME : public Game{

    bool player1_side;
    bool player2_side;

public:

    void pvp_game(){

        this->player1_side = true;
        this->player2_side = false;

        while (not get_is_game_finished()){
            if (isWhite_turn()){
                std::cout<<"Input figure coordinates" << std::endl;

                int x = input_coordinate("x");
                int y = input_coordinate("y");

                std::cout<<"Your choice:" << getCurrent_desk()->get_figure_by_coordinates(x, y)->getName()<< std::endl;

                std::cout<<"Input new coordinates" << std::endl;

                int new_x = input_coordinate("x");
                int new_y = input_coordinate("y");
            }
            else{

            }
        }
    }
};


#endif //CHESS_PVP_GAME_H

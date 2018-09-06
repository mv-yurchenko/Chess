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

        initialize_game();

        this->player1_side = true;
        this->player2_side = false;

        while (not get_is_game_finished()){
            player_turn(isWhite_turn());
        }

    }
};


#endif //CHESS_PVP_GAME_H

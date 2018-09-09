//
// Created by Max Yurchenko on 05.09.2018.
//

#include "PVP_GAME.h"

void PVP_GAME::pvp_game() {

    initialize_game();

    this->player1_side = true;
    this->player2_side = false;

    while (not get_is_game_finished()){
        if (not player_turn(isWhite_turn())) {
            print_request_to_move_again();
        }
    }

}

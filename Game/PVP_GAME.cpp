//
// Created by Max Yurchenko on 05.09.2018.
//

#include "PVP_GAME.h"

void PVP_GAME::pvp_game() {

    initialize_game();

    this->player1_side = true;
    this->player2_side = false;

    while (not get_is_game_finished()){
        player_turn(isWhite_turn());
    }

    // TODO: Сообшенеи о невозможности хода и просьба переходить

}

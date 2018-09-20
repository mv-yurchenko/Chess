//
// Created by Max Yurchenko on 19.09.2018.
//

#include "PVE_GAME.h"

PVE_GAME::PVE_GAME() {
    initialize_game();
    player_side = random_player_side();
    engine_side = not player_side;
    is_player_turn = player_side;
}

void PVE_GAME::engine_turn(bool side) {
    // TODO  !!!!!!!!!!
}

void PVE_GAME::pve_game() {
    initialize_game();

    this->player_side = random_player_side();
    this->engine_side = not this->player_side;
    this->setWhite_turn(true);

    while (not this->get_is_game_finished()){
        chessGraphic.print_desk(getCurrent_desk());
        if (is_player_turn){
            human_turn(isWhite_turn());
//            is_player_turn = not is_player_turn;
        } else{
            engine_turn(engine_side);
        }
    }
}

void PVE_GAME::write_desk() {
    gameLogsWriter.write_current_desk(getCurrent_desk(), false);
}

//
// Created by Max Yurchenko on 05.09.2018.
//

#include "PVP_GAME.h"

void PVP_GAME::pvp_game(bool is_game_online) {

    //////////////////////////////////////////
    //  1) Initialize Game
    //  2) bool is_game_online
    //  3) Делаем ход, если играем белыми
    //  4) Если черными, ждем хода противника(онлайн)
    /////////////////////////////////////////
    initialize_game();

    this->player1_side = random_player_side();
    this->player1_side = not this->player1_side;
    this->setWhite_turn(true);

    while (not this->get_is_game_finished()) {

        chessGraphic.print_desk(getCurrent_desk());

        if (is_game_online) {
            // Онлайн игра
        } else {
            // Локальная игра
            local_game();
        }
    }
}

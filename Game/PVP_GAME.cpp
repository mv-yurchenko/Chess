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

bool PVP_GAME::player_turn(bool is_white_move, Coordinates old_coordinates, Coordinates new_coordinates) {
    if (getCurrent_desk()->get_figure_by_coordinates(old_coordinates.getX(), old_coordinates.getY())->getSide() == is_white_move){
        return move_figure(old_coordinates.getX(), old_coordinates.getY(), new_coordinates.getX(), new_coordinates.getY());
    }
    else{
        return false;
    }
}

void PVP_GAME::local_game() {
    std::cout << "Input figure to move" << std::endl;
    Coordinates figure_coordinates = input_coordinates();
    print_msg_about_figure_choice(figure_coordinates);

    std::cout << "Input new coordinates" << std::endl;
    Coordinates new_coordinates = input_coordinates();

    if (player_turn(isWhite_turn(), figure_coordinates, new_coordinates)) {
        print_msg_about_success_move(figure_coordinates.getX(), figure_coordinates.getY(),
                                     new_coordinates.getX(), new_coordinates.getY());
        setWhite_turn(not isWhite_turn());
        this->setIs_game_finished(is_mate(new_coordinates.getX(), new_coordinates.getY()));
        //////////////////////////////////////////
        //  Дебаг
        /////////////////////////////////////////
        getCurrent_desk()->get_figure_by_coordinates(new_coordinates)->print_possible_moves();
    } else {
        //////////////////////////////////////////
        //  Дебаг
        /////////////////////////////////////////
        getCurrent_desk()->get_figure_by_coordinates(figure_coordinates)->print_possible_moves();
        print_msg_about_failed_move(figure_coordinates.getX(), figure_coordinates.getY(),
                                    new_coordinates.getX(), new_coordinates.getY());
    }
}

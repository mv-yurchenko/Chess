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

    bool game_finished = false;

    while (not game_finished) {

        chessGraphic.print_desk(getCurrent_desk());

        if (is_game_online) {
            // Онлайн игра
        } else {
            // Локальная игра
            std::cout << "Input figure to move" << std::endl;
            Coordinates figure_coordinates = input_coordinates();
            print_msg_about_figure_choice(figure_coordinates);

            std::cout << "Input new coordinates" << std::endl;
            Coordinates new_coordinates = input_coordinates();

            if (player_turn(isWhite_turn(), figure_coordinates, new_coordinates)) {
                print_msg_about_success_move(figure_coordinates.getX(), figure_coordinates.getY(),
                                             new_coordinates.getX(), new_coordinates.getY());
                setWhite_turn(not isWhite_turn());
                game_finished = is_mate(new_coordinates.getX(), new_coordinates.getY());
            } else
                print_msg_about_failed_move(figure_coordinates.getX(), figure_coordinates.getY(),
                                            new_coordinates.getX(), new_coordinates.getY());
        }
    }
}

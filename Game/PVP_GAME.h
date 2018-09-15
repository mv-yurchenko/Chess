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

    void local_game(){
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
        } else
            print_msg_about_failed_move(figure_coordinates.getX(), figure_coordinates.getY(),
                                        new_coordinates.getX(), new_coordinates.getY()); }

    void pvp_game(bool is_game_online);
};


#endif //CHESS_PVP_GAME_H

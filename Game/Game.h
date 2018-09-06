//
// Created by Max Yurchenko on 05.09.2018.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include "../Desk.h"

class Game {
    Desk *current_desk;

    bool is_game_finished;

    bool white_turn;
public:
    bool isWhite_turn() const;

public:
    Desk *getCurrent_desk() const;

    bool get_is_game_finished() const;

    void initialize_game();

    void move_figure(uint8_t old_x, uint8_t old_y, uint8_t new_x, uint8_t new_y);

    void finish_game();

    int input_coordinate(const char *coord_name);

    bool is_mate(Coordinates coordinates);

    void player_turn(bool is_white_turn){
        std::cout<<"Input figure coordinates" << std::endl;

        int x = input_coordinate("x");
        int y = input_coordinate("y");

        std::cout<<"Your choice:" << getCurrent_desk()->get_figure_by_coordinates(x, y)->getName()<< std::endl;

        std::cout<<"Input new coordinates" << std::endl;

        int new_x = input_coordinate("x");
        int new_y = input_coordinate("y");

        if (is_white_turn == getCurrent_desk()->get_figure_by_coordinates(x, y)->getSide()) {
            move_figure(x, y, new_x, new_y);
        } else{
            std::cout<<"Move is not possible" << std::endl;
        }
    }
};


#endif //CHESS_GAME_H

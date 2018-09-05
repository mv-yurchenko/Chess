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

    void finish_game(){
        is_game_finished = true;
    }

    int input_coordinate(const char *coord_name){
        std::cout<<coord_name << std::endl;
        int coord;
        std::cin >> coord;
        return coord;
    }
};


#endif //CHESS_GAME_H

//
// Created by Max Yurchenko on 05.09.2018.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include "../Desk.h"

class Game {
    Desk *current_desk;
    bool is_game_finished;
public:
    void initialize_game(){
        this->current_desk = new Desk();
        current_desk->initialize_desk();
        current_desk->print_desk();
    }

    void move_figure(uint8_t old_x, uint8_t old_y, uint8_t new_x, uint8_t new_y){
        Coordinates old_coord(old_x, old_y);
        Coordinates new_coord(new_x, new_y);
        std::cout << this->current_desk->get_figure_by_coordinates(old_x, old_y)->getName() << std::endl;
        this->current_desk->get_figure_by_coordinates(old_x, old_y)->print_possible_moves();
        std::cout <<this->current_desk->move_figure(old_coord, new_coord) << std::endl;
    }
};


#endif //CHESS_GAME_H

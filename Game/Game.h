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
    void initialize_game();

    void move_figure(uint8_t old_x, uint8_t old_y, uint8_t new_x, uint8_t new_y);
};


#endif //CHESS_GAME_H

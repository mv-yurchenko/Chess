//
// Created by max on 27.09.18.
//

#ifndef CHESS_ENGINE_H
#define CHESS_ENGINE_H

#include "../Desk.h"
#include "MoveWeight.h"
#include "cstdlib"
#include <ctime>


class Engine {
    std::vector<MoveWeight> possibilities;
    Desk *new_desk;
    Desk *current_desk;
    MoveWeight most_profitable_move;
    bool is_move_white;
public:
    Engine() = default;

    Engine(Desk *desk, bool is_move_white);

    void add_possible_moves_to_possibilities(Figure figure);

    void print_possibilities();

    Move move();

    void search_max_possibility();

    int get_random_num(int max_num);
};


#endif //CHESS_ENGINE_H

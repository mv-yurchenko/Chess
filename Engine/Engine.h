//
// Created by max on 27.09.18.
//

#ifndef CHESS_ENGINE_H
#define CHESS_ENGINE_H

#include "../Desk.h"
#include "MoveWeight.h"

class Engine {
    std::vector<MoveWeight> possibilities;
    Desk *new_desk;
    Desk *current_desk;
    bool is_move_white;
public:
    Engine() = default;

    Engine(Desk *desk, bool is_move_white);

    void add_possible_moves_to_possibilities(Figure *figure);

    void print_possibilities();
};


#endif //CHESS_ENGINE_H

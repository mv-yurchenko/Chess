#include <random>

//
// Created by max on 27.09.18.
//

#ifndef CHESS_ENGINE_H
#define CHESS_ENGINE_H

#include "../Desk.h"
#include "MoveWeight.h"
#include <algorithm>

class Engine {
    std::vector<MoveWeight> possibilities;
    Desk *new_desk;
    Desk *current_desk;
    std::vector<MoveWeight> most_profitable_moves;
    bool is_move_white;
public:
    Engine() = default;

    void search_max_possibilities();

    MoveWeight search_most_profitable_move();

    std::vector<MoveWeight> search_moves_with_same_weight(MoveWeight move);

    Engine(Desk *desk, bool is_move_white);

    void initialize_possibilities(std::vector<Figure> figures);

    void print_possibilities();

    const std::vector<MoveWeight> &getPossibilities() const;

    const std::vector<MoveWeight> &getMost_profitable_moves() const;

    Move engine_move();
};


#endif //CHESS_ENGINE_H

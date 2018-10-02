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
    MoveWeight most_profitable_move;
    bool is_move_white;
public:
    Engine() = default;

    Engine(Desk *desk, bool is_move_white);

    void add_possible_moves_to_possibilities(Figure figure);

    void print_possibilities();

    Move move(){
        search_max_possibility();
        return most_profitable_move.getMove();
    }

    void search_max_possibility(){
        most_profitable_move = possibilities[0];
        for (auto possibility : possibilities){
            if (possibility.getWeight() > most_profitable_move.getWeight()){
                most_profitable_move = possibility;
            }
            if (possibility.getWeight() == most_profitable_move.getWeight() and ( 20 + (rand() % static_cast<int>(100 - 20 + 1))) % 2) {
                most_profitable_move = possibility;
            }
        }
    }
};


#endif //CHESS_ENGINE_H

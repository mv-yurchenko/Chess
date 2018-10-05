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

    Engine(Desk *desk, bool is_move_white){
        this->current_desk = desk;
        std::vector<Figure> figures;
        if (is_move_white) {
             figures = desk->getWhite_figures();
        } else{
            figures = desk->getBlack_figures();
        }
        this->initialize_possibilities(figures);
    }

    void initialize_possibilities(std::vector<Figure> figures){
        for (auto figure : figures){
            for (auto possible_move : figure.getPossible_moves()){
                MoveWeight possibility;
                possibility.setMove(possible_move);
                possibility.setWeight(this->current_desk->get_figure_by_coordinates(possible_move.getNew_coordinates())->getValue());
                possibilities.push_back(possibility);
            }
        }
    }

    void print_possibilities();
};


#endif //CHESS_ENGINE_H

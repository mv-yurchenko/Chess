//
// Created by max on 27.09.18.
//

#include "Engine.h"

Engine::Engine(Desk *desk, bool is_move_white) {
    this->current_desk = desk;
    this->is_move_white = is_move_white;
    if (is_move_white){
        for (Figure figure : desk->getWhite_figures()){
            add_possible_moves_to_possibilities(&figure);
        }
    } else{
        for (Figure figure : desk->getBlack_figures()){
            add_possible_moves_to_possibilities(&figure);
        }
    }
}

void Engine::add_possible_moves_to_possibilities(Figure *figure) {
    for (const auto possible_move : figure->getPossible_moves()){
        MoveWeight possibility;
        possibility.setWeight(current_desk->get_figure_by_coordinates(possible_move.getNew_coordinates().getX(),
                                                                      possible_move.getNew_coordinates().getY())->getValue());
        possibility.setMove(possible_move);
        this->possibilities.push_back(possibility);
    }
}

void Engine::print_possibilities() {
    //////////////////////////////////////////
    //  Дебаг функция
    /////////////////////////////////////////
    for (MoveWeight possibility : possibilities){
        std::cout << "Possibility:" << std::endl;
        std::cout << "Weight: " << possibility.getWeight() << std::endl;
    }
}

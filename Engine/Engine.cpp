//
// Created by max on 27.09.18.
//

#include <time.h>
#include <algorithm>
#include <random>
#include "Engine.h"

Engine::Engine(Desk *desk, bool is_move_white) {
    this->current_desk = desk;
    this->is_move_white = is_move_white;
    if (is_move_white){
        for (Figure figure : desk->getWhite_figures()){
                add_possible_moves_to_possibilities(figure);
        }
    } else{
        for (Figure figure : desk->getBlack_figures()){
            add_possible_moves_to_possibilities(figure);
        }
    }
    this->print_possibilities();
}

void Engine::print_possibilities() {
    //////////////////////////////////////////
    //  Дебаг функция
    /////////////////////////////////////////
    std::ofstream output_file;
    output_file.open("../DebugOutput/print_possibilities.txt");
    for (MoveWeight possibility : possibilities){
        output_file << "Possibility:" << std::endl;
        output_file << "Current coordinates : " << possibility.getMove().getOld_coordinates().getX() << " " <<
                    possibility.getMove().getOld_coordinates().getY() << std::endl;
        output_file << "New coordinates : " << possibility.getMove().getNew_coordinates().getX() << " " <<
                    possibility.getMove().getNew_coordinates().getY() << std::endl;
        output_file << "Weight: " << possibility.getWeight() << std::endl;
        output_file << "----------------------------------------------------" << std::endl;
    }
}

void Engine::add_possible_moves_to_possibilities(Figure figure) {
    possibilities.clear();
    for (auto possible_move : figure.getPossible_moves()){
        MoveWeight possibility;
        possibility.setMove(possible_move);
        possibility.setWeight(this->current_desk->get_figure_by_coordinates(possible_move.getNew_coordinates())->getValue());
        possibilities.push_back(possibility);
    }
}

int Engine::get_random_num(int max_num) {
    srand(static_cast<unsigned int>(time(nullptr)));
    return rand() % max_num;
}

void Engine::search_max_possibility() {
    for (auto possibility : possibilities) {
        if (possibility.getWeight() > most_profitable_move.getWeight()) {
            most_profitable_move = possibility;
        }
        if (possibility.getWeight() == most_profitable_move.getWeight() and
            (20 + (rand() % static_cast<int>(100 - 20 + 1))) % 2) {
            most_profitable_move = possibility;
        }
    }
}

Move Engine::move() {
    search_max_possibility();
    return most_profitable_move.getMove();
}



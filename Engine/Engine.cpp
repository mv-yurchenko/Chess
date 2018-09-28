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
            std::cout << figure.getDesk_name() << std::endl;
                add_possible_moves_to_possibilities(figure);
        }
    } else{
        for (Figure figure : desk->getBlack_figures()){
            std::cout << figure.getDesk_name() << std::endl;
            add_possible_moves_to_possibilities(figure);
        }
    }
    this->print_possibilities();
}

void Engine::add_possible_moves_to_possibilities(Figure figure) {
    clear_possibilities();
    for (const auto possible_move : figure.getPossible_moves()){
        MoveWeight possibility;
        possibility.setWeight(current_desk->get_figure_by_coordinates(possible_move.getNew_coordinates().getX(),
                                                                      possible_move.getNew_coordinates().getY())->getValue());
        possibility.setMove(possible_move);
        this->possibilities.push_back(possibility);
    }
}

void Engine::clear_possibilities() {
    this->possibilities.clear();
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

void Engine::search_max_possibility() {
    srand (time(NULL));
    auto random_engine = std::default_random_engine {};
    std::shuffle ( this->possibilities.begin(), this->possibilities.end() , random_engine);
    this->most_profitable_move = possibilities[0];
    for (auto possibility : possibilities){
        if (possibility.getWeight() > this->most_profitable_move.getWeight()){
            this->most_profitable_move = possibility;
        }
        if (possibility.getWeight() == this->most_profitable_move.getWeight() && rand() % 2 == 0) {
            this->most_profitable_move = possibility;
        }
    }
}

Move Engine::move() {
    search_max_possibility();
    return this->most_profitable_move.getMove();
}

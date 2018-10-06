//
// Created by max on 27.09.18.
//

#include <time.h>
#include <algorithm>
#include <random>
#include "Engine.h"

void Engine::print_possibilities() {
    //////////////////////////////////////////
    //  Дебаг функция
    /////////////////////////////////////////
    std::ofstream output_file;
    output_file.open("../DebugOutput/print_possibilities.txt");
    for (MoveWeight possibility : possibilities){
        output_file << "Figure : " + this->current_desk->get_figure_by_coordinates(possibility.getMove().getOld_coordinates())->getName() + "\n";
        output_file << "Side : " + (std::string)this->current_desk->get_figure_by_coordinates(possibility.getMove().getOld_coordinates())->get_side_as_string() + "\n";
        output_file << "Possibility:" << std::endl;
        output_file << "Current coordinates : " << possibility.getMove().getOld_coordinates().getX() << " " <<
                possibility.getMove().getOld_coordinates().getY() << std::endl;
        output_file << "New coordinates : " << possibility.getMove().getNew_coordinates().getX() << " " <<
                  possibility.getMove().getNew_coordinates().getY() << std::endl;
        output_file << "Weight: " << possibility.getWeight() << std::endl;
        output_file << "----------------------------------------------------" << std::endl;
    }
}

void Engine::initialize_possibilities(std::vector<Figure> figures) {
    for (auto figure : figures){
        for (auto possible_move : figure.getPossible_moves()){
            MoveWeight possibility;
            possibility.setMove(possible_move);
            possibility.setWeight(this->current_desk->get_figure_by_coordinates(possible_move.getNew_coordinates())->getValue());
            possibilities.push_back(possibility);
        }
    }
}

Engine::Engine(Desk *desk, bool is_move_white) {
    this->current_desk = desk;
    std::vector<Figure> figures;
    if (is_move_white) {
        figures = desk->getWhite_figures();
    } else{
        figures = desk->getBlack_figures();
    }
    this->initialize_possibilities(figures);
}

const std::vector<MoveWeight> &Engine::getPossibilities() const {
    return possibilities;
}

const std::vector<MoveWeight> &Engine::getMost_profitable_moves() const {
    return most_profitable_moves;
}

void Engine::search_max_possibilities() {
    MoveWeight most_profitable_move = this->search_most_profitable_move();
    this->most_profitable_moves.push_back(most_profitable_move);
    std::vector<MoveWeight> moves_with_the_max_weight = search_moves_with_same_weight(most_profitable_move);
    this->most_profitable_moves.insert(this->most_profitable_moves.end(), moves_with_the_max_weight.begin(),
                                       moves_with_the_max_weight.end());
}

MoveWeight Engine::search_most_profitable_move() {
    MoveWeight most_profitable_move = possibilities[0];
    for (auto possibility : possibilities){
        if (possibility.getWeight() > most_profitable_move.getWeight()){
            most_profitable_move = possibility;
        }
    }
    return most_profitable_move;
}

std::vector<MoveWeight> Engine::search_moves_with_same_weight(MoveWeight move) {
    std::vector <MoveWeight> moves_with_the_same_weight;
    for (auto possible_move : this->possibilities){
        if (possible_move.getWeight() == move.getWeight()){
            moves_with_the_same_weight.push_back(possible_move);
        }
    }
    return moves_with_the_same_weight;
}

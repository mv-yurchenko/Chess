//
// Created by Max Yurchenko on 24.08.2018.
//

#include "Figure.h"

Figure::Figure(bool side, const Coordinates &coordinates, const char *name) {
    this->side = side;
    this->coordinates = coordinates;
    calculate_available_moves();
//    calculate_possible_moves();
}

void Figure::move_figure() {

}

void Figure::calculate_available_moves() {

}

void Figure::calculate_possible_moves(std::vector<Figure> white_figures ,std::vector<Figure> black_figures ) {

}

const Coordinates &Figure::getCoordinates() const {
    return coordinates;
}

const std::vector<Move> &Figure::getAvailable_moves() const {
    return available_moves;
}

const std::vector<Move> &Figure::getPossible_moves() const {
    return possible_moves;
}

const std::string &Figure::getName() const {
    return name;
}

bool Figure::is_out_of_border(Coordinates coordinates) {
    return  coordinates.getX() >= 8 or coordinates.getX() < 0 or coordinates.getY() >= 8 or coordinates.getY() < 0;
}

Figure::Figure() {

}

void Figure::add_move_to_available_moves(Coordinates new_coordinates) {
    Move available_move(this->getCoordinates(), new_coordinates);
    this->available_moves.push_back(available_move);
}

void Figure::setCoordinates(const Coordinates &coordinates) {
    this->coordinates = coordinates;
}

bool Figure::is_coordinates_same(Coordinates coordinates1, Coordinates coordinates2) {
    return coordinates1.getX() == coordinates2.getX() and coordinates2.getY() == coordinates1.getY();
}

bool Figure::is_figure_white() {
    return this->side;
}

bool Figure::is_figure_black() {
    return not this->side;
}

void Figure::print_possible_moves() {
    //////////////////////////////////////////
    //  Дебаг функция
    /////////////////////////////////////////
    for (auto move : this->getPossible_moves()){
        std::cout << "New coordinates" << std::endl;
        std::cout << move.getNew_coordinates().getX() << std::endl;
        std::cout << move.getNew_coordinates().getY() << std::endl;
        std::cout << "--------------------------" << std::endl;
    }
}

void Figure::print_available_moves() {
    //////////////////////////////////////////
    //  Дебаг функция
    /////////////////////////////////////////
    for (auto move : this->getAvailable_moves()){
        std::cout << "New coordinates" << std::endl;
        std::cout << move.getNew_coordinates().getX() << std::endl;
        std::cout << move.getNew_coordinates().getY() << std::endl;
        std::cout << "--------------------------" << std::endl;
    }
}

Figure::Figure(bool side, Coordinates coordinates) {
    this->side = side;
    this->coordinates = coordinates;
}

void Figure::setName(const std::string &name) {
    Figure::name = name;
}

void Figure::setSide(bool side) {
    Figure::side = side;
}

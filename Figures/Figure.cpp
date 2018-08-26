//
// Created by Max Yurchenko on 24.08.2018.
//

#include "Figure.h"

Figure::Figure(bool side, const Coordinates &coordinates, const char *name) {
    this->side = side;
    this->coordinates = coordinates;
    calculate_available_moves();
    calculate_possible_moves();
}

void Figure::move_figure() {

}

void Figure::calculate_available_moves() {

}

void Figure::calculate_possible_moves() {

}

bool Figure::isSide() const {
    return side;
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
    return  coordinates.getX() > 8 or coordinates.getX() < 0 or coordinates.getY() > 8 or coordinates.getY() < 0;
}

Figure::Figure() {

}

void Figure::add_move_to_available_moves(Coordinates new_coordinates) {
    Move available_move(this->getCoordinates(), new_coordinates);
    this->available_moves.push_back(available_move);
}

void Figure::setCoordinates(const Coordinates &coordinates) {
    Figure::coordinates = coordinates;
}

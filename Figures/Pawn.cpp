//
// Created by Max Yurchenko on 27.08.2018.
//

#include "Pawn.h"

Pawn::Pawn(bool side, Coordinates coordinates){
    this->setName("Pawn");
    this->setSide(side);
    this->setCoordinates(coordinates);
}

Pawn::Pawn() {

}

void Pawn::calculate_available_moves() {
    Coordinates new_position;
    if (is_figure_white()) {
        new_position.setX(this->getCoordinates().getX());
        new_position.setY(this->getCoordinates().getY() + 1);
        if (not is_out_of_border(new_position)) {
            add_move_to_available_moves(new_position);
        }
        if (this->getCoordinates().getY() == 1) {
            new_position.setX(this->getCoordinates().getX());
            new_position.setX(this->getCoordinates().getY() + 2);
            if (not is_out_of_border(new_position)) {
                add_move_to_available_moves(new_position);
            }
        }
        // Пешка есть по диагонали
        new_position.setX(this->getCoordinates().getX() + 1);
        new_position.setY(this->getCoordinates().getY() + 1);
        if (not is_out_of_border(new_position)) {
            add_move_to_available_moves(new_position);
        }

        new_position.setX(this->getCoordinates().getX() - 1);
        new_position.setY(this->getCoordinates().getY() + 1);
        if (not is_out_of_border(new_position)) {
            add_move_to_available_moves(new_position);
        }
    }
    if (is_figure_black()){
        new_position.setX(this->getCoordinates().getX());
        new_position.setY(this->getCoordinates().getY() - 1);
        if (not is_out_of_border(new_position)) {
            add_move_to_available_moves(new_position);
        }
        if (this->getCoordinates().getY() == 6) {
            new_position.setX(this->getCoordinates().getX());
            new_position.setY(this->getCoordinates().getY() - 2);
            if (not is_out_of_border(new_position)) {
                add_move_to_available_moves(new_position);
            }
        }
        // Пешка есть по диагонали
        new_position.setX(this->getCoordinates().getX() + 1);
        new_position.setY(this->getCoordinates().getY() - 1);
        if (not is_out_of_border(new_position)) {
            add_move_to_available_moves(new_position);
        }

        new_position.setX(this->getCoordinates().getX() - 1);
        new_position.setY(this->getCoordinates().getY() - 1);
        if (not is_out_of_border(new_position)) {
            add_move_to_available_moves(new_position);
        }
    }
}

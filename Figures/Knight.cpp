//
// Created by Max Yurchenko on 29.08.2018.
//

#include "Knight.h"

Knight::Knight(bool side, Coordinates coordinates) {
    this->setName("Knight");
    this->setSide(side);
    this->setCoordinates(coordinates);
}

Knight::Knight() {

}

void Knight::calculate_available_moves() {

    Coordinates current_coordinates = getCoordinates();
    Coordinates new_coordinates;
    // Заглушка для инициализации, по дефолту 2 аргумент - новые координаты
    Move possible_move(current_coordinates, current_coordinates);

    new_coordinates.setX(current_coordinates.getX() + 1);
    new_coordinates.setY(current_coordinates.getY() + 2);
    if (not is_out_of_border(new_coordinates)){
        possible_move.setNew_coordinates(new_coordinates);
    }

    new_coordinates.setX(current_coordinates.getX() - 1);
    new_coordinates.setY(current_coordinates.getY() + 2);
    if (not is_out_of_border(new_coordinates)){
        possible_move.setNew_coordinates(new_coordinates);
    }

    new_coordinates.setX(current_coordinates.getX() - 2);
    new_coordinates.setY(current_coordinates.getY() + 1);
    if (not is_out_of_border(new_coordinates)){
        possible_move.setNew_coordinates(new_coordinates);
    }

    new_coordinates.setX(current_coordinates.getX() - 2);
    new_coordinates.setY(current_coordinates.getY() - 1);
    if (not is_out_of_border(new_coordinates)){
        possible_move.setNew_coordinates(new_coordinates);
    }

    new_coordinates.setX(current_coordinates.getX() - 1);
    new_coordinates.setY(current_coordinates.getY() - 2);
    if (not is_out_of_border(new_coordinates)){
        possible_move.setNew_coordinates(new_coordinates);
    }

    new_coordinates.setX(current_coordinates.getX() + 1);
    new_coordinates.setY(current_coordinates.getY() - 2);
    if (not is_out_of_border(new_coordinates)){
        possible_move.setNew_coordinates(new_coordinates);
    }

    new_coordinates.setX(current_coordinates.getX() + 2);
    new_coordinates.setY(current_coordinates.getY() - 1);
    if (not is_out_of_border(new_coordinates)){
        possible_move.setNew_coordinates(new_coordinates);
    }

    new_coordinates.setX(current_coordinates.getX() + 2);
    new_coordinates.setY(current_coordinates.getY() + 1);
    if (not is_out_of_border(new_coordinates)){
        possible_move.setNew_coordinates(new_coordinates);
    }
}

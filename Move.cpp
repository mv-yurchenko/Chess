//
// Created by Max Yurchenko on 25.08.2018.
//

#include "Move.h"

bool Move::if_move_possible() {
    // TODO: Как функцию правильно сделать?
}

void Move::setOld_coordinates(const Coordinates &old_coordinates) {
    Move::old_coordinates = old_coordinates;
}

void Move::setNew_coordinates(const Coordinates &new_coordinates) {
    Move::new_coordinates = new_coordinates;
}

const Coordinates &Move::getOld_coordinates() const {
    return old_coordinates;
}

const Coordinates &Move::getNew_coordinates() const {
    return new_coordinates;
}

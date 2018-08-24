//
// Created by Max Yurchenko on 24.08.2018.
//

#include "Coordinates.h"

void Coordinates::setX(int x) {
    Coordinates::x = x;
}

void Coordinates::setY(int y) {
    Coordinates::y = y;
}

int Coordinates::getX() const {
    return x;
}

int Coordinates::getY() const {
    return y;
}

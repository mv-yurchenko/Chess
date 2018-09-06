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

Coordinates::Coordinates(int x, int y) {
    this->x = x;
    this->y = y;
}

Coordinates::Coordinates() {

}

bool Coordinates::operator==(const Coordinates &coord_1) {
    return coord_1.x == this->x and coord_1.y == this->y;
}

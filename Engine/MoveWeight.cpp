//
// Created by max on 26.09.18.
//

#include "MoveWeight.h"

MoveWeight::MoveWeight(int weight, Move move) : weight(weight), move(move) {}

const Move &MoveWeight::getMove() const {
    return move;
}

int MoveWeight::getWeight() const {
    return weight;
}

void MoveWeight::setMove(const Move &move) {
    MoveWeight::move = move;
}

void MoveWeight::setWeight(int weight) {
    MoveWeight::weight = weight;
}
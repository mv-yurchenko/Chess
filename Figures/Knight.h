//
// Created by Max Yurchenko on 29.08.2018.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H


#include "Figure.h"

class Knight : public Figure{
    Knight(bool side, Coordinates coordinates);

    Knight();

    void calculate_available_moves() override;

    void calculate_possible_moves()

};


#endif //CHESS_KNIGHT_H

//
// Created by Max Yurchenko on 25.08.2018.
//


#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "Figure.h"
#include <string>

class King : public Figure{
public:
    King();

    King(bool side, Coordinates coordinates) : Figure(side, coordinates ,"king"){

    }
    void calculate_available_moves();
};


#endif //CHESS_KING_H

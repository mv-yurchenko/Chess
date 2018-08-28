//
// Created by Max Yurchenko on 27.08.2018.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H


#include "Figure.h"

class Pawn : public Figure{
public:
    Pawn();

    Pawn(bool side, Coordinates coordinates);

    void calculate_available_moves();
};


#endif //CHESS_PAWN_H

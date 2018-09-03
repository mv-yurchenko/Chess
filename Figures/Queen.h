//
// Created by Max Yurchenko on 03.09.2018.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H


#include "Figure.h"

class Queen : public Figure{

public:

Queen(bool side, Coordinates coordinates);

Queen();

void calculate_available_moves() override;
};


#endif //CHESS_QUEEN_H

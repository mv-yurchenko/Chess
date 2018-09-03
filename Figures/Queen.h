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

void calculate_possible_moves(std::vector<Figure> white_figures, std::vector<Figure> black_figures) override;
};


#endif //CHESS_QUEEN_H

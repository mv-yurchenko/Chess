//
// Created by Max Yurchenko on 02.09.2018.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H


#include "Figure.h"

class Bishop : public Figure{
public:

    Bishop(bool side, Coordinates coordinates);

    void calculate_available_moves() override;

    void calculate_possible_moves(std::vector<Figure> white_figures, std::vector<Figure> black_figures) override{

    }
};


#endif //CHESS_BISHOP_H

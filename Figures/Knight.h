//
// Created by Max Yurchenko on 29.08.2018.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H


#include "Figure.h"

class Knight : public Figure{
public:
    Knight(bool side, Coordinates coordinates);

    Knight();

    void calculate_available_moves();

    void calculate_possible_moves(std::vector<Figure> white_figures, std::vector<Figure> black_figures) override;

};


#endif //CHESS_KNIGHT_H

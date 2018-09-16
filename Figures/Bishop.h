//
// Created by Max Yurchenko on 02.09.2018.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H


#include "Figure.h"

class Bishop : public Figure{

public:

    Bishop(bool side, Coordinates coordinates);

    void calculate_possible_moves(std::vector<Figure> white_figures, std::vector<Figure> black_figures) override;

    void calculate_one_direction(const std::vector<Figure> &white_figures, const std::vector <Figure> &black_figures, bool increment_up , bool increment_right);
};


#endif //CHESS_BISHOP_H

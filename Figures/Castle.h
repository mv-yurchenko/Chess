//
// Created by Max Yurchenko on 30.08.2018.
//

#ifndef CHESS_CASTLE_H
#define CHESS_CASTLE_H


#include "Figure.h"


class Castle : public Figure{

public:

    Castle(bool side, Coordinates coordinates);

    void calculate_possible_moves(std::vector<Figure> white_figures, std::vector<Figure> black_figures) override;

    void calculate_one_direction(const std::vector<Figure> &white_figures, const std::vector<Figure> &black_figures,
                                         bool increment_up,bool increment_down,bool increment_right, bool increment_left);
};


#endif //CHESS_CASTLE_H

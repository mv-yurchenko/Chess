//
// Created by Max Yurchenko on 30.08.2018.
//

#ifndef CHESS_CASTLE_H
#define CHESS_CASTLE_H


#include "Figure.h"


class Castle : public Figure{

public:

    Castle(bool side, Coordinates coordinates);

    void calculate_available_moves() override;

    void calculate_possible_moves(std::vector<Figure> white_figures, std::vector<Figure> black_figures) override;
};


#endif //CHESS_CASTLE_H

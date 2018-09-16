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

    King(bool side, Coordinates coordinates);

    void calculate_available_moves();

    void calculate_possible_moves(std::vector<Figure> white_figures ,std::vector<Figure> black_figures ) override;
};


#endif //CHESS_KING_H

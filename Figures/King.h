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

    void calculate_possible_moves(std::vector<Figure> white_figures ,std::vector<Figure> black_figures) override;

    void calculate_one_direction(const std::vector<Figure> &ally_figures, bool up, bool down, bool right, bool left);
};


#endif //CHESS_KING_H

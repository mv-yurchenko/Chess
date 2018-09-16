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

    void calculate_possible_moves(std::vector<Figure> white_figures, std::vector<Figure> black_figures) override;

    void calculate_bishop_one_direction(const std::vector<Figure> &white_figures, const std::vector<Figure> &black_figures,
                                 bool increment_up, bool increment_right);

    void calculate_castle_one_direction(const std::vector<Figure> &white_figures, const std::vector<Figure> &black_figures,
                                 bool increment_up, bool increment_down, bool increment_right, bool increment_left);
};


#endif //CHESS_QUEEN_H

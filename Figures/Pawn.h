//
// Created by Max Yurchenko on 27.08.2018.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H


#include "Figure.h"


class Pawn : public Figure {
public:
    Pawn();

    Pawn(bool side, Coordinates coordinates, uint8_t num);

    void calculate_available_moves() override;

    void calculate_possible_moves(std::vector<Figure> white_figures, std::vector<Figure> black_figures) override;
};


#endif //CHESS_PAWN_H

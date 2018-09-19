//
// Created by Max Yurchenko on 27.08.2018.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H


#include "Figure.h"


class Pawn : public Figure {
public:
    Pawn();

    Pawn(bool side, Coordinates coordinates, int num);

    void calculate_possible_moves(std::vector<Figure> white_figures, std::vector<Figure> black_figures) override;

    void calculate_move_forward_possibility(std::vector<Figure> white_figures, std::vector<Figure> black_figures);

    void calculate_two_cell_move_possibility(std::vector<Figure> white_figures, std::vector<Figure> black_figures);

    void calculate_diagonal_move_possibility(std::vector<Figure> white_figures, std::vector<Figure> black_figures);
};


#endif //CHESS_PAWN_H

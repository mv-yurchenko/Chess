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

    void calculate_possible_moves(std::vector<Figure> white_figures, std::vector<Figure> black_figures) override;

    void calculate_move_possibility_2_right_1_down(std::vector<Figure> ally_figures);

    void calculate_move_possibility_2_right_1_up(std::vector<Figure> ally_figures);

    void calculate_move_possibility_2_up_1_right(std::vector<Figure> ally_figures);

    void calculate_move_possibility_2_up_1_left(std::vector<Figure> ally_figures);

    void calculate_move_possibility_2_left_1_up(std::vector<Figure> ally_figures);

    void calculate_move_possibility_2_left_1_down(std::vector<Figure> ally_figures);

    void calculate_move_possibility_2_down_1_left(std::vector<Figure> ally_figures);

    void calculate_move_possibility_2_down_1_right(std::vector<Figure> ally_figures);

};


#endif //CHESS_KNIGHT_H

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

    void calculate_diagonal_move_possibility(std::vector<Figure> white_figures, std::vector<Figure> black_figures){
        Coordinates new_coordinates;

        if(is_figure_white()){
            for (int i = 0 ; i < 2; i++) {
                new_coordinates.setY(getCoordinates().getY() + 1);
                new_coordinates.setX(getCoordinates().getX() + (-1)^i);
                if (is_cell_busy_by_enemy_figure(new_coordinates, black_figures)) {
                    add_move_to_possible_moves(new_coordinates);
                }
            }
        } else{
            for (int i = 0 ; i < 2; i++) {
                new_coordinates.setY(getCoordinates().getY() - 1);
                new_coordinates.setX(getCoordinates().getX() + (-1)^i);
                if (is_cell_busy_by_enemy_figure(new_coordinates, white_figures)) {
                    add_move_to_possible_moves(new_coordinates);
                }
            }
        }
    }
};


#endif //CHESS_PAWN_H

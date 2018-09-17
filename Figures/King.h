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

    void calculate_one_direction(const std::vector<Figure> &ally_figures, bool up, bool down, bool right, bool left) {
        Coordinates new_coordinates(getCoordinates().getX(), getCoordinates().getY());

        if (up) {
            new_coordinates.setY(getCoordinates().getY() + 1);
        }
        if (down) {
            new_coordinates.setY(getCoordinates().getY() - 1);
        }
        if (right){
            new_coordinates.setX(getCoordinates().getX() + 1);
        }
        if (left){
            new_coordinates.setX(getCoordinates().getX() - 1);
        }
        if (not is_out_of_border(new_coordinates) and not is_cell_busy_by_ally_figure(new_coordinates, ally_figures)) {
            add_move_to_possible_moves(new_coordinates);
        }
    }
};


#endif //CHESS_KING_H

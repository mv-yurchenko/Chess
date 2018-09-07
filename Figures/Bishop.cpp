//
// Created by Max Yurchenko on 02.09.2018.
//

#include "Bishop.h"

Bishop::Bishop(bool side, Coordinates coordinates) : Figure(side, coordinates, "bishop", 3){

}

void Bishop::calculate_available_moves() {
    //////////////////////////////////////////
    //  tr = top   right
    //  br = bottom right
    //  bl = bottom left
    //  tl = top left
    /////////////////////////////////////////

    Coordinates new_coordinates(getCoordinates().getX(), getCoordinates().getY());

    // top right
    for (uint8_t i = 1; i < 8; i++){
        new_coordinates.setX(getCoordinates().getX() + i);
        new_coordinates.setY(getCoordinates().getY() + i);

        if (not is_out_of_border(new_coordinates)){
            add_move_to_available_moves(new_coordinates);
        }
    }

    // bottom right
    for (uint8_t i = 1; i < 8; i++){
        new_coordinates.setX(getCoordinates().getX() + i);
        new_coordinates.setY(getCoordinates().getY() - i);

        if (not is_out_of_border(new_coordinates)){
            add_move_to_available_moves(new_coordinates);
        }
    }

    // bottom left
    for (uint8_t i = 1; i < 8; i++){
        new_coordinates.setX(getCoordinates().getX() - i);
        new_coordinates.setY(getCoordinates().getY() - i);

        if (not is_out_of_border(new_coordinates)){
            add_move_to_available_moves(new_coordinates);
        }
    }

    // top left
    for (uint8_t i = 1; i < 8; i++){
        new_coordinates.setX(getCoordinates().getX() - i);
        new_coordinates.setY(getCoordinates().getY() - i);

        if (not is_out_of_border(new_coordinates)){
            add_move_to_available_moves(new_coordinates);
        }
    }
}

void Bishop::calculate_possible_moves(std::vector<Figure> white_figures, std::vector<Figure> black_figures) {

        //  top right

        calculate_one_direction(white_figures, black_figures, true, true);

        //  top left

        calculate_one_direction(white_figures, black_figures, true, false);

        // bottom right

        calculate_one_direction(white_figures, black_figures, false, true);

        // bottom left

        calculate_one_direction(white_figures, black_figures, false, false);

}

void Bishop::calculate_one_direction(const std::vector<Figure> &white_figures, const std::vector<Figure> &black_figures,
                                     bool increment_up, bool increment_right) {

    Coordinates new_coordinates(getCoordinates().getX(), getCoordinates().getY());
    bool is_way_free = true;
    bool is_not_out_of_border = true;

    std::vector<Figure> allies_figure;
    std::vector<Figure> enemy_figures;

    if (getSide()){
        allies_figure = white_figures;
        enemy_figures = black_figures;
    } else{
        allies_figure = black_figures;
        enemy_figures = white_figures;
    }
    for(uint8_t i = 1; i < 8; i++) {
        if (is_way_free and is_not_out_of_border) {
            bool is_move_possible = true;
            if (increment_right)
                new_coordinates.setX(getCoordinates().getX() + i);
            else
                new_coordinates.setX(getCoordinates().getX() - i);
            if (increment_up)
                new_coordinates.setY(getCoordinates().getY() + i);
            else
                new_coordinates.setY(getCoordinates().getY() - i);
            if (is_out_of_border(new_coordinates)) {
                is_not_out_of_border = false;
            } else {
                if (is_cell_busy_by_enemy_figure(new_coordinates, enemy_figures)){
                    add_move_to_possible_moves(new_coordinates);
                    is_way_free = false;
                }
                if (is_cell_busy_by_ally_figure(new_coordinates, allies_figure)){
                    is_way_free = false;
                    is_move_possible = false;
                }
                if (is_move_possible)
                    add_move_to_possible_moves(new_coordinates);
            }
        }
    }
}



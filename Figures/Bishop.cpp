//
// Created by Max Yurchenko on 02.09.2018.
//

#include "Bishop.h"

Bishop::Bishop(bool side, Coordinates coordinates) : Figure(side, coordinates, "bishop"){

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

    Coordinates new_coordinates(getCoordinates().getX(), getCoordinates().getY());
    bool is_way_free = true;
    bool is_not_out_of_border = true;



    if (is_figure_white()){

        //  top right

        for(uint8_t i = 1; i < 8; i++) {
            if (is_way_free and is_not_out_of_border) {
                new_coordinates.setX(getCoordinates().getX() + i);
                new_coordinates.setY(getCoordinates().getY() + i);
                if (is_out_of_border(new_coordinates)) {
                    is_not_out_of_border = false;
                } else {
                    if (is_cell_busy_by_enemy_figure(new_coordinates, black_figures)){
                        add_move_to_possible_moves(new_coordinates);
                        is_way_free = false;
                    }
                    if (is_cell_busy_by_ally_figure(new_coordinates, white_figures)){
                        is_way_free = false;
                    }
                    add_move_to_possible_moves(new_coordinates);
                }
            }
        }

        //  top left
        new_coordinates.setX(getCoordinates().getX());
        new_coordinates.setY(getCoordinates().getY());
        is_way_free = true;
        is_not_out_of_border = true;

        for(uint8_t i = 1; i < 8; i++) {
            if (is_way_free and is_not_out_of_border) {
                new_coordinates.setX(getCoordinates().getX() - i);
                new_coordinates.setX(getCoordinates().getY() + i);
                if (is_out_of_border(new_coordinates)) {
                    is_not_out_of_border = false;
                } else {
                    if (is_cell_busy_by_enemy_figure(new_coordinates, black_figures)){
                        add_move_to_possible_moves(new_coordinates);
                        is_way_free = false;
                    }
                    if (is_cell_busy_by_ally_figure(new_coordinates, white_figures)){
                        is_way_free = false;
                    }
                    add_move_to_possible_moves(new_coordinates);
                }
            }
        }

        // bottom right
        new_coordinates.setX(getCoordinates().getX());
        new_coordinates.setY(getCoordinates().getY());
        is_way_free = true;
        is_not_out_of_border = true;

        for(uint8_t i = 1; i < 8; i++) {
            if (is_way_free and is_not_out_of_border) {
                new_coordinates.setX(getCoordinates().getX() + i);
                new_coordinates.setY(getCoordinates().getY() - i);
                if (is_out_of_border(new_coordinates)) {
                    is_not_out_of_border = false;
                } else {
                    if (is_cell_busy_by_enemy_figure(new_coordinates, black_figures)){
                        add_move_to_possible_moves(new_coordinates);
                        is_way_free = false;
                    }
                    if (is_cell_busy_by_ally_figure(new_coordinates, white_figures)){
                        is_way_free = false;
                    }
                    add_move_to_possible_moves(new_coordinates);
                }
            }
        }

        // Проверим по Y вниз
        new_coordinates.setX(getCoordinates().getX());
        new_coordinates.setY(getCoordinates().getY());
        is_way_free = true;
        is_not_out_of_border = true;

        for(uint8_t i = 1; i < 8; i++) {
            if (is_way_free and is_not_out_of_border) {
                new_coordinates.setY(getCoordinates().getY() - i);
                new_coordinates.setX(getCoordinates().getX() - i);
                if (is_out_of_border(new_coordinates)) {
                    is_not_out_of_border = false;
                } else {
                    if (is_cell_busy_by_enemy_figure(new_coordinates, black_figures)){
                        add_move_to_possible_moves(new_coordinates);
                        is_way_free = false;
                    }
                    if (is_cell_busy_by_ally_figure(new_coordinates, white_figures)){
                        is_way_free = false;
                    }
                    add_move_to_possible_moves(new_coordinates);
                }
            }
        }
    }

    if (is_figure_black()){

        //  Проверяем по X вправо

        for(uint8_t i = 1; i < 8; i++) {
            if (is_way_free and is_not_out_of_border) {
                new_coordinates.setX(getCoordinates().getX() + i);
                if (is_out_of_border(new_coordinates)) {
                    is_not_out_of_border = false;
                } else {
                    if (is_cell_busy_by_enemy_figure(new_coordinates, white_figures)){
                        add_move_to_possible_moves(new_coordinates);
                        is_way_free = false;
                    }
                    if (is_cell_busy_by_ally_figure(new_coordinates, black_figures)){
                        is_way_free = false;
                    }
                    add_move_to_possible_moves(new_coordinates);
                }
            }
        }

        // Проверим по X влево
        new_coordinates.setX(getCoordinates().getX());
        is_way_free = true;
        is_not_out_of_border = true;

        for(uint8_t i = 1; i < 8; i++) {
            if (is_way_free and is_not_out_of_border) {
                new_coordinates.setX(getCoordinates().getX() - i);
                if (is_out_of_border(new_coordinates)) {
                    is_not_out_of_border = false;
                } else {
                    if (is_cell_busy_by_enemy_figure(new_coordinates, white_figures)){
                        add_move_to_possible_moves(new_coordinates);
                        is_way_free = false;
                    }
                    if (is_cell_busy_by_ally_figure(new_coordinates, black_figures)){
                        is_way_free = false;
                    }
                    add_move_to_possible_moves(new_coordinates);
                }
            }
        }

        // Проверим по Y вверх
        new_coordinates.setX(getCoordinates().getX());
        new_coordinates.setX(getCoordinates().getY());
        is_way_free = true;
        is_not_out_of_border = true;

        for(uint8_t i = 1; i < 8; i++) {
            if (is_way_free and is_not_out_of_border) {
                new_coordinates.setX(getCoordinates().getY() + i);
                if (is_out_of_border(new_coordinates)) {
                    is_not_out_of_border = false;
                } else {
                    if (is_cell_busy_by_enemy_figure(new_coordinates, white_figures)){
                        add_move_to_possible_moves(new_coordinates);
                        is_way_free = false;
                    }
                    if (is_cell_busy_by_ally_figure(new_coordinates, black_figures)){
                        is_way_free = false;
                    }
                    add_move_to_possible_moves(new_coordinates);
                }
            }
        }

        // Проверим по Y вниз
        new_coordinates.setX(getCoordinates().getY());
        is_way_free = true;
        is_not_out_of_border = true;

        for(uint8_t i = 1; i < 8; i++) {
            if (is_way_free and is_not_out_of_border) {
                new_coordinates.setX(getCoordinates().getY() - i);
                if (is_out_of_border(new_coordinates)) {
                    is_not_out_of_border = false;
                } else {
                    if (is_cell_busy_by_enemy_figure(new_coordinates, white_figures)){
                        add_move_to_possible_moves(new_coordinates);
                        is_way_free = false;
                    }
                    if (is_cell_busy_by_ally_figure(new_coordinates, black_figures)){
                        is_way_free = false;
                    }
                    add_move_to_possible_moves(new_coordinates);
                }
            }
        }
    }

}



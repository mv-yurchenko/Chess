//
// Created by Max Yurchenko on 30.08.2018.
//

#include "Castle.h"

Castle::Castle(bool side, Coordinates coordinates) : Figure(side, coordinates, "castle"){

}

void Castle::calculate_available_moves() {

    Coordinates new_coordinates(getCoordinates().getX(), getCoordinates().getY());

    bool is_not_out_of_border = true;

    // Проверяем по X вправо
    for(int i = 1; i < 8; i++){
        new_coordinates.setX(getCoordinates().getX() + i);
        if(is_not_out_of_border){
            if (not is_out_of_border(new_coordinates)){
                add_move_to_available_moves(new_coordinates);
            } else{
                is_not_out_of_border = false;
            }
        }
    }

    // Проверяем по X влево
    new_coordinates.setX(getCoordinates().getX());
    is_not_out_of_border = true;

    for(int i = 1; i < 8; i++){
        new_coordinates.setX(getCoordinates().getX() - i);
        if(is_not_out_of_border){
            if (not is_out_of_border(new_coordinates)){
                add_move_to_available_moves(new_coordinates);
            } else{
                is_not_out_of_border = false;
            }
        }
    }

    new_coordinates.setX(getCoordinates().getX());

    // Проверяем по Y вверх
    new_coordinates.setY(getCoordinates().getY());
    is_not_out_of_border = true;

    for(int i = 1; i < 8; i++){
        new_coordinates.setY(getCoordinates().getY() + i);
        if(is_not_out_of_border){
            if (not is_out_of_border(new_coordinates)){
                add_move_to_available_moves(new_coordinates);
            } else{
                is_not_out_of_border = false;
            }
        }
    }

    // Проверяем по Y вних
    new_coordinates.setY(getCoordinates().getY());
    is_not_out_of_border = true;

    for(int i = 1; i < 8; i++){
        new_coordinates.setY(getCoordinates().getY() - i);
        if(is_not_out_of_border){
            if (not is_out_of_border(new_coordinates)){
                add_move_to_available_moves(new_coordinates);
            } else{
                is_not_out_of_border = false;
            }
        }
    }
}

void Castle::calculate_possible_moves(std::vector<Figure> white_figures, std::vector<Figure> black_figures) {

    //TODO: rework!

    Coordinates new_coordinates(getCoordinates().getX(), getCoordinates().getY());

    bool is_not_out_of_border = true;

    bool is_way_free = true;

    if (is_figure_white()) {

        // Проверяем по X вправо
        for (int i = 1; i < 8; i++) {
            new_coordinates.setX(getCoordinates().getX() + i);
            if (is_not_out_of_border and is_way_free) {
                if (not is_out_of_border(new_coordinates)) {
                    if (not is_cell_busy_by_enemy_figure(new_coordinates, black_figures)){
                        add_move_to_possible_moves(new_coordinates);
                    } else {
                        is_way_free = false;
                    }
                } else {
                    is_not_out_of_border = false;
                }
            }
        }

        // Проверяем по X влево
        new_coordinates.setX(getCoordinates().getX());
        is_not_out_of_border = true;
        is_way_free = true;

        for (int i = 1; i < 8; i++) {
            new_coordinates.setX(getCoordinates().getX() - i);
            if (is_not_out_of_border) {
                if (not is_out_of_border(new_coordinates)) {
                    if (not is_cell_busy_by_enemy_figure(new_coordinates, black_figures)){
                        add_move_to_possible_moves(new_coordinates);
                    }
                    else {
                        is_way_free = false;
                    }
                } else {
                    is_not_out_of_border = false;
                }
            }
        }

        // Проверяем по Y вверх
        new_coordinates.setY(getCoordinates().getY());
        is_not_out_of_border = true;
        is_way_free = true;

        for(int i = 1; i < 8; i++){
            new_coordinates.setY(getCoordinates().getY() + i);
            if(is_not_out_of_border){
                if (not is_out_of_border(new_coordinates)){
                    if (not is_cell_busy_by_enemy_figure(new_coordinates, black_figures)){
                        add_move_to_possible_moves(new_coordinates);
                    }
                    else {
                        is_way_free = false;
                    }
                } else{
                    is_not_out_of_border = false;
                }
            }
        }

        // Проверяем по Y вниз
        new_coordinates.setY(getCoordinates().getY());
        is_not_out_of_border = true;
        is_way_free = true;

        for(int i = 1; i < 8; i++){
            new_coordinates.setY(getCoordinates().getY() - i);
            if(is_not_out_of_border){
                if (not is_out_of_border(new_coordinates)){
                    if (not is_cell_busy_by_enemy_figure(new_coordinates, black_figures)){
                        add_move_to_possible_moves(new_coordinates);
                    }
                    else {
                        is_way_free = false;
                    }
                } else{
                    is_not_out_of_border = false;
                }
            }
        }
    }

    if (is_figure_black()) {
        new_coordinates.setX(getCoordinates().getX());
        is_not_out_of_border = true;
        is_way_free = true;

        // Проверяем по X вправо
        for (int i = 1; i < 8; i++) {
            new_coordinates.setX(getCoordinates().getX() + i);
            if (is_not_out_of_border) {
                if (not is_out_of_border(new_coordinates)) {
                    if (not is_cell_busy_by_enemy_figure(new_coordinates, white_figures)){
                        add_move_to_possible_moves(new_coordinates);
                    }
                    else {
                        is_way_free = false;
                    }
                } else {
                    is_not_out_of_border = false;
                }
            }
        }

        // Проверяем по X влева
        new_coordinates.setX(getCoordinates().getX());
        is_not_out_of_border = true;
        is_way_free = true;

        for (int i = 1; i < 8; i++) {
            new_coordinates.setX(getCoordinates().getX() - i);
            if (is_not_out_of_border) {
                if (not is_out_of_border(new_coordinates)) {
                    if (not is_cell_busy_by_enemy_figure(new_coordinates, white_figures)){
                        add_move_to_possible_moves(new_coordinates);
                    }
                    else {
                        is_way_free = false;
                    }
                } else {
                    is_not_out_of_border = false;
                }
            }
        }

        // Проверяем по Y вверх
        new_coordinates.setY(getCoordinates().getY());
        is_not_out_of_border = true;
        is_way_free = true;

        for(int i = 1; i < 8; i++){
            new_coordinates.setY(getCoordinates().getY() + i);
            if(is_not_out_of_border){
                if (not is_out_of_border(new_coordinates)){
                    if (not is_cell_busy_by_enemy_figure(new_coordinates, white_figures)){
                        add_move_to_possible_moves(new_coordinates);
                    }else {
                        is_way_free = false;
                    }
                } else{
                    is_not_out_of_border = false;
                }
            }
        }

        // Проверяем по Y вниз
        new_coordinates.setY(getCoordinates().getY());
        is_not_out_of_border = true;
        is_way_free = true;

        for(int i = 1; i < 8; i++){
            new_coordinates.setY(getCoordinates().getY() - i);
            if(is_not_out_of_border){
                if (not is_out_of_border(new_coordinates)){
                    if (not is_cell_busy_by_enemy_figure(new_coordinates, white_figures)){
                        add_move_to_possible_moves(new_coordinates);
                    }else {
                        is_way_free = false;
                    }
                } else{
                    is_not_out_of_border = false;
                }
            }
        }
    }
}


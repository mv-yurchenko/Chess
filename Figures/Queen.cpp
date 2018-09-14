//
// Created by Max Yurchenko on 03.09.2018.
//

#include "Queen.h"

Queen::Queen(bool side, Coordinates coordinates) : Figure(side, coordinates, "queen", 9){
    if (side){
        setDesk_name("W_Q");
    } else{
        setDesk_name("B_Q");
    }
}

Queen::Queen() {

}

void Queen::calculate_available_moves() {
    //////////////////////////////////////////
    //  Bishop + Castle = Queen
    //////////////////////////////////////////

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

void Queen::calculate_possible_moves(std::vector<Figure> white_figures, std::vector<Figure> black_figures) {
    //  top right

    calculate_bishop_one_direction(white_figures, black_figures, true, true);

    //  top left

    calculate_bishop_one_direction(white_figures, black_figures, true, false);

    // bottom right

    calculate_bishop_one_direction(white_figures, black_figures, false, true);

    // bottom left

    calculate_bishop_one_direction(white_figures, black_figures, false, false);

    calculate_castle_one_direction(white_figures, black_figures, true, false, false, false);

    calculate_castle_one_direction(white_figures, black_figures, false, true, false, false);

    calculate_castle_one_direction(white_figures, black_figures, false, false, false, true);

    calculate_castle_one_direction(white_figures, black_figures, false, false, false, true);
}

void Queen::calculate_bishop_one_direction(const std::vector<Figure> &white_figures,
                                           const std::vector<Figure> &black_figures, bool increment_up,
                                           bool increment_right) {

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

void Queen::calculate_castle_one_direction(const std::vector<Figure> &white_figures,
                                           const std::vector<Figure> &black_figures, bool increment_up,
                                           bool increment_down, bool increment_right, bool increment_left) {

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
            if (increment_left)
                new_coordinates.setX(getCoordinates().getX() - i);
            if (increment_down)
                new_coordinates.setY(getCoordinates().getY() + i);
            if (increment_up)
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

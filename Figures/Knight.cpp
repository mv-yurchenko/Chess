//
// Created by Max Yurchenko on 29.08.2018.
//

#include "Knight.h"

Knight::Knight(bool side, Coordinates coordinates) {
    this->setName("Knight");
    this->setSide(side);
    this->setCoordinates(coordinates);
    this->setValue(3);
    if (side){
        setDesk_name("W_Kn");
    } else{
        setDesk_name("B_Kn");
    }
}

Knight::Knight() {

}

void Knight::calculate_possible_moves(std::vector<Figure> white_figures, std::vector<Figure> black_figures) {
    std::vector<Figure> ally_figures;
    std::vector<Figure> enemy_figures;
    if (is_figure_white()) {
        ally_figures = white_figures;
        enemy_figures = black_figures;
    } else{
        ally_figures = black_figures;
        enemy_figures = white_figures;
    }

    calculate_move_possibility_2_right_1_down(ally_figures);
    calculate_move_possibility_2_right_1_up(ally_figures);
    calculate_move_possibility_2_up_1_right(ally_figures);
    calculate_move_possibility_2_up_1_left(ally_figures);
    calculate_move_possibility_2_left_1_up(ally_figures);
    calculate_move_possibility_2_left_1_down(ally_figures);
    calculate_move_possibility_2_down_1_left(ally_figures);
    calculate_move_possibility_2_down_1_right(ally_figures);
}

void Knight::calculate_move_possibility_2_down_1_right(std::vector<Figure> ally_figures) {
    Coordinates new_coordinates(getCoordinates().getX() + 1, getCoordinates().getY() - 2);
    if (not is_out_of_border(new_coordinates) and not is_cell_busy_by_ally_figure(new_coordinates, ally_figures)){
        add_move_to_possible_moves(new_coordinates);
    }
}

void Knight::calculate_move_possibility_2_down_1_left(std::vector<Figure> ally_figures) {
    Coordinates new_coordinates(getCoordinates().getX() - 1, getCoordinates().getY() - 2);
    if (not is_out_of_border(new_coordinates) and not is_cell_busy_by_ally_figure(new_coordinates, ally_figures)){
        add_move_to_possible_moves(new_coordinates);
    }
}

void Knight::calculate_move_possibility_2_left_1_down(std::vector<Figure> ally_figures) {
    Coordinates new_coordinates(getCoordinates().getX() - 2, getCoordinates().getY() - 1);
    if (not is_out_of_border(new_coordinates) and not is_cell_busy_by_ally_figure(new_coordinates, ally_figures)){
        add_move_to_possible_moves(new_coordinates);
    }
}

void Knight::calculate_move_possibility_2_left_1_up(std::vector<Figure> ally_figures) {
    Coordinates new_coordinates(getCoordinates().getX() - 2, getCoordinates().getY() + 1);
    if (not is_out_of_border(new_coordinates) and not is_cell_busy_by_ally_figure(new_coordinates, ally_figures)){
        add_move_to_possible_moves(new_coordinates);
    }
}

void Knight::calculate_move_possibility_2_up_1_left(std::vector<Figure> ally_figures) {
    Coordinates new_coordinates(getCoordinates().getX() - 1, getCoordinates().getY() + 2);
    if (not is_out_of_border(new_coordinates) and not is_cell_busy_by_ally_figure(new_coordinates, ally_figures)){
        add_move_to_possible_moves(new_coordinates);
    }
}

void Knight::calculate_move_possibility_2_up_1_right(std::vector<Figure> ally_figures) {
    Coordinates new_coordinates(getCoordinates().getX() + 1, getCoordinates().getY() + 2);
    if (not is_out_of_border(new_coordinates) and not is_cell_busy_by_ally_figure(new_coordinates, ally_figures)){
        add_move_to_possible_moves(new_coordinates);
    }
}

void Knight::calculate_move_possibility_2_right_1_up(std::vector<Figure> ally_figures) {
    Coordinates new_coordinates(getCoordinates().getX() + 2, getCoordinates().getY() + 1);
    if (not is_out_of_border(new_coordinates) and not is_cell_busy_by_ally_figure(new_coordinates, ally_figures)){
        add_move_to_possible_moves(new_coordinates);
    }
}

void Knight::calculate_move_possibility_2_right_1_down(std::vector<Figure> ally_figures) {
    Coordinates new_coordinates(getCoordinates().getX() + 2, getCoordinates().getY() -1);
    if (not is_out_of_border(new_coordinates) and not is_cell_busy_by_ally_figure(new_coordinates, ally_figures)){
        add_move_to_possible_moves(new_coordinates);
    }
}



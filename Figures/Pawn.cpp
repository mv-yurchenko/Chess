//
// Created by Max Yurchenko on 27.08.2018.
//

#include "Pawn.h"

Pawn::Pawn(bool side, Coordinates coordinates, int num){
    this->setName("Pawn" + std::to_string(num));
    this->setSide(side);
    this->setCoordinates(coordinates);
    this->setValue(1);
    if (side){
        setDesk_name("W_P");
    } else{
        setDesk_name("B_P");
    }
}

Pawn::Pawn() {

}

void Pawn::calculate_possible_moves(std::vector<Figure> white_figures, std::vector<Figure> black_figures) {
    calculate_move_forward_possibility(white_figures, black_figures);

    calculate_two_cell_move_possibility(white_figures, black_figures);

    calculate_diagonal_move_possibility(white_figures, black_figures);
}

void Pawn::calculate_two_cell_move_possibility(std::vector<Figure> white_figures, std::vector<Figure> black_figures) {
    bool two_cell_move_possible = true;
    Coordinates new_coordinates{};
    new_coordinates.setX(getCoordinates().getX());

    if (is_figure_white()){
        if (getCoordinates().getY() != 1){
            two_cell_move_possible = false;
        } else{
            // Первая клетка
            new_coordinates.setY(getCoordinates().getY() + 1);
            if (not is_out_of_border(new_coordinates) and
                is_cell_empty(new_coordinates, white_figures, black_figures)) {
                new_coordinates.setY(getCoordinates().getY() + 2);
                if(not is_out_of_border(new_coordinates) and
                   is_cell_empty(new_coordinates, white_figures, black_figures)) {
                    add_move_to_possible_moves(new_coordinates);
                }
            }
        }
    }else{
        if (getCoordinates().getY() != 6){
            two_cell_move_possible = false;
        } else{
            // Первая клетка
            new_coordinates.setY(getCoordinates().getY() - 1);
            if (not is_out_of_border(new_coordinates) and
                is_cell_empty(new_coordinates, white_figures, black_figures)) {
                new_coordinates.setY(getCoordinates().getY() - 2);
                if (not is_out_of_border(new_coordinates) and
                    is_cell_empty(new_coordinates, white_figures, black_figures)) {
                    add_move_to_possible_moves(new_coordinates);
                }
            }
        }
    }
}

void Pawn::calculate_move_forward_possibility(std::vector<Figure> white_figures, std::vector<Figure> black_figures) {
    Coordinates new_coordinates;
    new_coordinates.setX(getCoordinates().getX());
    if (is_figure_white()){
        new_coordinates.setY(getCoordinates().getY() + 1);
    }
    else{
        new_coordinates.setY(new_coordinates.getY() - 1);
    }

    if (not is_out_of_border(new_coordinates) and
        not is_cell_busy_by_ally_figure(new_coordinates, white_figures) and
        not is_cell_busy_by_ally_figure(new_coordinates, black_figures)){
        add_move_to_possible_moves(new_coordinates);
    }
}

void Pawn::calculate_diagonal_move_possibility(std::vector<Figure> white_figures, std::vector<Figure> black_figures) {
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

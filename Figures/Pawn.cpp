//
// Created by Max Yurchenko on 27.08.2018.
//

#include "Pawn.h"

Pawn::Pawn(bool side, Coordinates coordinates, uint8_t num){
    this->setName("Pawn" + std::to_string(num));
    this->setSide(side);
    this->setCoordinates(coordinates);
    if (side){
        setDesk_name("W_P");
    } else{
        setDesk_name("B_P");
    }
}

Pawn::Pawn() {

}

void Pawn::calculate_possible_moves(std::vector<Figure> white_figures, std::vector<Figure> black_figures) {
    // TODO: добавить 1 ход на 2 клетки
    for (auto move : getAvailable_moves()) {
        if (is_figure_white()) {
            for (const auto &black_figure : black_figures) {
                // Проверка на съедение
                if (is_coordinates_same(black_figure.getCoordinates(), move.getNew_coordinates())) {
                    if (getCoordinates().getX() != move.getNew_coordinates().getX()) {
                        add_move_to_possible_moves(move.getNew_coordinates());
                    }
                }
            }
        }
        if (is_figure_black()){
            {
                for (const auto &white_figure : white_figures) {
                    // Проверка на съедение
                    if (is_coordinates_same(white_figure.getCoordinates(), move.getNew_coordinates())) {
                        if (getCoordinates().getX() != move.getNew_coordinates().getX()) {
                            add_move_to_possible_moves(move.getNew_coordinates());
                        }
                    }
                }
            }
        }
    }
    // Ход вперед
    if (is_figure_white()) {
        Coordinates move_forward_coord(getCoordinates().getX(), getCoordinates().getY() + 1);
        bool move_forward_possible = true;
        for (const auto &black_figure : black_figures) {
            if (is_coordinates_same(black_figure.getCoordinates(), move_forward_coord)) {
                move_forward_possible = false;
            }
        }
        for (const auto &white_figure : white_figures) {
            if (is_coordinates_same(white_figure.getCoordinates(), move_forward_coord)) {
                move_forward_possible = false;
            }
        }
        if (move_forward_possible) {
            add_move_to_possible_moves(move_forward_coord);
        }
    }
    if (is_figure_black()){
        Coordinates move_forward_coord(getCoordinates().getX(), getCoordinates().getY() - 1);
        bool move_forward_possible = true;
        for (const auto &black_figure : black_figures) {
            if (is_coordinates_same(black_figure.getCoordinates(), move_forward_coord)) {
                move_forward_possible = false;
            }
        }
        for (const auto &white_figure : white_figures) {
            if (is_coordinates_same(white_figure.getCoordinates(), move_forward_coord)) {
                move_forward_possible = false;
            }
        }
        if (move_forward_possible) {
            add_move_to_possible_moves(move_forward_coord);
        }
    }

    // Первый ход на 2 клетки

    if (is_figure_white() and getCoordinates().getY() == 1){
        bool two_cell_move_possible = true;
        for(int i = 1; i<=2; i++){
            Coordinates possible_move (getCoordinates().getX(), getCoordinates().getY() + i);
            for (const auto &black_figure : black_figures){
                if (black_figure.getCoordinates().getX() == possible_move.getX() and
                    black_figure.getCoordinates().getY() == possible_move.getY()){
                    two_cell_move_possible = false;
                }
            }
        }
        if (two_cell_move_possible){
            Coordinates new_coordinates(getCoordinates().getX(), getCoordinates().getY() + 2);
            add_move_to_possible_moves(new_coordinates);
        }
    }

    if (is_figure_black() and getCoordinates().getY() == 6){
        bool two_cell_move_possible = true;
        for(int i = 1; i<=2; i++){
            Coordinates possible_move (getCoordinates().getX(), getCoordinates().getY() - i);
            for (const auto &white_figure : white_figures){
                if (white_figure.getCoordinates().getX() == possible_move.getX() and
                    white_figure.getCoordinates().getY() == possible_move.getY()){
                    two_cell_move_possible = false;
                }
            }
        }
        if (two_cell_move_possible){
            Coordinates new_coordinates(getCoordinates().getX(), getCoordinates().getY() - 2);
            add_move_to_possible_moves(new_coordinates);
        }
    }
}

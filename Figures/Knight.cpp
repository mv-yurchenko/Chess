//
// Created by Max Yurchenko on 29.08.2018.
//

#include "Knight.h"

Knight::Knight(bool side, Coordinates coordinates) {
    this->setName("Knight");
    this->setSide(side);
    this->setCoordinates(coordinates);
}

Knight::Knight() {

}

void Knight::calculate_available_moves() {

    Coordinates current_coordinates = getCoordinates();
    Coordinates new_coordinates;
    // Заглушка для инициализации, по дефолту 2 аргумент - новые координаты
    Move possible_move(current_coordinates, current_coordinates);

    //////////////////////////////////////////
    //  Перебираем все ходы коня
    /////////////////////////////////////////

    new_coordinates.setX(current_coordinates.getX() + 1);
    new_coordinates.setY(current_coordinates.getY() + 2);
    if (not is_out_of_border(new_coordinates)){
        add_move_to_available_moves(new_coordinates);
    }

    new_coordinates.setX(current_coordinates.getX() - 1);
    new_coordinates.setY(current_coordinates.getY() + 2);
    if (not is_out_of_border(new_coordinates)){
        add_move_to_available_moves(new_coordinates);
    }

    new_coordinates.setX(current_coordinates.getX() - 2);
    new_coordinates.setY(current_coordinates.getY() + 1);
    if (not is_out_of_border(new_coordinates)){
        add_move_to_available_moves(new_coordinates);
    }

    new_coordinates.setX(current_coordinates.getX() - 2);
    new_coordinates.setY(current_coordinates.getY() - 1);
    if (not is_out_of_border(new_coordinates)){
        add_move_to_available_moves(new_coordinates);
    }

    new_coordinates.setX(current_coordinates.getX() - 1);
    new_coordinates.setY(current_coordinates.getY() - 2);
    if (not is_out_of_border(new_coordinates)){
        add_move_to_available_moves(new_coordinates);
    }

    new_coordinates.setX(current_coordinates.getX() + 1);
    new_coordinates.setY(current_coordinates.getY() - 2);
    if (not is_out_of_border(new_coordinates)){
        add_move_to_available_moves(new_coordinates);
    }

    new_coordinates.setX(current_coordinates.getX() + 2);
    new_coordinates.setY(current_coordinates.getY() - 1);
    if (not is_out_of_border(new_coordinates)){
        add_move_to_available_moves(new_coordinates);
    }

    new_coordinates.setX(current_coordinates.getX() + 2);
    new_coordinates.setY(current_coordinates.getY() + 1);
    if (not is_out_of_border(new_coordinates)){
        add_move_to_available_moves(new_coordinates);
    }
}

void Knight::calculate_possible_moves(std::vector<Figure> white_figures, std::vector<Figure> black_figures) {
    for (auto available_move : getAvailable_moves()){
        // Ход возможен, если клетка не занята фигурой того же цвета
        bool move_possible = true;

        if (is_figure_white()){
            for (const auto &white_figure : white_figures){
                if (is_coordinates_same(white_figure.getCoordinates(), available_move.getNew_coordinates())){
                    move_possible = false;
                }
            }
        }

        if (is_figure_black()){
            for (const auto &black_figure : white_figures){
                if (is_coordinates_same(black_figure.getCoordinates(), available_move.getNew_coordinates())){
                    move_possible = false;
                }
            }
        }

        if (move_possible){
            add_move_to_possible_moves(available_move.getNew_coordinates());
        }
    }
}

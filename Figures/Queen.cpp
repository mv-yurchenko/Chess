//
// Created by Max Yurchenko on 03.09.2018.
//

#include "Queen.h"

Queen::Queen(bool side, Coordinates coordinates) : Figure(side, coordinates, "queen"){

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

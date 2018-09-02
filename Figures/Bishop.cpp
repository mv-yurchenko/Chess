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

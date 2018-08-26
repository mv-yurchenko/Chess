//
// Created by Max Yurchenko on 25.08.2018.
//

#include "King.h"

void King::calculate_available_moves() {
    Coordinates current_coordinates = this->getCoordinates();
    std::vector <Coordinates> vector_of_new_coordinates;
    Coordinates new_pos;

    new_pos.setX(current_coordinates.getX());
    new_pos.setY(current_coordinates.getY() + 1);
    if (not is_out_of_border(new_pos)) {
        vector_of_new_coordinates.push_back(new_pos);
    }
    new_pos.setX(current_coordinates.getX() + 1);
    new_pos.setY(current_coordinates.getY() + 1);
    if (not is_out_of_border(new_pos)) {
        vector_of_new_coordinates.push_back(new_pos);
    }
    new_pos.setX(current_coordinates.getX() + 1);
    new_pos.setY(current_coordinates.getY());
    if (not is_out_of_border(new_pos)) {
        vector_of_new_coordinates.push_back(new_pos);
    }
    new_pos.setX(current_coordinates.getX() + 1);
    new_pos.setY(current_coordinates.getY() - 1);
    if (not is_out_of_border(new_pos)) {
        vector_of_new_coordinates.push_back(new_pos);
    }
    new_pos.setX(current_coordinates.getX());
    new_pos.setY(current_coordinates.getY() - 1);
    if (not is_out_of_border(new_pos)) {
        vector_of_new_coordinates.push_back(new_pos);
    }
    new_pos.setX(current_coordinates.getX() - 1);
    new_pos.setY(current_coordinates.getY() - 1);
    if (not is_out_of_border(new_pos)) {
        vector_of_new_coordinates.push_back(new_pos);
    }
    new_pos.setX(current_coordinates.getX() - 1);
    new_pos.setY(current_coordinates.getY());
    if (not is_out_of_border(new_pos)) {
        vector_of_new_coordinates.push_back(new_pos);
    }
    new_pos.setX(current_coordinates.getX() - 1);
    new_pos.setY(current_coordinates.getY() + 1);
    if (not is_out_of_border(new_pos)) {
        vector_of_new_coordinates.push_back(new_pos);
    }
    for (auto new_coordinates : vector_of_new_coordinates){
        this->add_move_to_available_moves(new_coordinates);
    }
    std::cout<<std::endl;
}

King::King() {

}

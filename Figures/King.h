//
// Created by Max Yurchenko on 25.08.2018.
//

#include "Figure.h"

#ifndef CHESS_KING_H
#define CHESS_KING_H


class King : public Figure{
public:
    void calculate_available_moves(){
        Coordinates current_coordinates = this->getCoordinates();
        std::vector <Coordinates> vector_of_new_coordinates;
        Coordinates new_pos;

        new_pos.setX(current_coordinates.getX());
        new_pos.setY(current_coordinates.getY() + 1);
        vector_of_new_coordinates.push_back(new_pos);

        new_pos.setX(current_coordinates.getX() + 1);
        new_pos.setY(current_coordinates.getY() + 1);
        vector_of_new_coordinates.push_back(new_pos);

        new_pos.setX(current_coordinates.getX() + 1);
        new_pos.setY(current_coordinates.getY());
        vector_of_new_coordinates.push_back(new_pos);

        new_pos.setX(current_coordinates.getX() + 1);
        new_pos.setY(current_coordinates.getY() - 1);
        vector_of_new_coordinates.push_back(new_pos);

        new_pos.setX(current_coordinates.getX());
        new_pos.setY(current_coordinates.getY() - 1);
        vector_of_new_coordinates.push_back(new_pos);

        new_pos.setX(current_coordinates.getX() - 1);
        new_pos.setY(current_coordinates.getY() - 1);
        vector_of_new_coordinates.push_back(new_pos);

        new_pos.setX(current_coordinates.getX() - 1);
        new_pos.setY(current_coordinates.getY());
        vector_of_new_coordinates.push_back(new_pos);

        new_pos.setX(current_coordinates.getX() - 1);
        new_pos.setY(current_coordinates.getY() + 1);
        vector_of_new_coordinates.push_back(new_pos);

        for (auto new_coordinates : vector_of_new_coordinates){
            this->add_move_to_available_moves(new_coordinates);
        }
        std::cout<<std::endl;
    }
};


#endif //CHESS_KING_H

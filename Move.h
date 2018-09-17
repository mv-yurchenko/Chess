//
// Created by Max Yurchenko on 25.08.2018.
//

#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H

#include "Coordinates.h"

class Move {
    Coordinates old_coordinates;
    Coordinates new_coordinates;
public:
    Move(const Coordinates &old_coordinates, const Coordinates &new_coordinates);

    Move();

    void setOld_coordinates(const Coordinates &old_coordinates);

    void setNew_coordinates(const Coordinates &new_coordinates);

    const Coordinates &getOld_coordinates() const;

    const Coordinates &getNew_coordinates() const;
};


#endif //CHESS_MOVE_H

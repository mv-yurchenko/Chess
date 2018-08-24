//
// Created by Max Yurchenko on 25.08.2018.
//

#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H

#include "Coordinates.h"

class Move {
    Coordinates old_coordinates;
public:
    const Coordinates &getOld_coordinates() const;

    const Coordinates &getNew_coordinates() const;

private:
    Coordinates new_coordinates;
public:
    bool if_move_possible();

    void setOld_coordinates(const Coordinates &old_coordinates);

    void setNew_coordinates(const Coordinates &new_coordinates);
};


#endif //CHESS_MOVE_H

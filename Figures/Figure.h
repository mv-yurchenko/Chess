//
// Created by Max Yurchenko on 24.08.2018.
//

#ifndef CHESS_FIGURE_H
#define CHESS_FIGURE_H

#include "../Coordinates.h"
#include "../Move.h"
#include <iostream>
#include <vector>
#include <string>

class Figure {
    bool side;
    Coordinates coordinates;
    std::vector <Move> available_moves;
    std::vector <Move> possible_moves;
    std::string name;
public:
    void move_figure();
};


#endif //CHESS_FIGURE_H

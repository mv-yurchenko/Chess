//
// Created by Max Yurchenko on 25.08.2018.
//

#ifndef CHESS_DESK_H
#define CHESS_DESK_H

#include "Figures/Figure.h"
#include "Figures/King.h"

class Desk{
    Figure** desk;
public:
    Figure **getDesk() const {
        return desk;
    }

private:
    Figure* white_figures[16];
    Figure* black_figures[16];
public:
    Desk();
};


#endif //CHESS_DESK_H

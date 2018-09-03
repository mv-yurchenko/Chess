//
// Created by Max Yurchenko on 03.09.2018.
//

#ifndef CHESS_DESK_H
#define CHESS_DESK_H


#include "Figures/Figure.h"
#include "Figures/King.h"
#include "Figures/Pawn.h"
#include "Figures/Knight.h"
#include "Figures/Castle.h"
#include "Figures/Bishop.h"
#include "Figures/Queen.h"

class Desk {
    Figure *desk[8][8];
public:

    Desk();

    Figure *get_figure_by_coordinates(int x, int y);

    void initiatilize_desk();

    void print_desk(){
        //////////////////////////////////////////
        //  Дебаг функция
        /////////////////////////////////////////
        for (int i = 0; i < 8; i ++){
            for (int j = 0; j < 8; j ++) {
                Figure *figure = desk[j][i];
                std::cout << desk[j][i]->getName() << std::endl;
                std::cout << "-------------------------" << std::endl;
            }
        }
    }
};


#endif //CHESS_DESK_H

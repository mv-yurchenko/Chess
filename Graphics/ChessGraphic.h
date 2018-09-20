//
// Created by Max Yurchenko on 08.09.2018.
//

#ifndef CHESS_CHESSGRAPHIC_H
#define CHESS_CHESSGRAPHIC_H

#include "../Desk.h"

class ChessGraphic{
    char top_letters[8]={'A','B','C','D','E','F','G','H'};
public:
    void print_letters();

    void print_horizontal_separate_lane();

    void print_desk(Desk *desk);

    void print_figure_on_cell(Figure *figure);

    void clear_desk();
};


#endif //CHESS_CHESSGRAPHIC_H

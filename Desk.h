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

    std::vector<Figure> white_figures;
    std::vector<Figure> black_figures;
public:
    const std::vector<Figure> &getWhite_figures() const;

    const std::vector<Figure> &getBlack_figures() const;


public:

    Desk();

    Figure *get_figure_by_coordinates(int x, int y);

    void initialize_desk();

    void print_desk();

    bool move_figure(Coordinates old_coordinates, Coordinates new_coordinates);

    bool is_move_possible(Figure figure, Coordinates new_coordinates);

    void initialize_possible_moves();

    void reinitialize_white_black_figures();

    Figure *get_figure_by_coordinates(Coordinates coordinates);
};


#endif //CHESS_DESK_H

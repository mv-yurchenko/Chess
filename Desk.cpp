//
// Created by Max Yurchenko on 25.08.2018.
//

#include "Desk.h"

Desk::Desk() {
    //////////////////////////////////////////
    //  Выделяем память под каждую клетку
    /////////////////////////////////////////

    desk = new Figure *[8];
    for (int i = 0; i < 8; i++){
        desk[i] = new Figure[8];
    }
    //////////////////////////////////////////
    //  Инициализация фигур
    /////////////////////////////////////////

    // Белый король
    Coordinates w_king_coord(4, 0);
    King *white_king = new King(true, w_king_coord);
    white_figures[0] = white_king;
    desk[0][4] = *white_king;

    // Черный король
    Coordinates b_king_coord(4, 0);
    King *black_king = new King(false, w_king_coord);
    black_figures[0] = black_king;
    desk[7][4] = *black_king;

}

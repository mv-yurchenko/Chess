//
// Created by Max Yurchenko on 03.09.2018.
//

#include "Desk.h"


Desk::Desk() {
    for (int i=0; i<8;i++)
        for(int j=0;j<8; j++) {
            {
                desk[i][j] = new Figure;
            }
        }
}

Figure *Desk::get_figure_by_coordinates(int x, int y) {
    return desk[x][y];
}

void Desk::initiatilize_desk() {

    // White castles
    Coordinates w_castle1_coordinates(0, 0);
    Coordinates w_castle2_coordinates(7, 0);

    Castle w_castle1(true, w_castle1_coordinates);
    Castle w_castle2(true, w_castle2_coordinates);

    desk[0][0] = &w_castle1;
    desk[7][0] = &w_castle2;

    // Black castles
    Coordinates b_castle1_coordinates(0, 7);
    Coordinates b_castle2_coordinates(7, 7);

    Castle b_castle1(true, b_castle1_coordinates);
    Castle b_castle2(true, b_castle2_coordinates);

    desk[0][7] = &b_castle1;
    desk[7][7] = &b_castle2;

}

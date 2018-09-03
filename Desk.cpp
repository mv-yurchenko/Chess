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

    desk[w_castle1_coordinates.getX()][w_castle1_coordinates.getY()] = &w_castle1;
    desk[w_castle2_coordinates.getX()][w_castle2_coordinates.getY()] = &w_castle2;

    // Black castles
    Coordinates b_castle1_coordinates(0, 7);
    Coordinates b_castle2_coordinates(7, 7);

    Castle b_castle1(false, b_castle1_coordinates);
    Castle b_castle2(false, b_castle2_coordinates);

    desk[b_castle1_coordinates.getX()][b_castle1_coordinates.getY()] = &b_castle1;
    desk[b_castle2_coordinates.getY()][b_castle2_coordinates.getY()] = &b_castle2;

    // White Knights
    Coordinates w_knight1_coordinates(1, 0);
    Coordinates w_knight2_coordinates(6, 0);

    Knight w_knight1(true, w_knight1_coordinates);
    Knight w_knight2(true, w_knight2_coordinates);

    desk[w_knight1_coordinates.getX()][w_knight1_coordinates.getY()] = &w_knight1;
    desk[w_knight2_coordinates.getX()][w_knight2_coordinates.getY()] = &w_knight2;

    // Black Knights
    Coordinates b_knight1_coordinates(1, 7);
    Coordinates b_knight2_coordinates(6, 7);

    Knight b_knight1(false, w_knight1_coordinates);
    Knight b_knight2(false, w_knight2_coordinates);

    desk[b_knight1_coordinates.getX()][b_knight1_coordinates.getY()] = &b_knight1;
    desk[b_knight2_coordinates.getX()][b_knight2_coordinates.getY()] = &b_knight2;

    // White Bishops

    Coordinates w_bishop1_coordinates(2, 0);
    Coordinates w_bishop2_coordinates(5, 0);

    Bishop w_bishop1(true, w_bishop1_coordinates);
    Bishop w_bishop2(true, w_bishop2_coordinates);

    desk[w_bishop1_coordinates.getX()][w_bishop1_coordinates.getY()] = &w_bishop1;
    desk[w_bishop2_coordinates.getX()][w_bishop2_coordinates.getY()] = &w_bishop2;

    // Black Bishops

    Coordinates b_bishop1_coordinates(2, 0);
    Coordinates b_bishop2_coordinates(5, 0);

    Bishop b_bishop1(false, b_bishop1_coordinates);
    Bishop b_bishop2(false, b_bishop2_coordinates);

    desk[b_bishop1_coordinates.getX()][b_bishop1_coordinates.getY()] = &b_bishop1;
    desk[b_bishop2_coordinates.getX()][b_bishop2_coordinates.getY()] = &b_bishop2;

    // White King && Queen

    Coordinates w_queen_coordinates(3, 0);
    Coordinates w_King_coordinates(4, 0);

    Queen w_queen(true, w_queen_coordinates);
    King w_king(true, w_King_coordinates);

    desk[w_queen_coordinates.getX()][w_queen_coordinates.getY()] = &w_queen;
    desk[w_King_coordinates.getX()][w_King_coordinates.getY()] = &w_king;

    // Black King && Queen

    Coordinates b_queen_coordinates(3, 7);
    Coordinates b_King_coordinates(4, 7);

    Queen b_queen(false, b_queen_coordinates);
    King b_king(false, b_King_coordinates);

    desk[b_queen_coordinates.getX()][b_queen_coordinates.getY()] = &b_queen;
    desk[b_King_coordinates.getX()][b_King_coordinates.getY()] = &b_king;

}

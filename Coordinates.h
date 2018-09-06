//
// Created by Max Yurchenko on 24.08.2018.
//

#ifndef CHESS_COORDINATES_H
#define CHESS_COORDINATES_H


class Coordinates {
    int x,y;
public:
    int getX() const;

    int getY() const;

    Coordinates(int x, int y);

    Coordinates();

    void setX(int x);

    void setY(int y);

    bool operator== (const Coordinates& coord_1);

};


#endif //CHESS_COORDINATES_H

//
// Created by Max Yurchenko on 24.08.2018.
//

#ifndef CHESS_FIGURE_H
#define CHESS_FIGURE_H

#include "../Move.h"
#include <iostream>
#include <vector>
#include <string>


// TODO: Сделать абстрактным
class Figure  {
    bool side;
    Coordinates coordinates;
public:
    void setCoordinates(const Coordinates &coordinates);

private:
    std::vector <Move> available_moves;
    std::vector <Move> possible_moves;
    std::string name;
public:
    Figure(bool side, const Coordinates &coordinates, const char *name);

    Figure();

    void calculate_possible_moves();

    void calculate_available_moves();

    void move_figure();

    bool isSide() const;

    const Coordinates &getCoordinates() const;

    const std::vector<Move> &getAvailable_moves() const;

    const std::vector<Move> &getPossible_moves() const;

    const std::string &getName() const;

    bool is_out_of_border(Coordinates coordinates);

    void add_move_to_available_moves(Coordinates new_coordinates);
};

#endif //CHESS_FIGURE_H
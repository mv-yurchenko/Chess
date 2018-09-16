//
// Created by Max Yurchenko on 24.08.2018.
//

// TODO: Удалить available_moves

#ifndef CHESS_FIGURE_H
#define CHESS_FIGURE_H

#include "../Move.h"
#include <iostream>
#include <vector>
#include <string>

class Figure  {
    bool side;
    int value;
public:
    void setValue(int value);

private:
    Coordinates coordinates;
    std::vector <Move> available_moves;
    std::vector <Move> possible_moves;
    std::string name;
    std::string desk_name;
public:
    const std::string &getDesk_name() const;

public:
    void setDesk_name(const char *desk_name);

private:
    bool is_dead = false;
public:
    void setName(const std::string &name);

    void setCoordinates(const Coordinates &coordinates);

    Figure(bool side, const Coordinates &coordinates, const char *name, int value);

    Figure(bool side, Coordinates coordinates);

    Figure();

    virtual void calculate_possible_moves(std::vector<Figure> white_figures ,std::vector<Figure> black_figures );

    const Coordinates &getCoordinates() const;

    const std::vector<Move> &getAvailable_moves() const;

    const std::vector<Move> &getPossible_moves() const;

    const std::string &getName() const;

    bool is_out_of_border(Coordinates coordinates);

    void add_move_to_available_moves(Coordinates new_coordinates);

    void add_move_to_possible_moves(Coordinates new_coordinates);

    bool is_coordinates_same(Coordinates coordinates1, Coordinates coordinates2);

    bool is_figure_white();

    bool is_figure_black();

    void print_possible_moves();

    void print_available_moves();

    void setSide(bool side);

    bool is_cell_busy_by_enemy_figure(Coordinates cell, std::vector<Figure> enemy_figures);

    bool is_cell_busy_by_ally_figure(Coordinates cell, std::vector<Figure> ally_figures);

    bool getSide() const;

    void clear_possible_moves();

    void clear_available_moves();

    const char *get_side_as_string();
};

#endif //CHESS_FIGURE_H
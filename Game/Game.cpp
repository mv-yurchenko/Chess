//
// Created by Max Yurchenko on 05.09.2018.
//

#include "Game.h"

void Game::initialize_game() {
    this->current_desk = new Desk();
    current_desk->initialize_desk();
}

void Game::move_figure(uint8_t old_x, uint8_t old_y, uint8_t new_x, uint8_t new_y) {
    Coordinates old_coord(old_x, old_y);
    Coordinates new_coord(new_x, new_y);
//        this->current_desk->get_figure_by_coordinates(old_x, old_y)->print_possible_moves();
    std::cout <<this->current_desk->move_figure(old_coord, new_coord);
}

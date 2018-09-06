//
// Created by Max Yurchenko on 05.09.2018.
//

#include "Game.h"

void Game::initialize_game() {
    this->current_desk = new Desk();
    this->is_game_finished = false;
    this->white_turn = true;
    current_desk->initialize_desk();
}

void Game::move_figure(uint8_t old_x, uint8_t old_y, uint8_t new_x, uint8_t new_y) {
    Coordinates old_coord(old_x, old_y);
    Coordinates new_coord(new_x, new_y);
//        this->current_desk->get_figure_by_coordinates(old_x, old_y)->print_possible_moves();
    std::cout <<this->current_desk->move_figure(old_coord, new_coord);
}

Desk *Game::getCurrent_desk() const {
    return current_desk;
}

bool Game::get_is_game_finished() const {
    return is_game_finished;
}

bool Game::isWhite_turn() const {
    return white_turn;
}

void Game::finish_game() {
    is_game_finished = true;
}

int Game::input_coordinate(const char *coord_name) {
    std::cout<<coord_name << std::endl;
    int coord;
    std::cin >> coord;
    return coord;
}

bool Game::is_mate(Coordinates coordinates) {
    return this->getCurrent_desk()->get_figure_by_coordinates(coordinates.getX(), coordinates.getY())->getName() == "king";
}

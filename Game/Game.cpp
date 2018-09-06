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

bool Game::move_figure(uint8_t old_x, uint8_t old_y, uint8_t new_x, uint8_t new_y) {
    Coordinates old_coord(old_x, old_y);
    Coordinates new_coord(new_x, new_y);
//        this->current_desk->get_figure_by_coordinates(old_x, old_y)->print_possible_moves();
    bool is_move_done = this->current_desk->move_figure(old_coord, new_coord);
    return is_move_done;
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

void Game::player_turn(bool is_white_turn) {
    std::cout<<"Input figure coordinates" << std::endl;

    int x = input_coordinate("X:");
    int y = input_coordinate("Y:");

    std::cout<<"Your choice:" << getCurrent_desk()->get_figure_by_coordinates(x, y)->getName()<< std::endl;

    std::cout<<"Input new coordinates" << std::endl;

    int new_x = input_coordinate("X:");
    int new_y = input_coordinate("Y:");

    if (is_white_turn == getCurrent_desk()->get_figure_by_coordinates(x, y)->getSide()) {
        bool success_turn = move_figure(x, y, new_x, new_y);
        if (success_turn){
            print_msg_about_success_move(x, y, new_x, new_y);
        }
    } else{
        print_msg_about_failed_move(x, y, new_x, new_y);
    }
}

void Game::print_msg_about_success_move(int old_x, int old_y, int new_x, int new_y) {
    std::cout << "Figure " << this->current_desk->get_figure_by_coordinates(new_x, new_y)->getName() << " was moved from : (" << old_x << " , " << old_y << ") to (" << new_x << " , " << new_y << ")"<< std::endl;
}

void Game::print_msg_about_failed_move(int old_x, int old_y, int new_x, int new_y) {
    std::cout << "Figure " << this->current_desk->get_figure_by_coordinates(old_x, old_y)->getName() << " was NOT moved from : (" << old_x << " , " << old_y << ") to (" << new_x << " , " << new_y << ")"<< std::endl;
}

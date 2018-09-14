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

bool Game::move_figure(int old_x, int old_y, int new_x, int new_y) {
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
    return coord - 1;
}

bool Game::is_mate(int x, int y) {
    return this->getCurrent_desk()->get_figure_by_coordinates(x, y)->getName() == "king";
}

bool Game::player_turn(bool is_white_turn) {

    bool move_done = false;

    std::cout<<"Input figure coordinates" << std::endl;

    Coordinates old_coordinates = input_coordinates();

    std::cout<<"Your choice:" << getCurrent_desk()->get_figure_by_coordinates(old_coordinates.getX(), old_coordinates.getY())->getName()<< std::endl;

    std::cout<<"Input new coordinates" << std::endl;

    Coordinates new_coordinates = input_coordinates();

    if (is_white_turn == getCurrent_desk()->get_figure_by_coordinates(old_coordinates.getX(), old_coordinates.getY())->getSide()) {
        bool success_turn = move_figure(old_coordinates.getX(), old_coordinates.getY(), new_coordinates.getX(), new_coordinates.getY());
        if (success_turn){
            print_msg_about_success_move(old_coordinates.getX(), old_coordinates.getY(), new_coordinates.getX(), new_coordinates.getY());
            setIs_game_finished(is_mate(new_coordinates.getX(), new_coordinates.getY()));
            write_log_about_move(getCurrent_desk()->get_figure_by_coordinates(new_coordinates.getX(), new_coordinates.getY()), old_coordinates.getX(), old_coordinates.getY(), new_coordinates.getX(), new_coordinates.getY());
            move_done = true;
            setWhite_turn(not isWhite_turn());
        }
    } else{
        print_msg_about_failed_move(old_coordinates.getX(), old_coordinates.getY(), new_coordinates.getX(), new_coordinates.getY());
    }
    return move_done;
}

void Game::print_msg_about_success_move(int old_x, int old_y, int new_x, int new_y) {
    std::cout << "Figure " << this->current_desk->get_figure_by_coordinates(new_x, new_y)->getName() << " was moved from : (" << old_x << " , " << old_y << ") to (" << new_x << " , " << new_y << ")"<< std::endl;
}

void Game::print_msg_about_failed_move(int old_x, int old_y, int new_x, int new_y) {
    std::cout << "Figure " << this->current_desk->get_figure_by_coordinates(old_x, old_y)->getName() << " was NOT moved from : (" << old_x << " , " << old_y << ") to (" << new_x << " , " << new_y << ")"<< std::endl;
}

void Game::setIs_game_finished(bool is_game_finished) {
    Game::is_game_finished = is_game_finished;
}

void Game::setWhite_turn(bool white_turn) {
    Game::white_turn = white_turn;
}

void Game::write_log_about_move(Figure *figure, int old_x, int old_y, int new_x, int new_y) {
    gameLogsWriter.write_log_about_move(figure, old_x, old_y, new_x, new_y);
}

void Game::print_request_to_move_again() {
    std::cout << "Move FAILED" << std::endl << "Try again: " << std::endl;
}



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

    // Координаты, указывающее на желание пользователя  сохранить игру
    Coordinates save_game_coord(100, 100);
    Coordinates new_coordinates;

    std::cout<<"Input figure coordinates" << std::endl;
    Coordinates old_coordinates = input_coordinates();

    if (old_coordinates != save_game_coord) {
        std::cout << "Your choice:" << getCurrent_desk()->get_figure_by_coordinates(old_coordinates.getX(),
                                                                                    old_coordinates.getY())->getName()
                  << std::endl;

        std::cout << "Input new coordinates" << std::endl;
        new_coordinates = input_coordinates();
    } else{
        new_coordinates.setX(100); new_coordinates.setY(100);
    }
    bool is_game_saved = save_game_coord == new_coordinates or save_game_coord == old_coordinates;
    if (is_game_saved){
        GameLogsWriter gameLogsWriter;
        gameLogsWriter.save_game(getCurrent_desk(), is_white_turn);
    }
    // TODO : Дебаг функции SAVE
    if (not is_game_saved) {
        if (is_white_turn ==
            getCurrent_desk()->get_figure_by_coordinates(old_coordinates.getX(), old_coordinates.getY())->getSide()) {
            bool success_turn = move_figure(old_coordinates.getX(), old_coordinates.getY(), new_coordinates.getX(),
                                            new_coordinates.getY());
            if (success_turn) {
                print_msg_about_success_move(old_coordinates.getX(), old_coordinates.getY(), new_coordinates.getX(),
                                             new_coordinates.getY());
                setIs_game_finished(is_mate(new_coordinates.getX(), new_coordinates.getY()));
                write_log_about_move(
                        getCurrent_desk()->get_figure_by_coordinates(new_coordinates.getX(), new_coordinates.getY()),
                        old_coordinates.getX(), old_coordinates.getY(), new_coordinates.getX(), new_coordinates.getY());
                move_done = true;
                setWhite_turn(not isWhite_turn());
            }
        } else {
            print_msg_about_failed_move(old_coordinates.getX(), old_coordinates.getY(), new_coordinates.getX(),
                                        new_coordinates.getY());
        }
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

Coordinates Game::input_coordinates() {
    int first_num;
    bool success_input = false;
    std::string coordinates;
    while (not success_input)
    {
        std::cout << "Input Coordinates:";
        std::cin >> coordinates;
        if (coordinates == "save"){
            return Coordinates(100, 100);
        }
        first_num = convert_letter_to_num(coordinates[0]);
        success_input = not (coordinates.length() != 2 or first_num == 0);
    }
    Coordinates return_coordinates(first_num -1, convert_char_to_string(coordinates[1]) - 1);
    return return_coordinates;
}

int Game::convert_letter_to_num(char letter) {
    if (letter == 'A') {
        return 1;
    }
    if (letter == 'B') {
        return 2;
    }
    if (letter == 'C') {
        return 3;
    }
    if (letter == 'D') {
        return 4;
    }
    if (letter == 'E') {
        return 5;
    }
    if (letter == 'F') {
        return 6;
    }
    if (letter == 'G') {
        return 7;
    }
    if (letter == 'H') {
        return 8;
    }
    return 0;
}

int Game::convert_char_to_string(char num_as_char) {
    if (num_as_char == '1'){
        return 1;
    }
    if (num_as_char == '2'){
        return 2;
    }
    if (num_as_char == '3'){
        return 3;
    }
    if (num_as_char == '4'){
        return 4;
    }
    if (num_as_char == '5'){
        return 5;
    }
    if (num_as_char == '6'){
        return 6;
    }
    if (num_as_char == '7'){
        return 7;
    }
    if (num_as_char == '8'){
        return 8;
    }
}



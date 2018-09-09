//
// Created by Max Yurchenko on 05.09.2018.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include "../Desk.h"
#include "conio.h"
#include "stdio.h"
#include "../LogsWriter/GameLogsWriter.h"

class Game {
    Desk *current_desk;

    bool is_game_finished;

    bool white_turn;

    GameLogsWriter gameLogsWriter;
public:
    void setWhite_turn(bool white_turn);

public:
    bool isWhite_turn() const;

    void setIs_game_finished(bool is_game_finished);

    Desk *getCurrent_desk() const;

    bool get_is_game_finished() const;

    void initialize_game();

    bool move_figure(int old_x, int old_y, int new_x, int new_y);

    void finish_game();

    int input_coordinate(const char *coord_name);

    bool is_mate(int x, int y);

    bool player_turn(bool is_white_turn);

    void print_msg_about_success_move(int old_x, int old_y, int new_x, int new_y);

    void print_msg_about_failed_move(int old_x, int old_y, int new_x, int new_y);

    void print_request_to_move_again(){
        std::cout << "Move FAILED" << std::endl << "Try again: " << std::endl;
    }

    void write_log_about_move(Figure *figure, int old_x, int old_y, int new_x, int new_y);
};


#endif //CHESS_GAME_H

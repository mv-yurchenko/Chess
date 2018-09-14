//
// Created by Max Yurchenko on 05.09.2018.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include "../Desk.h"
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

    void print_request_to_move_again();

    void write_log_about_move(Figure *figure, int old_x, int old_y, int new_x, int new_y);

    Coordinates input_coordinates(){
        int first_num;
        bool success_input = false;
        std::string coordinates;
        while (not success_input)
        {
            std::cout << "Input Coordinates:";
            std::cin >> coordinates;
            first_num = convert_letter_to_num(coordinates[0]);
            success_input = not (coordinates.length() != 2 or first_num == 0);
        }
        Coordinates return_coordinates(first_num -1, convert_char_to_string(coordinates[1]) - 1);
        return return_coordinates;
    }

    int convert_letter_to_num(char letter){
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

    int convert_char_to_string(char num_as_char){
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
};


#endif //CHESS_GAME_H

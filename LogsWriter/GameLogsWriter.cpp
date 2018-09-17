//
// Created by Max Yurchenko on 08.09.2018.
//

#include "GameLogsWriter.h"

GameLogsWriter::GameLogsWriter() {
    this->log_filename = "GameLogs";
    this->log_file_path = "../LogsFiles/" + this->log_filename+ ".txt";
    this->log_file.open(this->log_file_path);
    this->desk_log_filename = "Desk";
    this->desk_log_file_path = "../LogsFiles/" + this->desk_log_filename+ ".txt";
    this->desk_log_file.open(this->desk_log_file_path);
    this->game_save_filename = "../LogsFiles/SavedGames/";
    this->game_save_file_path = removeSpaces(this->game_save_filename + generate_game_save_filename() + ".txt");
    this->game_save_file.open(this->game_save_file_path);
}

void GameLogsWriter::write_log_about_move(Figure *figure, int old_x, int old_y, int new_x, int new_y) {
    log_file << figure->get_side_as_string() << " " << figure->getName() << " was moved from : (" << old_x << " , " << old_y << ") to (" << new_x << " , " << new_y << ")"<< std::endl;
}

void GameLogsWriter::write_current_desk(Desk *desk, bool to_save_game) {
    std::ofstream desk_log_file;
    if (to_save_game){
        desk_log_file.open(this->game_save_file_path);
    } else{
        std::ofstream log_file;
        desk_log_file.open(this->desk_log_file_path);
    }
    for (int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            desk_log_file << std::to_string(j) << std::to_string(i) << " " << desk->get_figure_by_coordinates(j, i)->getName() << " " << desk->get_figure_by_coordinates(j, i)->get_side_as_string()<< std::endl;
        }
    }
}

void GameLogsWriter::save_game(Desk *desk, bool is_white_turn) {
    this->game_save_file << std::to_string(is_white_turn) << std::endl;
    write_current_desk(desk, true);
}

std::string GameLogsWriter::generate_game_save_filename() {
    time_t result = time(nullptr);
    std::string time_string = asctime(localtime(&result));
    // Удаляем преенос строки в конце
    return time_string.substr(0, time_string.length() - 1);
}

std::string GameLogsWriter::removeSpaces(std::string str) {
    std::string new_string;
    for(auto symbol : str){
        if (symbol != ' ' and symbol != ':'){
            new_string.push_back(symbol);
        }else{
            new_string.push_back('_');
        }
    }
    return new_string;
}





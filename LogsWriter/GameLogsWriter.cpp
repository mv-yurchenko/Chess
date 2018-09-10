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
}

void GameLogsWriter::write_log_about_move(Figure *figure, int old_x, int old_y, int new_x, int new_y) {
    log_file << figure->get_side_as_string() << " " << figure->getName() << " was moved from : (" << old_x << " , " << old_y << ") to (" << new_x << " , " << new_y << ")"<< std::endl;
}

void GameLogsWriter::write_current_desk(Desk *desk) {
    for (int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            desk_log_file << std::to_string(j) << std::to_string(i) << " " << desk->get_figure_by_coordinates(j, i)->getName() << " " << desk->get_figure_by_coordinates(j, i)->get_side_as_string()<< std::endl;
        }
    }
}

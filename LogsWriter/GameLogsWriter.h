//
// Created by Max Yurchenko on 08.09.2018.
//

#ifndef CHESS_GAMELOGSWRITER_H
#define CHESS_GAMELOGSWRITER_H


#include <string>
#include <fstream>
#include "../Desk.h"

class GameLogsWriter {
    std::string log_file_path;
    std::string log_filename;
    std::ofstream log_file;
public:
    GameLogsWriter(){
        this->log_filename = "GameLogs";
        this->log_file_path = "../LogsFiles/" + this->log_filename+ ".txt";
        this->log_file.open(this->log_file_path);
    }

    void write_log_about_move(Figure *figure, int old_x, int old_y, int new_x, int new_y) {
        log_file << "Figure " << figure->getName() << " was moved from : (" << old_x << " , " << old_y << ") to (" << new_x << " , " << new_y << ")"<< std::endl;
    }
};


#endif //CHESS_GAMELOGSWRITER_H

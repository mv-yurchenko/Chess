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
    std::ofstream desk_log_file;
    std::string desk_log_filename;
    std::string desk_log_file_path;
public:
    GameLogsWriter();

    void write_log_about_move(Figure *figure, int old_x, int old_y, int new_x, int new_y);

    void write_current_desk(Desk *desk);
};


#endif //CHESS_GAMELOGSWRITER_H

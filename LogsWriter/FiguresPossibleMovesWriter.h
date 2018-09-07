//
// Created by Max Yurchenko on 06.09.2018.
//

#ifndef CHESS_FIGURESPOSSIBLEMOVESWRITER_H
#define CHESS_FIGURESPOSSIBLEMOVESWRITER_H

#include "../Desk.h"
#include "fstream"


class FiguresPossibleMovesWriter {
    std::string path_to_white_figure_logs_directory;
    std::string path_to_black_figure_logs_directory;
    std::string full_path_to_output_file;
public:
    FiguresPossibleMovesWriter();

    void write_all_figures_possible_moves(Desk *desk);

    void write_figure_possible_moves(Figure *figure, bool side);


    bool DoesFileExist (const std::string& name);
};


#endif //CHESS_FIGURESPOSSIBLEMOVESWRITER_H

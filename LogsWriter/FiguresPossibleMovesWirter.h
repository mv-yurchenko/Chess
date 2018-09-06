//
// Created by Max Yurchenko on 06.09.2018.
//

#ifndef CHESS_FIGURESPOSSIBLEMOVESWIRTER_H
#define CHESS_FIGURESPOSSIBLEMOVESWIRTER_H

#include "../Figures/Figure.h"
#include "fstream"

class FiguresPossibleMovesWirter {
    std::string path_to_white_figure_logs_directory;
    std::string path_to_black_figure_logs_directory;
    std::string full_path_to_output_file;
public:
    FiguresPossibleMovesWirter();

    void write_all_figures_possible_moves(std::vector<Figure> white_figures, std::vector<Figure> black_figures);
};


#endif //CHESS_FIGURESPOSSIBLEMOVESWIRTER_H

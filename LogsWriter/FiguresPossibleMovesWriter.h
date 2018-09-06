//
// Created by Max Yurchenko on 06.09.2018.
//

#ifndef CHESS_FIGURESPOSSIBLEMOVESWRITER_H
#define CHESS_FIGURESPOSSIBLEMOVESWRITER_H

#include "../Figures/Figure.h"
#include "fstream"

class FiguresPossibleMovesWriter {
    std::string path_to_white_figure_logs_directory;
    std::string path_to_black_figure_logs_directory;
    std::string full_path_to_output_file;
public:
    FiguresPossibleMovesWriter();

    void write_all_figures_possible_moves(std::vector<Figure> white_figures, std::vector<Figure> black_figures);
};


#endif //CHESS_FIGURESPOSSIBLEMOVESWRITER_H

//
// Created by Max Yurchenko on 06.09.2018.
//

#include "FiguresPossibleMovesWriter.h"

void FiguresPossibleMovesWriter::write_all_figures_possible_moves(std::vector<Figure> white_figures,
                                                                  std::vector<Figure> black_figures) {
    // Общий вид логов : 1 строчка - текущие координаты, остальные - Possible_moves
    for(const auto &figure : white_figures){
        // LogsFiles/Figures/Black/figureName.txt
        this->full_path_to_output_file = this->path_to_white_figure_logs_directory +  figure.getName() + ".txt";

        std::ofstream output_file;
        output_file.open(this->full_path_to_output_file);

        output_file << std::to_string(figure.getCoordinates().getX()) << "," << std::to_string(figure.getCoordinates().getY()) << std::endl;
    }

    for(const auto &figure : black_figures){
        // LogsFiles/Figures/Black/figureName.txt
        this->full_path_to_output_file = this->path_to_black_figure_logs_directory +  figure.getName() + ".txt";

        std::ofstream output_file;
        output_file.open(this->full_path_to_output_file);

        output_file << std::to_string(figure.getCoordinates().getX()) << "," << std::to_string(figure.getCoordinates().getY()) << std::endl;
    }
}

FiguresPossibleMovesWriter::FiguresPossibleMovesWriter() {
    this->path_to_white_figure_logs_directory = "LogsFiles/Figures/White/";
    this->path_to_black_figure_logs_directory = "LogsFiles/Figures/Black/";
}

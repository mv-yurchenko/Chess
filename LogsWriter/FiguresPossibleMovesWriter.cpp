//
// Created by Max Yurchenko on 06.09.2018.
//

#include "FiguresPossibleMovesWriter.h"

void FiguresPossibleMovesWriter::write_all_figures_possible_moves(Desk *desk) {
    for (uint8_t i = 0; i < 7; i++){
        for (uint8_t j = 0; j < 7; j++) {
            auto figure = desk->get_figure_by_coordinates(i, j);
            write_figure_possible_moves(figure, figure->getSide());
        }
    }
}

FiguresPossibleMovesWriter::FiguresPossibleMovesWriter() {
    this->path_to_white_figure_logs_directory = "../LogsFiles/Figures/White/";
    this->path_to_black_figure_logs_directory = "../LogsFiles/Figures/Black/";
}


bool FiguresPossibleMovesWriter::DoesFileExist(const std::string &name) {
    std::ifstream f(name.c_str());
    return f.good();
}

void FiguresPossibleMovesWriter::write_figure_possible_moves(Figure *figure, bool side) {
    if (side){
        this->full_path_to_output_file = this->path_to_white_figure_logs_directory +  figure->getName() + ".txt";
    } else{
        this->full_path_to_output_file = this->path_to_black_figure_logs_directory +  figure->getName() + ".txt";
    }

    std::ofstream output_file;
    output_file.open(this->full_path_to_output_file);


    // Записываем текущее положение
    output_file << std::to_string(figure->getCoordinates().getX()) << "," << std::to_string(figure->getCoordinates().getY()) << std::endl;

    for (auto move : figure->getPossible_moves()){
        output_file << std::to_string(move.getNew_coordinates().getX()) << "," << std::to_string(move.getNew_coordinates().getY()) << std::endl;
    }
}

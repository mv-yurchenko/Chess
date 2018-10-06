//
// Created by max on 27.09.18.
//

#include <time.h>
#include <algorithm>
#include <random>
#include "Engine.h"

void Engine::print_possibilities() {
    //////////////////////////////////////////
    //  Дебаг функция
    /////////////////////////////////////////
    std::ofstream output_file;
    output_file.open("../DebugOutput/print_possibilities.txt");
    for (MoveWeight possibility : possibilities){
        output_file << "Figure : " + this->current_desk->get_figure_by_coordinates(possibility.getMove().getOld_coordinates())->getName() + "\n";
        output_file << "Side : " + (std::string)this->current_desk->get_figure_by_coordinates(possibility.getMove().getOld_coordinates())->get_side_as_string() + "\n";
        output_file << "Possibility:" << std::endl;
        output_file << "Current coordinates : " << possibility.getMove().getOld_coordinates().getX() << " " <<
                possibility.getMove().getOld_coordinates().getY() << std::endl;
        output_file << "New coordinates : " << possibility.getMove().getNew_coordinates().getX() << " " <<
                  possibility.getMove().getNew_coordinates().getY() << std::endl;
        output_file << "Weight: " << possibility.getWeight() << std::endl;
        output_file << "----------------------------------------------------" << std::endl;
    }
}

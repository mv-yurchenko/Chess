//
// Created by Max Yurchenko on 08.09.2018.
//

#include "ChessGraphic.h"

void ChessGraphic::print_letters() {
    for (auto letter : this->top_letters){
        std::cout << "  " << letter << "  ";
    }
}

void ChessGraphic::print_horizontal_separate_lane() {
    std::cout << std::endl;
    for(int i=0; i<40; i++)
    {
        std::cout<<"-";
    }
    std::cout << std::endl;
}

void ChessGraphic::print_desk(Desk *desk) {
    clear_desk();
    print_letters();
    print_horizontal_separate_lane();
    for (auto i = 0; i < 8;  i++){
        for (auto j = 0; j < 8; j++){
            print_figure_on_cell(desk->get_figure_by_coordinates(j, i));
        }
        std::cout << std::endl;
    }
}

void ChessGraphic::print_figure_on_cell(Figure *figure) {
    bool no_fig = true;
    if (figure->getDesk_name().length() == 3){
        std::cout<<figure->getDesk_name() << "  ";
        no_fig = false;
    } if(figure->getDesk_name().length() == 4) {
        std::cout << figure->getDesk_name() << " ";
        no_fig = false;
    }
    if (no_fig) {
        std::cout << "     ";
    }
}

void ChessGraphic::clear_desk() {
    system("clear");
    system("cls");
}

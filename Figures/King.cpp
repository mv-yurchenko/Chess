//
// Created by Max Yurchenko on 25.08.2018.
//

#include "King.h"

King::King() {

}

void King::calculate_possible_moves(std::vector<Figure> white_figures ,std::vector<Figure> black_figures ) {
    std::vector<Figure> ally_figures;
    if (is_figure_white()){
        ally_figures = white_figures;
    } else{
        ally_figures = black_figures;
    }

    calculate_one_direction(ally_figures, true, false, false, false);
    calculate_one_direction(ally_figures, false, true, false, false);
    calculate_one_direction(ally_figures, false, false , true, false);
    calculate_one_direction(ally_figures, false, false , false, true);

    calculate_one_direction(ally_figures, true, false, true, false);
    calculate_one_direction(ally_figures, true, false, false, true);
    calculate_one_direction(ally_figures, false, true, false, true);
    calculate_one_direction(ally_figures, false, true, true, false);

}

King::King(bool side, Coordinates coordinates) : Figure(side, coordinates ,"king", 9999){
    if (side){
        setDesk_name("W_K");
    } else{
        setDesk_name("B_K");
    }
}

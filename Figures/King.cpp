//
// Created by Max Yurchenko on 25.08.2018.
//

#include "King.h"

King::King() = default;

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

void King::calculate_one_direction(const std::vector<Figure> &ally_figures, bool up, bool down, bool right, bool left) {
    Coordinates new_coordinates(getCoordinates().getX(), getCoordinates().getY());

    if (up) {
        new_coordinates.setY(getCoordinates().getY() + 1);
    }
    if (down) {
        new_coordinates.setY(getCoordinates().getY() - 1);
    }
    if (right){
        new_coordinates.setX(getCoordinates().getX() + 1);
    }
    if (left){
        new_coordinates.setX(getCoordinates().getX() - 1);
    }
    new_coordinates.print_coordinates();
    std::cout << is_out_of_border(new_coordinates) << " : " << is_cell_busy_by_ally_figure(new_coordinates, ally_figures) << std::endl;
    if (not is_out_of_border(new_coordinates) and not is_cell_busy_by_ally_figure(new_coordinates, ally_figures)) {
        add_move_to_possible_moves(new_coordinates);
    }
}

#include "Game/PVP_GAME.h"
#include "Game/PVE_GAME.h"


int main(){

    Desk desk;

    desk.initialize_desk();

    Coordinates old_coordinates(4, 0);
    Coordinates new_coordinates(4, 4);

    desk.force_move_figure(old_coordinates, new_coordinates);
    std::cout << desk.get_figure_by_coordinates(new_coordinates)->getName();
    desk.get_figure_by_coordinates(new_coordinates)->print_possible_moves();

//    PVE_GAME pve_game;
//
//    pve_game.initialize_game();
//
//    Engine engine(pve_game.getCurrent_desk(), pve_game.isWhite_turn());
//
//    engine.getMost_profitable_moves();
}

#include "Game/PVP_GAME.h"
#include "Game/PVE_GAME.h"


int main(){

    Desk *desk = new Desk();
    desk->initialize_desk();
//    PVE_GAME pve_game;
//
//    pve_game.pve_game();
    bool is_move_white = false;
    Engine engine(desk, is_move_white);
    engine.print_possibilities();
}

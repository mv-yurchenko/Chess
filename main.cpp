#include "Game/PVP_GAME.h"
#include "Game/PVE_GAME.h"


int main(){
    PVE_GAME pve_game;

    pve_game.initialize_game();

    Engine engine(pve_game.getCurrent_desk(), pve_game.isWhite_turn());
    engine.print_possibilities();
}

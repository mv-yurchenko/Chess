//
// Created by Max Yurchenko on 24.08.2018.
//

#include <iostream>
#include "Game/Game.h"

using namespace std;


    int main (){
    Game *game = new Game();

    game->initialize_game();

    game->move_figure(1 , 1 , 1 , 3);
    game->move_figure(1 , 1 , 1 , 3);
    game->move_figure(1 , 3 , 1 , 4); // TODO: Почему нельзя?
};
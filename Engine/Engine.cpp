//
// Created by max on 27.09.18.
//

#include "Engine.h"

Engine::Engine(Desk *desk, bool is_move_white) {
    this->current_desk = desk;
    this->is_move_white = is_move_white;
}

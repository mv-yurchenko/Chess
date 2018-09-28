//
// Created by Max Yurchenko on 19.09.2018.
//

#include "PVE_GAME.h"

PVE_GAME::PVE_GAME() {
    initialize_game();
    player_side = random_player_side();
    engine_side = not player_side;
    is_player_turn = player_side;
}

void PVE_GAME::engine_turn(bool is_white_turn) {
    Engine engine(this->getCurrent_desk(), is_white_turn);
    Move engine_move = engine.move();
    if (this->getCurrent_desk()->move_figure(engine_move.getOld_coordinates(), engine_move.getNew_coordinates())){
        this->setWhite_turn(not is_white_turn);
        this->setIs_game_finished(is_mate(engine_move.getNew_coordinates().getX(), engine_move.getNew_coordinates().getY()));
    }
}

void PVE_GAME::pve_game() {
    initialize_game();

    this->player_side = random_player_side();
    this->engine_side = not this->player_side;
    this->setWhite_turn(true);

    while (not this->get_is_game_finished()){
        chessGraphic.print_desk(getCurrent_desk());
        if (is_player_turn){
            human_turn(isWhite_turn());
        } else{
            engine_turn(isWhite_turn());
            is_player_turn = not is_player_turn;
        }
    }
}

void PVE_GAME::write_desk() {
    gameLogsWriter.write_current_desk(getCurrent_desk(), false);
}

void PVE_GAME::human_turn(bool is_white_turn) {
    std::cout << "Input figure to move" << std::endl;
    Coordinates figure_coordinates = input_coordinates();
    print_msg_about_figure_choice(figure_coordinates);

    std::cout << "Input new coordinates" << std::endl;
    Coordinates new_coordinates = input_coordinates();

    if (player_turn(isWhite_turn(), figure_coordinates, new_coordinates)) {
        print_msg_about_success_move(figure_coordinates.getX(), figure_coordinates.getY(),
                                     new_coordinates.getX(), new_coordinates.getY());
        setWhite_turn(not isWhite_turn());
        this->setIs_game_finished(is_mate(new_coordinates.getX(), new_coordinates.getY()));
        this->is_player_turn = not this->is_player_turn;
    } else {
        getCurrent_desk()->get_figure_by_coordinates(figure_coordinates)->print_possible_moves();
        print_msg_about_failed_move(figure_coordinates.getX(), figure_coordinates.getY(),
                                    new_coordinates.getX(), new_coordinates.getY());
    }
    write_desk();
    figuresPossibleMovesWriter.write_all_figures_possible_moves(getCurrent_desk());
}

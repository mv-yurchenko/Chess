//
// Created by Max Yurchenko on 19.09.2018.
//

#ifndef CHESS_PVE_GAME_H
#define CHESS_PVE_GAME_H


#include "Game.h"
#include "../Graphics/ChessGraphic.h"
#include "../LogsWriter/FiguresPossibleMovesWriter.h"
#include "../Engine/Engine.h"

class PVE_GAME : public Game{

    bool is_player_turn;
    bool player_side;
    bool engine_side;
    GameLogsWriter gameLogsWriter;
    ChessGraphic chessGraphic;
    FiguresPossibleMovesWriter figuresPossibleMovesWriter;
public:
    PVE_GAME();

    void write_desk();

    void pve_game();

    void human_turn(bool is_white_turn){
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
        } else {
            getCurrent_desk()->get_figure_by_coordinates(figure_coordinates)->print_possible_moves();
            print_msg_about_failed_move(figure_coordinates.getX(), figure_coordinates.getY(),
                                        new_coordinates.getX(), new_coordinates.getY());
        }
        write_desk();
        figuresPossibleMovesWriter.write_all_figures_possible_moves(getCurrent_desk());
    }

    void engine_turn(bool side);
};


#endif //CHESS_PVE_GAME_H

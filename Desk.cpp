//
// Created by Max Yurchenko on 03.09.2018.
//

#include "Desk.h"

Desk::Desk() {
    for (int i=0; i<8;i++)
        for(int j=0;j<8; j++) {
            {
                desk[i][j] = new Figure;
            }
        }
}

Figure *Desk::get_figure_by_coordinates(int x, int y) {
    return desk[x][y];
}

void Desk::initialize_desk() {

    // White castles
    Coordinates w_castle1_coordinates(0, 0);
    Coordinates w_castle2_coordinates(7, 0);

    Castle *w_castle1 = new Castle(true, w_castle1_coordinates);
    Castle *w_castle2 = new Castle(true, w_castle2_coordinates);

    desk[w_castle1_coordinates.getX()][w_castle1_coordinates.getY()] = w_castle1;
    desk[w_castle2_coordinates.getX()][w_castle2_coordinates.getY()] = w_castle2;

    // Black castles
    Coordinates b_castle1_coordinates(0, 7);
    Coordinates b_castle2_coordinates(7, 7);

    Castle *b_castle1 = new Castle(false, b_castle1_coordinates);
    Castle *b_castle2 = new Castle(false, b_castle2_coordinates);

    desk[b_castle1_coordinates.getX()][b_castle1_coordinates.getY()] = b_castle1;
    desk[b_castle2_coordinates.getY()][b_castle2_coordinates.getY()] = b_castle2;

    // White Knights
    Coordinates w_knight1_coordinates(1, 0);
    Coordinates w_knight2_coordinates(6, 0);

    Knight *w_knight1 = new Knight(true, w_knight1_coordinates);
    Knight *w_knight2 = new Knight(true, w_knight2_coordinates);

    desk[w_knight1_coordinates.getX()][w_knight1_coordinates.getY()] = w_knight1;
    desk[w_knight2_coordinates.getX()][w_knight2_coordinates.getY()] = w_knight2;

    // Black Knights
    Coordinates b_knight1_coordinates(1, 7);
    Coordinates b_knight2_coordinates(6, 7);

    Knight *b_knight1 = new Knight(false, w_knight1_coordinates);
    Knight *b_knight2 = new Knight(false, w_knight2_coordinates);

    desk[b_knight1_coordinates.getX()][b_knight1_coordinates.getY()] = b_knight1;
    desk[b_knight2_coordinates.getX()][b_knight2_coordinates.getY()] = b_knight2;

    // White Bishops

    Coordinates w_bishop1_coordinates(2, 0);
    Coordinates w_bishop2_coordinates(5, 0);

    auto w_bishop1 = new Bishop(true, w_bishop1_coordinates);
    auto w_bishop2 = new Bishop(true, w_bishop2_coordinates);

    desk[w_bishop1_coordinates.getX()][w_bishop1_coordinates.getY()] = w_bishop1;
    desk[w_bishop2_coordinates.getX()][w_bishop2_coordinates.getY()] = w_bishop2;

    // Black Bishops

    Coordinates b_bishop1_coordinates(2, 7);
    Coordinates b_bishop2_coordinates(5, 7);

    Bishop *b_bishop1 = new Bishop(false, b_bishop1_coordinates);
    Bishop *b_bishop2 = new Bishop(false, b_bishop2_coordinates);

    desk[b_bishop1_coordinates.getX()][b_bishop1_coordinates.getY()] = b_bishop1;
    desk[b_bishop2_coordinates.getX()][b_bishop2_coordinates.getY()] = b_bishop2;

    // White King && Queen

    Coordinates w_queen_coordinates(3, 0);
    Coordinates w_King_coordinates(4, 0);

    Queen *w_queen = new Queen(true, w_queen_coordinates);
    King *w_king = new King(true, w_King_coordinates);

    desk[w_queen_coordinates.getX()][w_queen_coordinates.getY()] = w_queen;
    desk[w_King_coordinates.getX()][w_King_coordinates.getY()] = w_king;

    // Black King && Queen

    Coordinates b_queen_coordinates(3, 7);
    Coordinates b_King_coordinates(4, 7);

    Queen *b_queen = new Queen(false, b_queen_coordinates);
    King *b_king = new King(false, b_King_coordinates);

    desk[b_queen_coordinates.getX()][b_queen_coordinates.getY()] = b_queen;
    desk[b_King_coordinates.getX()][b_King_coordinates.getY()] = b_king;

    // White Pawns

    for (int8_t i = 0; i < 8; i++){
        Coordinates w_pawn_coordinatrs(i, 1);

        Pawn *w_pawn = new Pawn(true, w_pawn_coordinatrs);

        desk[w_pawn->getCoordinates().getX()][w_pawn->getCoordinates().getY()] = w_pawn;
    }

    // Black Pawns

    for (int8_t i = 0; i < 8; i++){
        Coordinates b_pawn_coordinatrs(i, 6);

        Pawn *b_pawn = new Pawn(true, b_pawn_coordinatrs);

        desk[b_pawn->getCoordinates().getX()][b_pawn->getCoordinates().getY()] = b_pawn;
    }

    reinitialize_white_black_figures();
    initialize_possible_moves();

}

void Desk::print_desk() {
    //////////////////////////////////////////
    //  Дебаг функция
    //////////////////////////////////////////
    for (int i = 0; i < 8; i ++){
        for (int j = 0; j < 8; j ++) {
            if (not (desk[j][i]->getName() == "No figure")) {
                Figure *figure = desk[j][i];
                std::cout << "Figure on coordinates: " << j << " : "<< i  << std::endl;
                std::cout << desk[j][i]->getName() << std::endl;
                std::cout << "-------------------------" << std::endl;
            }
        }
    }
}

bool Desk::move_figure(Coordinates old_coordinates, Coordinates new_coordinates) {
    Figure *figure = desk[old_coordinates.getX()][old_coordinates.getY()];
    Figure *old_figure = new Figure;
    if (is_move_possible(*figure, new_coordinates)){
        this->desk[new_coordinates.getX()][new_coordinates.getY()] = figure;
        this->desk[new_coordinates.getX()][new_coordinates.getY()]->setCoordinates(new_coordinates);
        this->desk[old_coordinates.getX()][old_coordinates.getY()] = old_figure;
        reinitialize_white_black_figures();
        initialize_possible_moves();
        return true;
    } else {
        return false;
    }
}

bool Desk::is_move_possible(Figure figure, Coordinates new_coordinates) {
    for(auto move : figure.getPossible_moves()){
        Coordinates possible_coordinates = move.getNew_coordinates();
        if (possible_coordinates == new_coordinates){
            return true;
        }
    }
    return false;
}

void Desk::reinitialize_white_black_figures() {
    for (int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j ++){
            if(desk[i][j]->getSide() and not (desk[i][j]->getName() == "no figure")){
                white_figures.push_back(*desk[i][j]);
            }
            if(not desk[i][j]->getSide() and not (desk[i][j]->getName() == "no figure")){
                black_figures.push_back(*desk[i][j]);
            }
        }
    }
}

void Desk::initialize_possible_moves() {
    for (int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j ++){
            this->desk[i][j]->clear_available_moves();
            this->desk[i][j]->clear_possible_moves();
            this->desk[i][j]->calculate_available_moves();
            this->desk[i][j]->calculate_possible_moves(white_figures, black_figures);
        }
    }
}

const std::vector<Figure> &Desk::getWhite_figures() const {
    return white_figures;
}

const std::vector<Figure> &Desk::getBlack_figures() const {
    return black_figures;
}


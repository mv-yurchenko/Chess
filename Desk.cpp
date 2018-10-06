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
    initialize_castles(true);
    initialize_castles(false);

    initialize_knights(true);
    initialize_knights(false);

    initialize_bishops(true);
    initialize_bishops(false);

    initialize_king(true);
    initialize_king(false);

    initialize_queen(true);
    initialize_queen(false);

    // White Pawns
    for (uint8_t i = 0; i < 8; i++){
        initialize_pawn(true, i);
    }

    // Black Pawns
    for (uint8_t i = 0; i < 8; i++){
        initialize_pawn(false, i);
    }

    reinitialize_white_black_figures();

    initialize_possible_moves();

    reinitialize_white_black_figures();
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
    white_figures.clear();
    black_figures.clear();
    for (int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j ++){
            if(desk[i][j]->getSide() and not (desk[i][j]->getName() == "no figure")){
                white_figures.push_back(*desk[i][j]);
            }
            if(not desk[i][j]->getSide() and  desk[i][j]->getName() != "NoFigure"){
                black_figures.push_back(*desk[i][j]);
            }
        }
    }
}

void Desk::initialize_possible_moves() {
    for (int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j ++){
            this->desk[i][j]->clear_possible_moves();
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

Figure *Desk::get_figure_by_coordinates(Coordinates coordinates) {
    return desk[coordinates.getX()][coordinates.getY()];
}

void Desk::print_black_figures(bool to_file) {
    ////////////////////////////////////////////
    //  Дебаг функция
    /////////////////////////////////////////
    std::ofstream file;
    file.open("black_figures.txt");

    for (auto figure : black_figures){
        file << figure.getName() << " : " << figure.getCoordinates().getX() << " , " << figure.getCoordinates().getY() << std::endl;
    }
}

void Desk::print_white_figures(bool to_file) {
    ////////////////////////////////////////////
    //  Дебаг функция
    /////////////////////////////////////////
    std::ofstream file;
    file.open("white_figures.txt");

    for (auto figure : white_figures){
        file << figure.getName() << " : " << figure.getCoordinates().getX() << " , " << figure.getCoordinates().getY() << std::endl;
    }
}

void Desk::initialize_castles(bool side) {
    Coordinates castle1_coordinates;
    Coordinates castle2_coordinates;
    castle1_coordinates.setX(0);
    castle2_coordinates.setX(7);
    if (side){
        castle1_coordinates.setY(0);
        castle2_coordinates.setY(0);

    }else{
        castle1_coordinates.setY(7);
        castle2_coordinates.setY(7);
    }
    Castle *castle1 = new Castle(side, castle1_coordinates);
    Castle *castle2 = new Castle(side, castle2_coordinates);

    desk[castle1_coordinates.getX()][castle1_coordinates.getY()] = castle1;
    desk[castle2_coordinates.getX()][castle2_coordinates.getY()] = castle2;
}

void Desk::initialize_king(bool side) {
    Coordinates king_coordinates{};
    king_coordinates.setX(4);

    if (side){
        king_coordinates.setY(0);
    } else{
        king_coordinates.setY(7);
    }

    King *king = new King(side, king_coordinates);

    desk[king_coordinates.getX()][king_coordinates.getY()] = king;
}

void Desk::initialize_queen(bool side) {
    Coordinates queen_coordinates{};
    queen_coordinates.setX(3);

    if (side){
        queen_coordinates.setY(0);
    } else{
        queen_coordinates.setY(7);
    }

    Queen *queen = new Queen(side, queen_coordinates);

    desk[queen_coordinates.getX()][queen_coordinates.getY()] = queen;
}

void Desk::initialize_bishops(bool side) {
    Coordinates bishop1_coordinates;
    Coordinates bishop2_coordinates;
    bishop1_coordinates.setX(2);
    bishop2_coordinates.setX(5);

    if (side){
        bishop1_coordinates.setY(0);
        bishop2_coordinates.setY(0);
    } else{
        bishop1_coordinates.setY(7);
        bishop2_coordinates.setY(7);
    }

    Bishop *bishop1 = new Bishop(side, bishop1_coordinates);
    Bishop *bishop2 = new Bishop(side, bishop2_coordinates);

    desk[bishop1_coordinates.getX()][bishop1_coordinates.getY()] = bishop1;
    desk[bishop2_coordinates.getX()][bishop2_coordinates.getY()] = bishop2;
}

void Desk::initialize_knights(bool side) {
    Coordinates knight1_coordinates;
    Coordinates knight2_coordinates;
    knight1_coordinates.setX(1);
    knight2_coordinates.setX(6);

    if (side){
        knight1_coordinates.setY(0);
        knight2_coordinates.setY(0);
    } else{
        knight1_coordinates.setY(7);
        knight2_coordinates.setY(7);
    }

    Knight *knight1 = new Knight(side, knight1_coordinates);
    Knight *knight2 = new Knight(side, knight2_coordinates);

    desk[knight1_coordinates.getX()][knight1_coordinates.getY()] = knight1;
    desk[knight2_coordinates.getX()][knight2_coordinates.getY()] = knight2;
}

void Desk::initialize_pawn(bool side, int num) {
    Coordinates pawn_coordinates{};
    pawn_coordinates.setX(num);
    if (side)
        pawn_coordinates.setY(1);
    else
        pawn_coordinates.setY(6);
    Pawn *pawn = new Pawn(side, pawn_coordinates, num);
    desk[pawn_coordinates.getX()][pawn_coordinates.getY()] = pawn;
}

void Desk::print_all_figures_coordinates() {
    std::ofstream out_file;
    out_file.open("../DebugOutput/FiguresCoordinates.txt");
    out_file << "White Figures: \n";
    out_file << "--------------------------------------------\n";
    for(auto figure: getWhite_figures()){
        out_file << figure.get_figure_info();
    }
    out_file << "Black Figures: \n";
    out_file << "--------------------------------------------\n";
    for(auto figure: getBlack_figures()){
        out_file << figure.get_figure_info();
    }
}

bool Desk::force_move_figure(Coordinates old_coordinates, Coordinates new_coordinates) {
    // TODO : return
    int old_x = old_coordinates.getX();
    int old_y = old_coordinates.getY();

    int new_x = new_coordinates.getX();
    int new_y = new_coordinates.getY();

    desk[new_x][new_y] = desk[old_x][old_y];
    desk[new_x][new_y]->setCoordinates(new_coordinates);

    Figure *figure;
    desk[old_x][old_y] = figure;

    reinitialize_white_black_figures();
    this->initialize_possible_moves();
}


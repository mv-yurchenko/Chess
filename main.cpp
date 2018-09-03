//
// Created by Max Yurchenko on 24.08.2018.
//

#include <iostream>
#include "Figures/Figure.h"
#include "Coordinates.h"
#include "Figures/King.h"
#include "Figures/Pawn.h"
#include "Figures/Knight.h"
#include "Figures/Castle.h"
#include "Figures/Bishop.h"
#include "Figures/Queen.h"


using namespace std;


int main (){

    Coordinates w_queen_coordinates(3 , 3);

    Queen *w_queen = new Queen(true, w_queen_coordinates);

    w_queen->calculate_available_moves();
    w_queen->print_available_moves();



};
//
// Created by Max Yurchenko on 24.08.2018.
//

#include <iostream>
#include "Figures/Figure.h"
#include "Coordinates.h"
#include "Figures/King.h"
#include "Figures/Pawn.h"

using namespace std;


int main (){

    // TODO: проверить работу get_possible_moves()
    Coordinates coordinates(7, 7);
    Pawn *w_pawn = new Pawn(false, coordinates);
    w_pawn->calculate_available_moves();
    w_pawn->print_available_moves();


    cout << endl;
    system("pause");
    return 0;
};
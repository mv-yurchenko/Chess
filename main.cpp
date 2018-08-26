//
// Created by Max Yurchenko on 24.08.2018.
//

#include <iostream>
#include "Figures/Figure.h"
#include "Coordinates.h"
#include "Figures/King.h"
#include "Desk.h"

using namespace std;


int main (){
    Coordinates coordinates(1, 0);
    King king(true, coordinates);
    king.setCoordinates(coordinates);
    king.calculate_available_moves();
    Desk desk;
    Figure** desk_coord = desk.getDesk();
    std::cout<<desk_coord[0][4].getCoordinates().getX()<<std::endl;
    std::cout<<desk_coord[0][4].getCoordinates().getY()<<std::endl;
    for (auto pos_move : king.getAvailable_moves()){
        cout<<pos_move.getNew_coordinates().getX()<<endl;
        cout<<pos_move.getNew_coordinates().getY()<<endl;
        cout<<"-----------------------------------"<<endl;
    }
    cout << endl;
    system("pause");
    return 0;
};
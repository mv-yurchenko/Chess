//
// Created by Max Yurchenko on 24.08.2018.
//

#include <iostream>
#include "Figures/Figure.h"
#include "Coordinates.h"
#include "Figures/King.h"


using namespace std;


int main (){
    King king;
    Coordinates coordinates(2,2);
    king.setCoordinates(coordinates);
    king.calculate_available_moves();
    for (auto pos_move : king.getAvailable_moves()){
        cout<<pos_move.getNew_coordinates().getX()<<endl;
        cout<<pos_move.getNew_coordinates().getY()<<endl;
        cout<<"-----------------------------------"<<endl;
    }
    cout << endl;
    system("pause");
    return 0;
};
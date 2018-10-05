//
// Created by max on 26.09.18.
//

#ifndef CHESS_MOVEWEIGHT_H
#define CHESS_MOVEWEIGHT_H

#include "../Move.h"

class MoveWeight {
private:
    Move move;
    int weight;

public:
    MoveWeight() = default;

    MoveWeight(int weight, Move move);

    const Move &getMove() const;

    int getWeight() const;

    void setMove(const Move &move);

    void setWeight(int weight);

    Coordinates get_new_coordinates();;
};


#endif //CHESS_MOVEWEIGHT_H

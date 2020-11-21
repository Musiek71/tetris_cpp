//
// Created by musiek on 11/21/20.
//

#ifndef TETRIS_CPP_LPIECE_H
#define TETRIS_CPP_LPIECE_H


#include "Point.h"
#include "Piece.h"

class LPiece : public Piece {
    static Point punkty[4][4];
public:
    LPiece(int rotation);
};


#endif //TETRIS_CPP_LPIECE_H

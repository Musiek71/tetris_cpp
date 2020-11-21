//
// Created by musiek on 11/21/20.
//

#ifndef TETRIS_CPP_OPIECE_H
#define TETRIS_CPP_OPIECE_H


#include "Point.h"
#include "Piece.h"

class OPiece : public Piece {
    static Point punkty[4][4];
public:
    OPiece(std::string tileset, int rotation);
};



#endif //TETRIS_CPP_OPIECE_H

//
// Created by musiek on 11/21/20.
//

#ifndef TETRIS_CPP_TPIECE_H
#define TETRIS_CPP_TPIECE_H


#include "Point.h"
#include "Piece.h"

class TPiece : public Piece {
    static Point punkty[4][4];
public:
    TPiece(std::string tileset, int rotation);
};



#endif //TETRIS_CPP_TPIECE_H

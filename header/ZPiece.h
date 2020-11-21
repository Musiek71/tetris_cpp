//
// Created by musiek on 11/21/20.
//

#ifndef TETRIS_CPP_ZPIECE_H
#define TETRIS_CPP_ZPIECE_H


#include "Point.h"
#include "Piece.h"

class ZPiece : public Piece {
    static Point punkty[4][4];
public:
    ZPiece(std::string tileset, int rotation);
};


#endif //TETRIS_CPP_ZPIECE_H

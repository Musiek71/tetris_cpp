//
// Created by musiek on 11/21/20.
//

#ifndef TETRIS_CPP_JPIECE_H
#define TETRIS_CPP_JPIECE_H


#include "Point.h"
#include "Piece.h"

class JPiece : public Piece {
    static Point punkty[4][4];
public:
    JPiece(std::string tileset, int rotation, int spawnX);
};


#endif //TETRIS_CPP_JPIECE_H

//
// Created by musiek on 17.11.2020.
//

#ifndef TETRIS_CPP_IPIECE_H
#define TETRIS_CPP_IPIECE_H


#include "Point.h"
#include "Piece.h"

class IPiece : public Piece {
    static Point punkty[4][4];
public:
    IPiece(int rotation);
};


#endif //TETRIS_CPP_IPIECE_H

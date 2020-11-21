//
// Created by musiek on 11/21/20.
//

#include "../header/ZPiece.h"
#include "../header/PieceEnum.h"

Point ZPiece::punkty[4][4] = {
        {
                Point(0, 0), Point(1, 0),  Point(1, 1),  Point(2,1)
        },
        {
                Point(2, 0),  Point(2, 1),  Point(1, 1),  Point(1,2)
        },
        {
                Point(0, 0), Point(1, 0),  Point(1, 1),  Point(2,1)
        },
        {
                Point(2, 0),  Point(2, 1),  Point(1, 1),  Point(1,2)
        }
};

ZPiece::ZPiece(int rotation) : Piece(rotation, ZP, punkty) {}
//
// Created by musiek on 11/21/20.
//

#include "../header/OPiece.h"
#include "../header/PieceEnum.h"

Point OPiece::punkty[4][4] = {
        {
                Point(1, 1), Point(2, 1),  Point(1, 2),  Point(2,2)
        },
        {
                Point(1, 1), Point(2, 1),  Point(1, 2),  Point(2,2)
        },
        {
                Point(1, 1), Point(2, 1),  Point(1, 2),  Point(2,2)
        },
        {
                Point(1, 1), Point(2, 1),  Point(1, 2),  Point(2,2)
        }
};

OPiece::OPiece(int rotation) : Piece(rotation, OP, punkty) {}
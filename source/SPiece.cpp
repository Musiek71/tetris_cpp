//
// Created by musiek on 11/21/20.
//

#include "../header/SPiece.h"
#include "../header/PieceEnum.h"

Point SPiece::punkty[4][4] = {
        {
                Point(0,1), Point(1, 1),  Point(1, 0),  Point(2,0)
        },
        {
                Point(1, 0),  Point(1, 1),  Point(2, 1),  Point(2,2)
        },
        {
                Point(0, 1),  Point(1, 1),  Point(1, 0),  Point(2,0)
        },
        {
                Point(1, 0),  Point(1, 1),  Point(2, 1),  Point(2,2)
        }
};

SPiece::SPiece(std::string tileset, int rotation) : Piece(tileset, rotation, SP, punkty) {}
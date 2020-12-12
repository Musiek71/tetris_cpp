//
// Created by musiek on 11/21/20.
//

#include "../../header/Game/ZPiece.h"
#include "../../header/PieceEnum.h"

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

ZPiece::ZPiece(std::string tileset, int rotation, int spawnX) : Piece(tileset, rotation, ZP, (Point*)punkty, spawnX) {}
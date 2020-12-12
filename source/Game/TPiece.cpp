//
// Created by musiek on 11/21/20.
//

#include "../../header/Game/TPiece.h"
#include "../../header/PieceEnum.h"

Point TPiece::punkty[4][4] = {
        {
                Point(0, 1), Point(1, 1),  Point(2, 1),  Point(1,2)
        },
        {
                Point(0, 1),  Point(1, 1),  Point(1, 0),  Point(1,2)
        },
        {
                Point(0, 1),  Point(1, 1),  Point(1, 0),  Point(2,1)
        },
        {
                Point(1, 0),  Point(1, 1),  Point(1, 2),  Point(2,1)
        }
};

TPiece::TPiece(std::string tileset, int rotation, int spawnX) : Piece(tileset, rotation, TP, (Point*)punkty, spawnX) {}
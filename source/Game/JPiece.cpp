//
// Created by musiek on 11/21/20.
//

#include "../../header/Game/JPiece.h"
#include "../../header/Game/PieceEnum.h"

Point JPiece::punkty[4][4] = {
        {
                Point(1, 0), Point(1, 1),  Point(1, 2),  Point(0,2)
        },
        {
                Point(0, 0),  Point(0, 1),  Point(1, 1),  Point(2,1)
        },
        {
                Point(1, 0),  Point(2, 0),  Point(1, 1),  Point(1,2)
        },
        {
                Point(0, 1),  Point(1, 1),  Point(2, 1),  Point(2,2)
        }
};

JPiece::JPiece(std::string tileset, int rotation, int spawnX) : Piece(tileset, rotation, JP, (Point*)punkty, spawnX) {}
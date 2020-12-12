//
// Created by musiek on 11/21/20.
//

#include "../../header/Game/SPiece.h"
#include "../../header/Game/PieceEnum.h"

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

SPiece::SPiece(std::string tileset, int rotation, int spawnX) : Piece(tileset, rotation, SP, (Point*)punkty, spawnX) {}
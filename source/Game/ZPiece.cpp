//
// Created by musiek on 11/21/20.
//

#include "../../header/Game/ZPiece.h"
#include "../../header/PieceEnum.h"

Point ZPiece::points[4][4] = {
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

ZPiece::ZPiece(std::string tileset, ResourceManager* resourceManager, int rotation, int spawnX) : Piece(tileset, resourceManager, rotation, ZP, (Point*)points, spawnX) {}
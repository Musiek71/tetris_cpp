//
// Created by musiek on 11/21/20.
//

#include "../../header/Game/OPiece.h"
#include "../../header/PieceEnum.h"

Point OPiece::points[4][4] = {
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

OPiece::OPiece(std::string tileset, ResourceManager* resourceManager, int rotation, int spawnX) : Piece(tileset, resourceManager, rotation, OP, (Point*)points, spawnX) {}
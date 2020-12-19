//
// Created by musiek on 11/21/20.
//

#include "../../header/Game/LPiece.h"
#include "../../header/PieceEnum.h"

Point LPiece::points[4][4] = {
        {
                Point(1, 0), Point(1, 1),  Point(1, 2),  Point(2,2)
        },
        {
                Point(0, 1),  Point(1, 1),  Point(2, 1),  Point(0,2)
        },
        {
                Point(0, 0),  Point(1, 0),  Point(1, 1),  Point(1,2)
        },
        {
                Point(0, 1),  Point(1, 1),  Point(2, 1),  Point(2,0)
        }
};

LPiece::LPiece(std::string tileset, ResourceManager* resourceManager, int rotation, int spawnX) : Piece(tileset, resourceManager, rotation, LP, (Point*)points, spawnX) {}

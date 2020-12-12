//
// Created by musiek on 17.11.2020.
//

#include "../../header/Game/IPiece.h"
#include "../../header/Game/PieceEnum.h"

Point IPiece::punkty[4][4] = {
        {
                Point(0, 1), Point(1, 1),  Point(2, 1),  Point(3,1)
        },
        {
                Point(2, 0),  Point(2, 1),  Point(2, 2),  Point(2,3)
        },
        {
                Point(0, 2),  Point(1, 2),  Point(2, 2),  Point(3,2)
        },
        {
                Point(1, 0),  Point(1, 1),  Point(1, 2),  Point(1,3)
        }
};

IPiece::IPiece(std::string tileset, int rotation, int spawnX) : Piece(tileset, rotation, IP, (Point*)punkty, spawnX) {}
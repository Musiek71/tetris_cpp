//
// Created by musiek on 11/21/20.
//

#ifndef TETRIS_CPP_ZPIECE_H
#define TETRIS_CPP_ZPIECE_H


#include "Point.h"
#include "Piece.h"

/**
 * Class representing the Z piece/tetromino, deriving after Piece class.
 */
class ZPiece : public Piece {
    static Point points[4][4];
public:
    ZPiece(std::string tileset, ResourceManager* resourceManager, int rotation, int spawnX);
};


#endif //TETRIS_CPP_ZPIECE_H

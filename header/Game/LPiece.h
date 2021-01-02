//
// Created by musiek on 11/21/20.
//

#ifndef TETRIS_CPP_LPIECE_H
#define TETRIS_CPP_LPIECE_H


#include "Point.h"
#include "Piece.h"

/**
 * Class representing the L piece/tetromino, deriving after Piece class.
 */
class LPiece : public Piece {
    static Point points[4][4];
public:
    LPiece(std::string tileset, ResourceManager* resourceManager, int rotation, int spawnX);
};


#endif //TETRIS_CPP_LPIECE_H

//
// Created by musiek on 11/21/20.
//

#ifndef TETRIS_CPP_JPIECE_H
#define TETRIS_CPP_JPIECE_H


#include "Point.h"
#include "Piece.h"

/**
 * Class representing the J piece/tetromino, deriving after Piece class.
 */
class JPiece : public Piece {
    static Point points[4][4];
public:
    JPiece(std::string tileset, ResourceManager* resourceManager, int rotation, int spawnX);
};


#endif //TETRIS_CPP_JPIECE_H

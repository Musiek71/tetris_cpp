//
// Created by musiek on 11/21/20.
//

#ifndef TETRIS_CPP_SPIECE_H
#define TETRIS_CPP_SPIECE_H


#include "Point.h"
#include "Piece.h"

/**
 * Class representing the S piece/tetromino, deriving after Piece class.
 */
class SPiece : public Piece {
    static Point points[4][4];
public:
    SPiece(std::string tileset, ResourceManager* resourceManager, int rotation, int spawnX);
};



#endif //TETRIS_CPP_SPIECE_H

//
// Created by musiek on 11/21/20.
//

#ifndef TETRIS_CPP_TPIECE_H
#define TETRIS_CPP_TPIECE_H


#include "Point.h"
#include "Piece.h"

/**
 * Class representing the T piece/tetromino, deriving after Piece class.
 */
class TPiece : public Piece {
    static Point points[4][4];
public:
    TPiece(std::string tileset, ResourceManager* resourceManager, int rotation, int spawnX);
};



#endif //TETRIS_CPP_TPIECE_H

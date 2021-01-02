//
// Created by musiek on 17.11.2020.
//

#ifndef TETRIS_CPP_IPIECE_H
#define TETRIS_CPP_IPIECE_H


#include "Point.h"
#include "Piece.h"

/**
 * Class representing the I piece/tetromino, deriving after Piece class.
 */
class IPiece : public Piece {
    static Point points[4][4];
public:
    IPiece(std::string tileset, ResourceManager* resourceManager, int rotation, int spawnX);
};


#endif //TETRIS_CPP_IPIECE_H

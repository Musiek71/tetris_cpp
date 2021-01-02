//
// Created by musiek on 12/4/20.
//

#ifndef TETRIS_CPP_GHOSTPIECE_H
#define TETRIS_CPP_GHOSTPIECE_H

#include "Piece.h"

/**
 * The ghost piece class.
 *
 * Represents a ghost piece of a current piece. Its shape is dependent on the piece it mimics.
 */
class GhostPiece : public Piece {
public:
    GhostPiece(std::string tileset, ResourceManager* resourceManager, int rotation, Point* shapes);
};


#endif //TETRIS_CPP_GHOSTPIECE_H

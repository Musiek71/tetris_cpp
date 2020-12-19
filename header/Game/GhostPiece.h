//
// Created by musiek on 12/4/20.
//

#ifndef TETRIS_CPP_GHOSTPIECE_H
#define TETRIS_CPP_GHOSTPIECE_H

#include "Piece.h"

class GhostPiece : public Piece {
public:
    GhostPiece(std::string tileset, ResourceManager* resourceManager, int rotation, Point* shapes);
};


#endif //TETRIS_CPP_GHOSTPIECE_H

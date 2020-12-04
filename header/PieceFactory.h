//
// Created by musiek on 11/21/20.
//

#ifndef TETRIS_CPP_PIECEFACTORY_H
#define TETRIS_CPP_PIECEFACTORY_H


#include <vector>
#include "Piece.h"

class PieceFactory {
    std::vector<int> pieceVector;

    void fillVector();
public:
    PieceFactory();

    Piece* getPiece();
    Piece* getGhostPiece(Piece* currentPiece);

};


#endif //TETRIS_CPP_PIECEFACTORY_H

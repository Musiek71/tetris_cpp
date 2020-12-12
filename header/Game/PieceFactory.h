//
// Created by musiek on 11/21/20.
//

#ifndef TETRIS_CPP_PIECEFACTORY_H
#define TETRIS_CPP_PIECEFACTORY_H


#include <vector>
#include <random>
#include <chrono>
#include "Piece.h"
#include "../PieceEnum.h"
#include "IPiece.h"
#include "JPiece.h"
#include "LPiece.h"
#include "OPiece.h"
#include "TPiece.h"
#include "SPiece.h"
#include "ZPiece.h"
#include "GhostPiece.h"

class PieceFactory {
    std::vector<int> pieceVector;
    int defaultX;

    void fillVector();
public:
    PieceFactory(int defaultX);

    Piece* getPiece();
    Piece* getGhostPiece(Piece* currentPiece);

};


#endif //TETRIS_CPP_PIECEFACTORY_H

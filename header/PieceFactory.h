//
// Created by musiek on 11/21/20.
//

#ifndef TETRIS_CPP_PIECEFACTORY_H
#define TETRIS_CPP_PIECEFACTORY_H


#include <vector>
#include <random>
#include <chrono>
#include "Piece.h"
#include "../header/PieceEnum.h"
#include "../header/IPiece.h"
#include "../header/JPiece.h"
#include "../header/LPiece.h"
#include "../header/OPiece.h"
#include "../header/TPiece.h"
#include "../header/SPiece.h"
#include "../header/ZPiece.h"
#include "../header/GhostPiece.h"

class PieceFactory {
    std::vector<int> pieceVector;

    void fillVector();
public:
    PieceFactory();

    Piece* getPiece();
    Piece* getGhostPiece(Piece* currentPiece);

};


#endif //TETRIS_CPP_PIECEFACTORY_H

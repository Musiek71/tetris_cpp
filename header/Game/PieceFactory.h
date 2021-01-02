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

/**
 * The Piece Factory class implementing a simple factory pattern.
 *
 * Used to spawn random pieces on the board in a sequence.
 */
class PieceFactory {

    /**
     * Vector that holds all the pieces of a single sequence. The pieces are shuffled.
     */
    std::vector<int> pieceVector;

    /// The default X position the pieces are going to be spawned at.
    int defaultX;

    /**
     * Resource manager pointer.
     *
     * Holds a pointer to the main resource manager.
     */
    ResourceManager* resourceManager;

    /**
     * Fills the vector with all the possible pieces, then shuffles them to achieve a random order.
     */
    void fillVector();
public:

    /**
     * Default Piece Factory constructor.
     *
     * Sets the class fields and fills the vector.
     * @param defaultX
     * @param resourceManager
     */
    PieceFactory(int defaultX, ResourceManager* resourceManager);

    /**
     * Returns a single, random piece from the piece vector.
     *
     * Gets a single piece from the piece vector and removes it from the vector.
     * When the vector is empty, fills it with filLVector method.
     *
     * @return A pointer to the single, random piece.
     */
    Piece* getPiece();

    /**
     * Returns a ghost piece of a current piece.
     *
     * @param currentPiece The pointer to the piece the ghost piece we want to get.
     * @return A pointer to the ghost piece.
     */
    Piece* getGhostPiece(Piece* currentPiece);

};


#endif //TETRIS_CPP_PIECEFACTORY_H

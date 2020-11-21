//
// Created by musiek on 11/21/20.
//

#ifndef TETRIS_CPP_GAME_H
#define TETRIS_CPP_GAME_H


#include "Piece.h"
#include "Board.h"
#include "../header/LPiece.h"
#include "PieceFactory.h"


class Game {
private:
    PieceFactory pieceFactory;
    Board gameBoard;
    bool moveLeft(Piece* piece);
    bool moveRight(Piece* piece);
    bool rotateLeft(Piece* piece);
    bool rotateRight(Piece* piece);
    bool fallDown(Piece *piece);

public:
    Game();

    bool run();

};


#endif //TETRIS_CPP_GAME_H

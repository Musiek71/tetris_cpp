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
    PieceFactory pieceFactory;
    Board gameBoard;

public:
    bool run();

    Game();
};


#endif //TETRIS_CPP_GAME_H

//
// Created by musiek on 11/21/20.
//

#ifndef TETRIS_CPP_GAME_H
#define TETRIS_CPP_GAME_H


#include "Piece.h"
#include "Board.h"
#include "../header/LPiece.h"
#include "PieceFactory.h"
#include "../header/ScoreBoard.h"
#include <iostream>
#include "../header/NextBoard.h"


class Game {
private:
    int boardWidth;
    int boardHeight;
    PieceFactory* pieceFactory;
    Board* gameBoard;
    bool gameOver = false;
    int score = 0;
    int level = 1;
    int totalRows = 0;

    bool moveLeft(Piece *piece, Piece* ghostPiece);
    bool moveRight(Piece *piece, Piece* ghostPiece);
    bool rotateLeft(Piece *piece, Piece* ghostPiece);
    bool rotateRight(Piece *piece, Piece* ghostPiece);
    bool fallDown(Piece* piece);

    void setGhostPosition(Piece *currentPiece, Piece* ghostPiece);

    void updateScore(int clearedRows);
    void updateLevel();

public:
    Game(int boardWidth, int boardHeight);

    virtual ~Game();

    bool run();

};


#endif //TETRIS_CPP_GAME_H

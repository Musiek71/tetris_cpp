//
// Created by musiek on 11/21/20.
//

#ifndef TETRIS_CPP_GAME_H
#define TETRIS_CPP_GAME_H


#include "Piece.h"
#include "Board.h"
#include "LPiece.h"
#include "PieceFactory.h"
#include "ScoreBoard.h"
#include "../../header/StatesEnum.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include "NextBoard.h"


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
    float volume = 100;
    bool ghostFlag = true;

    int* gameStatePtr;
    int* scorePtr;
    int* levelPtr;

    sf::RenderWindow* window;
    sf::Font textFont;
    sf::Text pausedText;

    bool moveLeft(Piece *piece, Piece* ghostPiece);
    bool moveRight(Piece *piece, Piece* ghostPiece);
    bool rotateLeft(Piece *piece, Piece* ghostPiece);
    bool rotateRight(Piece *piece, Piece* ghostPiece);
    bool fallDown(Piece* piece);

    void setGhostPosition(Piece *currentPiece, Piece* ghostPiece);

    void updateScore(int clearedRows);
    void updateLevel();

public:
    Game(sf::RenderWindow* window, int boardWidth, int boardHeight, float volume, int* gameStatePtr, int* scorePtr, int* levelPtr, bool ghostFlag);

    virtual ~Game();

    bool run();

};


#endif //TETRIS_CPP_GAME_H

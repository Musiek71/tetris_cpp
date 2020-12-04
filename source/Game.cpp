//
// Created by musiek on 11/21/20.
//

#include "../header/Game.h"
#include <iostream>

bool Game::run() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Tetris");
    window.setVerticalSyncEnabled(true);

    if (!gameBoard.init("tileset.png", 32))
        return false;

    sf::Texture backgroundText;
    backgroundText.loadFromFile("background.png");
    sf::Sprite background;
    background.setTexture(backgroundText);

    Piece* currentPiece = pieceFactory.getPiece();
    Piece* nextPiece = pieceFactory.getPiece();
    nextPiece->setPiecePosition(BOARD_WIDTH + 2, 10);
//    Piece* ghostPiece =


    bool deltaFlag = false;
    float deltaTime = 0;

    sf::Clock clock;
    sf::Time time = clock.getElapsedTime();


    while (window.isOpen()) {

        if (gameOver) {
            break;
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
                //todo jedna funkcja
                if (event.key.code == sf::Keyboard::Left)
                    moveLeft(currentPiece);
                else if (event.key.code == sf::Keyboard::Right)
                    moveRight(currentPiece);
                else if (event.key.code == sf::Keyboard::Up)
                    (*currentPiece).setPiecePosition((*currentPiece).getPiecePosition().getX(), (*currentPiece).getPiecePosition().getY() - 1);
                else if (event.key.code == sf::Keyboard::Down)
                    fallDown(currentPiece);
                else if (event.key.code == sf::Keyboard::Z)
                    rotateLeft(currentPiece);
                else if (event.key.code == sf::Keyboard::X)
                    rotateRight(currentPiece);
            }
        }

        window.clear();
        window.draw(background);
        window.draw(gameBoard);
        window.draw(*currentPiece);
        window.draw(*nextPiece);
        window.display();

        time = clock.getElapsedTime();
        if (time.asSeconds() - deltaTime > 0.5) {
            clock.restart();
            if (!fallDown(currentPiece)) {
                gameOver = gameBoard.add(currentPiece);

                delete currentPiece;

                //swap pieces
                currentPiece = nextPiece;
                currentPiece->setPiecePosition(DEFAULT_X, DEFAULT_Y);
                //get new piece as the next piece
                nextPiece = pieceFactory.getPiece();
                nextPiece->setPiecePosition(BOARD_WIDTH + 2, 10);

                //getting number of cleared rows
                int clearedRows = gameBoard.updateBoard();
                totalRows += gameBoard.updateBoard();

//                updateScore(clearedRows);
//                updateLevel();



                //TODO score updating here i guess
            }

        }
    }

    return true;
}

Game::Game() {}

bool Game::moveLeft(Piece *piece) {
    if (!gameBoard.collidesWith(
            piece->getPiecePosition().getX() - 1,
            piece->getPiecePosition().getY(),
            piece->getCurrentShape())
            ) {
        piece->setPiecePosition(piece->getPiecePosition().getX() - 1, piece->getPiecePosition().getY());
        return true;
    }
    return false;
}

bool Game::moveRight(Piece *piece) {
    if (!gameBoard.collidesWith(
            piece->getPiecePosition().getX() + 1,
            piece->getPiecePosition().getY(),
            piece->getCurrentShape())
            ) {
        piece->setPiecePosition(piece->getPiecePosition().getX() + 1, piece->getPiecePosition().getY());
        return true;
    }
    return false;
}

bool Game::rotateLeft(Piece *piece) {
    if (!gameBoard.collidesWith(
            piece->getPiecePosition().getX(),
            piece->getPiecePosition().getY(),
            piece->getLeftRotationShape())
            ) {
        piece->rotateLeft();
        return true;
    }
    return false;
}

bool Game::rotateRight(Piece *piece) {
    if (!gameBoard.collidesWith(
            piece->getPiecePosition().getX(),
            piece->getPiecePosition().getY(),
            piece->getRightRotationShape())
            ) {
        piece->rotateRight();
        return true;
    }
    return false;
}

bool Game::fallDown(Piece *piece) {
    if (!gameBoard.collidesWith(
            piece->getPiecePosition().getX(),
            piece->getPiecePosition().getY() + 1,
            piece->getCurrentShape())
            ) {
        piece->setPiecePosition(piece->getPiecePosition().getX(), piece->getPiecePosition().getY() + 1);
        return true;
    }
    return false;
}

void Game::setGhostPosition(Piece *ghostPiece, Piece* currentPiece) {
    //set current ghost rotation the same as the current piece rotation
    ghostPiece->setRotation(currentPiece->getRotation());
    //set current ghost position the same as the current piece position
    ghostPiece->setPiecePosition(currentPiece->getPiecePosition());

    while (!gameBoard.collidesWith(ghostPiece->getPiecePosition().getX(),
                                   ghostPiece->getPiecePosition().getY(),
                                   ghostPiece->getCurrentShape())) {
        ghostPiece->setPiecePosition(ghostPiece->getPiecePosition().getX(),
                                     ghostPiece->getPiecePosition().getY() + 1);
    }
}





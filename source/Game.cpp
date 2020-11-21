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

    Piece* currentPiece = pieceFactory.getPiece();

    bool gameOver = false;
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
                    (*currentPiece).setPiecePosition((*currentPiece).getPiecePosition().getX(), (*currentPiece).getPiecePosition().getY() + 1);
                else if (event.key.code == sf::Keyboard::Z)
                    rotateLeft(currentPiece);
                else if (event.key.code == sf::Keyboard::X)
                    rotateRight(currentPiece);
            }
            clock.restart();
        }

        window.clear();
        window.draw(gameBoard);
        window.draw(*currentPiece);
        window.display();

        time = clock.getElapsedTime();
        if (time.asSeconds() - deltaTime > 0.5) {
            clock.restart();
            if (!fallDown(currentPiece)) {
                gameOver = gameBoard.add(currentPiece);

                delete currentPiece;
                currentPiece = pieceFactory.getPiece();

                int clearedRows = gameBoard.updateBoard();

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
            piece->getCurrentShape()) ||
            (piece->getPiecePosition().getY() < 0 &&
            piece->getPiecePosition().getX() > 1 &&
            piece->getPiecePosition().getX() < BOARD_WIDTH - 1)
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
            piece->getCurrentShape()) ||
            (piece->getPiecePosition().getY() < 0 &&
            piece->getPiecePosition().getX() > 1 &&
            piece->getPiecePosition().getX() < BOARD_WIDTH - 1)
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
            piece->getLeftRotationShape()) ||
            piece->getPiecePosition().getY() < 0
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
            piece->getRightRotationShape()) ||
            piece->getPiecePosition().getY() < 0
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
            piece->getCurrentShape()) ||
            piece->getPiecePosition().getY() < 0
            ) {
        piece->setPiecePosition(piece->getPiecePosition().getX(), piece->getPiecePosition().getY() + 1);
        return true;
    }
    return false;
}





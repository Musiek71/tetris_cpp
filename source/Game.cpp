//
// Created by musiek on 11/21/20.
//

#include "../header/Game.h"
#include "../header/LPiece.h"
#include "../header/OPiece.h"
#include <iostream>

bool Game::run() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Tetris");
    window.setVerticalSyncEnabled(true);

    if (!gameBoard.init("tileset.png", 32))
        return false;

    Piece& currentPiece = pieceFactory.getPiece();


    sf::Clock clock;
    float lastTime = 0;


    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
                //todo jedna funkcja
                if (event.key.code == sf::Keyboard::Left)
                    currentPiece.setPiecePosition(currentPiece.getPiecePosition().getX() - 1, currentPiece.getPiecePosition().getY());
                else if (event.key.code == sf::Keyboard::Right)
                    currentPiece.setPiecePosition(currentPiece.getPiecePosition().getX() + 1, currentPiece.getPiecePosition().getY());
                else if (event.key.code == sf::Keyboard::Up)
                    currentPiece.setPiecePosition(currentPiece.getPiecePosition().getX(), currentPiece.getPiecePosition().getY() - 1);
                else if (event.key.code == sf::Keyboard::Down)
                    currentPiece.setPiecePosition(currentPiece.getPiecePosition().getX(), currentPiece.getPiecePosition().getY() + 1);
                else if (event.key.code == sf::Keyboard::Z)
                    currentPiece.rotateLeft();
                else if (event.key.code == sf::Keyboard::X)
                    currentPiece.rotateRight();
                else if (event.key.code == sf::Keyboard::C) {
                    Point* nextRot = currentPiece.getLeftRotationShape();
                    for (int i = 0; i < 4; i++) {
                        nextRot[i].print();
                    }
                } else if (event.key.code == sf::Keyboard::V) {
                    Point* nextRot = currentPiece.getRightRotationShape();
                    for (int i = 0; i < 4; i++) {
                        nextRot[i].print();
                    }
                }

            }

        }

        window.clear();
        window.draw(gameBoard);
        window.draw(currentPiece);
        window.display();

        float currentTime = clock.restart().asSeconds();
        float fps = 1.f / currentTime;
        //std::cout << fps << std::endl;
        lastTime = currentTime;
    }

    return true;
}

Game::Game() {}

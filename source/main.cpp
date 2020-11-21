#include <iostream>
#include <SFML/Graphics.hpp>
#include "../header/Point.h"
#include "../header/Piece.h"
#include "../header/IPiece.h"
#include "../header/PieceEnum.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 800), "Tetris");
    window.setVerticalSyncEnabled(true);

    IPiece iPiece(0, IP);


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
                     iPiece.setPiecePosition(iPiece.getPiecePosition().getX() - 1, iPiece.getPiecePosition().getY());
                else if (event.key.code == sf::Keyboard::Right)
                    iPiece.setPiecePosition(iPiece.getPiecePosition().getX() + 1, iPiece.getPiecePosition().getY());
                else if (event.key.code == sf::Keyboard::Up)
                    iPiece.setPiecePosition(iPiece.getPiecePosition().getX(), iPiece.getPiecePosition().getY() - 1);
                else if (event.key.code == sf::Keyboard::Down)
                    iPiece.setPiecePosition(iPiece.getPiecePosition().getX(), iPiece.getPiecePosition().getY() + 1);
                else if (event.key.code == sf::Keyboard::Z)
                    iPiece.rotateLeft();
                else if (event.key.code == sf::Keyboard::X)
                    iPiece.rotateRight();
                else if (event.key.code == sf::Keyboard::C) {
                    Point* nextRot = iPiece.getLeftRotationShape();
                    for (int i = 0; i < 4; i++) {
                        nextRot[i].print();
                    }
                } else if (event.key.code == sf::Keyboard::V) {
                    Point* nextRot = iPiece.getRightRotationShape();
                    for (int i = 0; i < 4; i++) {
                        nextRot[i].print();
                    }
                }

            }

        }

        window.clear();
        window.draw(iPiece);
        window.display();
    }



    return 0;
}

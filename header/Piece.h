//
// Created by musiek on 16.11.2020.
//

#ifndef TETRIS_CPP_PIECE_H
#define TETRIS_CPP_PIECE_H


#include <SFML/Graphics.hpp>
#include "Point.h"

class Piece : public sf::Drawable, public sf::Transformable {
private:
    Point piecePosition;
    int rotation{0};
    int currentShapeInt{0};
    Point shape[4];
    Point shapes[4][4];

    sf::Texture tileSet;
    sf::Sprite tileSprite[4];

    void setCurrentShape();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:

    Piece(std::string tileset, int rotation, int currentShapeInt, Point shapes[4][4]);

    void setShapes(Point shapes[4][4]);

    int getRotation() const;

    void setRotation(int rotation);

    const Point getPiecePosition() const;

    void setPiecePosition(int x, int y);
    void setPiecePosition(Point x);
    void setPiecePosition();

    void rotateLeft();
    void rotateRight();

    Point* getCurrentShape();
    Point* getLeftRotationShape();
    Point* getRightRotationShape();
};


#endif //TETRIS_CPP_PIECE_H

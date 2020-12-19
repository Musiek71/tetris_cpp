//
// Created by musiek on 16.11.2020.
//

#ifndef TETRIS_CPP_PIECE_H
#define TETRIS_CPP_PIECE_H


#include <SFML/Graphics.hpp>
#include "Point.h"
#include "../ResourceManager.h"

#define DEFAULT_Y 0

/**
 * Default Piece class representing a single tetromino
 */
class Piece : public sf::Drawable, public sf::Transformable {
private:
    /**
     * Current piece position
     */
    Point piecePosition;
    int rotation{0};
    int currentShapeInt{0};
    Point shape[4];
    Point shapes[4][4];

    ResourceManager* resourceManager;

    sf::Texture* tilesetPtr;
    sf::Sprite tileSprite[4];

    void setCurrentShape();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:

    Piece(std::string tileset, ResourceManager* resourceManager, int rotation, int currentShapeInt, Point* shapes, int spawnX = 4);

    void setShapes(Point* shapes);

    Point* const getShapes() const;

    int getRotation() const;

    int getCurrentShapeInt() const;

    void setRotation(int rotation);

    const Point getPiecePosition() const;

    void setPiecePosition(int x, int y, bool fixedToBoard);
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

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
 * Default Piece class representing a single tetromino.
 */
class Piece : public sf::Drawable, public sf::Transformable {
private:
    /// Current piece position on the board. Holds the position of the piece's center/main point.
    Point piecePosition;

    /**
     * Piece's current rotation.
     *
     * Each piece has 4 possible rotations, each rotation is held in the Point shapes[] array.
     */
    int rotation{0};

    /// Current shape represented by PieceEnum.
    int currentShapeInt{0};

    /// Current shape(rotation) held in 4 points, one of 4 possible rotations held in shapes[].
    Point shape[4];

    /**
     * Main shapes array.
     *
     * Each array
     */
    Point shapes[4][4];

    /**
     * Resource manager pointer.
     *
     * Holds a pointer to the main resource manager.
     */
    ResourceManager* resourceManager;

    /// Texture pointer.
    sf::Texture* tilesetPtr;

    /**
     * An array of SFML sprites representing a piece.
     *
     * An array of 4 SFML sprites representing current piece shape on the board.
     * Its texture depends on currentShapeInt, and positions dependent on current shape[] and piecePosition.
     */
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

    void rotateLeft();
    void rotateRight();

    Point* getCurrentShape();
    Point* getLeftRotationShape();
    Point* getRightRotationShape();
};


#endif //TETRIS_CPP_PIECE_H

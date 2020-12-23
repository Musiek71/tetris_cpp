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
     * Piece's main shapes array.
     *
     * Holds the 4x4 array of Points, representing 4 possible rotations of the piece, where each rotation has 4 points.
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


    /**
     * Sets current piece shape to the shape determined by the piece's rotation field.
     *
     * Sets each of shape's 4 points to the shape determined by piece's rotation field.
     */
    void setCurrentShape();

    /// Implementation of the SFML's draw interface.
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:

    /**
     * Main Piece constructor.
     *
     * The constructor isn't directly used anywhere in the game. Instead, each of the piece's derived classes represents
     * a new piece. Creating a new object of any derived class invokes the constructor of the base class, with predefined
     * values (piece's shapes, rotation, currentShapeInt defining the piece's texture,...).
     *
     * @param tileset Name of the tileset file.
     * @param resourceManager Pointer to the program's resource manager.
     * @param rotation Piece's current rotation.
     * @param currentShapeInt Piece's individual number represented by the PieceEnum.
     * @param shapes The shapes array holding piece's every rotation (Point* array).
     * @param spawnX Piece's X spawning position (4 by default).
     */
    Piece(std::string tileset, ResourceManager* resourceManager, int rotation, int currentShapeInt, Point* shapes, int spawnX = 4);

    /**
     * Copies the shapes from newShapes to the piece's shapes field.
     *
     * @param newShapes Shapes array.
     */
    void setShapes(Point* newShapes);

    /**
     * Returns the pointer to the piece's shapes field.
     *
     * @return Shapes pointer.
     */
    Point* const getShapes() const;

    /**
     * Returns piece's current rotation (int from 0 to 3).
     *
     * @return Piece's rotation
     */
    int getRotation() const;

    /**
     * Sets piece's rotation to the desired one.
     *
     * @param rotation Piece's desired rotation.
     */
    void setRotation(int rotation);

    /**
     * Returns piece's current shape int represented by PieceEnum.
     *
     * @return Current shape represented by PieceEnum.
     */
    int getCurrentShapeInt() const;

    /**
     * Returns piece's current position on the board.
     * @return Point with the piece's coordinates on the map.
     */
    const Point getPiecePosition() const;

    /**
     * Sets piece's position to desired x and y parameters. Sets piece's 4 sprites representing the tetromino to the
     * desired x and y parameters. The sprites' positions are multiplied by 32 pixels, as 32 pixels is the default
     * size of the game's tile. Depending on the fixedToBoard parameter, sprites' positions on the screen are moved
     * by the board's X and Y offsets automatically, so coordinates relative to the beginning of the game board
     * can be used.
     *
     * @param x The X coordinate of the piece.
     * @param y The Y coordinate of the piece.
     * @param fixedToBoard Piece's sprites will be moved according to the board's position on the screen automatically.
     */
    void setPiecePosition(int x, int y, bool fixedToBoard);

    /**
     * Sets piece's position to desired x and y parameters. Sets piece's 4 sprites representing the tetromino to the
     * desired x and y parameters. The sprites' positions are multiplied by 32 pixels, as 32 pixels is the default
     * size of the game's tile. Depending on the fixedToBoard parameter, sprites' positions on the screen are moved
     * by the board's X and Y offsets automatically, so coordinates relative to the beginning of the game board
     * can be used. fixedToBoard parameter is true by default.
     *
     * @param x The X coordinate of the piece.
     * @param y The Y coordinate of the piece.
     */
    void setPiecePosition(int x, int y);

    /**
     * Sets piece's position to desired x and y parameters. Sets piece's 4 sprites representing the tetromino to the
     * desired x and y parameters. The sprites' positions are multiplied by 32 pixels, as 32 pixels is the default
     * size of the game's tile. Depending on the fixedToBoard parameter, sprites' positions on the screen are moved
     * by the board's X and Y offsets automatically, so coordinates relative to the beginning of the game board
     * can be used. fixedToBoard parameter is true by default.
     *
     * @param x A Point class representing x and y coordinates,
     */
    void setPiecePosition(Point x);

    /**
     * Rotates the piece left.
     *
     * Depending on piece's current rotation, calculates the next left rotation, sets it and changes piece's and sprites'
     * shape and positions.
     */
    void rotateLeft();

    /**
     * Rotates the piece right.
     *
     * Depending on piece's current rotation, calculates the next right rotation, sets it and changes piece's and sprites'
     * shape and positions.
     */
    void rotateRight();

    /**
     * Returns a pointer to piece's current shape array.
     * @return Point* arr of length 4 containing piece's current shape.
     */
    Point* getCurrentShape();

    /**
     * Returns a pointer to piece's left rotation shape (if piece rotates left, it'll apply this shape).
     * @return Point* arr of length 4 containing piece's left rotation shape.
     */
    Point* getLeftRotationShape();

    /**
     * Returns a pointer to piece's right rotation shape (if piece rotates right, it'll apply this shape).
     * @return Point* arr of length 4 containing piece's right rotation shape.
     */
    Point* getRightRotationShape();
};


#endif //TETRIS_CPP_PIECE_H

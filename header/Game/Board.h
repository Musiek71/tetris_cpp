//
// Created by musiek on 11/21/20.
//

#ifndef TETRIS_CPP_BOARD_H
#define TETRIS_CPP_BOARD_H


#include <SFML/Graphics.hpp>
#include "../PieceEnum.h"
#include "Point.h"
#include "Piece.h"


/// Default game board's Y offset, hides 3 invisible rows used for piece spawning.
#define DEFAULT_Y_OFFSET 3 * 32

/// Y offset of the baord on the screen
#define Y_OFFSET 3 * 32 //board's Y offset on the screen

/// X offset of the board on the screen
#define X_OFFSET 3 * 32 //board's X offset on the screen

class Board : public sf::Drawable, sf::Transformable {
private:
    /// Width of the game board.
    int boardWidth;

    /// Height of the game board.
    int boardHeight;

    /**
     * Double pointer to the dynamically allocated 2D array representing the board.
     *
     * The board is initialized in the constructor - the memory is allocated and the walls are set.
     */
    int** board;

    /**
     * Resource manager pointer.
     *
     * Holds a pointer to the main resource manager.
     */
    ResourceManager* resourceManager;

    /// A pointer to the tileset texture received from the resource manager.
    sf::Texture* tilesetPtr;

    /**
     * SFML VertexArray that holds the vertices representing the board. It's 4 times the size of the board.
     *
     * Every board's tile is represented by 4 vertices(quads), and then the wall these vertices make is textured
     * depending on the board's state - what piece is held on current board's tile (PieceEnum).
     */
    sf::VertexArray vertices;

    /**
     * Updates the texture of the board's single tile.
     *
     * Updates/switches the texture of the tile under piecePos + shapePoint. PiecePos is the position of the piece (piece's left corner)
     * on the board, and shapePoint is the position of each point representing a single shape. This approach allows us to
     * use the method with a single piecePos and every shapePoint in a simple for in the 'add' method, adding the whole
     * piece.
     * ShapeInt is represented by the PieceEnum and defines the piece's texture being set on the board/screen.
     * TileSize is used to find the right texture square on the tileset texture (shapeInt * tileSize).
     *
     * @param piecePos Position of the piece on the board, represented by Point.
     * @param shapePoint Position of the shape's current point, relative to the piecePos (piece's left corner). Represented by Point.
     * @param shapeInt Current shape (PieceEnum).
     * @param tileSize The size of a single tile on a tileset texture.
     */
    void updateTexture(Point piecePos, Point shapePoint, int shapeInt, int tileSize);


    void updateAllTextures(int tileSize);

public:
    Board(int boardWidth, int boardHeight, ResourceManager* resourceManager);

    virtual ~Board();

    bool init(std::string tileset, int tileSize);

    bool collidesWith(int x, int y, Point* shape);

    bool add(Piece *piece);

    int updateBoard();

    void pushRowDown(int row);

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //TETRIS_CPP_BOARD_H

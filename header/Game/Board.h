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

    /**
     * Updates all the textures of the board.
     *
     * Iterates through all the vertices in the vertices field and updates every quad's positions (crucial for proper drawing)
     * and used texture's position in the tileset, depending on shapeInt read from the board 2D array.
     *
     * @param tileSize Size of a single tile on a tileset texture.
     */
    void updateAllTextures(int tileSize);

public:
    /**
     * Main Board constructor.
     *
     * The main constructor, allocates the board's memory and initializes it with walls and empty spaces from PieceEnum.
     *
     * @param boardWidth The board's width, including the side walls.
     * @param boardHeight The board's height, including the top piece spawning rows and bottom wall row.
     * @param resourceManager Pointer to the program's resource manager.
     */
    Board(int boardWidth, int boardHeight, ResourceManager* resourceManager);

    /**
     * Board's main destructor.
     *
     * Frees the memory allocated for the board.
     */
    virtual ~Board();

    /**
     * Initialization of the board.
     *
     * Creates the vertex array representing the board in SFML library. Gets the texture from the main resource
     * manager using the tileset parameter, then adds a texture rectangle to every quad of the vertex array using
     * the UpdateAllTextures method.
     *
     * @param tileset Name of the tileset texture.
     * @param tileSize Size of a single tile on a tileset texture.
     */
    void init(std::string tileset, int tileSize);

    /**
     * Main collision checking method.
     *
     * Checks, whether the piece at certain coordinates collides/would collide with pieces already existing on the board (or walls).
     * It takes absolute x and y values (position), and then checks every point of the shape.
     * Returns true, if any of the point collides with existing board.
     * Returns false, if none of the points collides.
     *
     * @param x The absolute x position of the piece on the board.
     * @param y The absolute y positison of the piece on the board.
     * @param shape The Point array containing the current shape of the piece.
     * @return True if collides, otherwise false.
     */
    bool collidesWith(int x, int y, Point* shape);

    /**
     * Adds a single piece to the board.
     *
     * Adds the piece to the board, using its coordinates, then updates the board's texture.
     * Returns, whether the game is over - the Y position of any of the piece's points is less than 3 (rows intended
     * for piece spawning).
     * Returns false, if game's over (piece was added in the illegal zone).
     * Returns true, if piece was added successfully.
     *
     * @param piece The piece to add to the board.
     * @return True if piece was added successfully, false if game's over.
     */
    bool add(Piece *piece);

    /**
     * Updates the board, clearing all full rows.
     *
     * Updates the board, beginning from the very bottom of the board. Searches for any full rows and when found,
     * increases the cleared rows counter and pushes the board one row down (removing the counted full row).
     *
     * @return The number of cleared full rows.
     */
    int updateBoard();

    /**
     * Pushes all the rows above the removed row down, then updates the textures depending on the board's state.
     *
     * @param row The number of the row to be removed/pushed down/cleared.
     */
    void pushRowDown(int row);

protected:
    /// Implementation of the SFML's draw interface.
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //TETRIS_CPP_BOARD_H

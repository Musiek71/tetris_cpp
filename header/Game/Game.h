//
// Created by musiek on 11/21/20.
//

#ifndef TETRIS_CPP_GAME_H
#define TETRIS_CPP_GAME_H


#include "Piece.h"
#include "Board.h"
#include "LPiece.h"
#include "PieceFactory.h"
#include "ScoreBoard.h"
#include "../../header/StatesEnum.h"
#include <SFML/Audio.hpp>
#include "NextBoard.h"

/**
 * The Game class implementing a single game of tetris. Sews the whole game implementation together.
 */
class Game {
private:
    /// Width of the game board.
    int boardWidth;

    /// Height of the game board.
    int boardHeight;

    /// A pointer to the game's PieceFactory, used to spawn pieces.
    PieceFactory* pieceFactory;

    /// A pointer to the game's Board.
    Board* gameBoard;

    /// Game Over flag.
    bool gameOver = false;

    /// Game's score.
    int score = 0;

    /// Game's level.
    int level = 1;

    /// The number of total cleared rows. Used for game level counting.
    int totalRows = 0;

    /// The game's sound volume.
    float volume = 50;

    /// Flag used to determine, whether to draw ghost piece.
    bool ghostFlag = true;

    /**
     * Resource manager pointer.
     *
     * Holds a pointer to the main resource manager.
     */
    ResourceManager* resourceManager;

    /// A pointer to the main game state variable.
    int* gameStatePtr;

    /// A pointer to the main score variable.
    int* scorePtr;

    /// A pointer to the main level variable.
    int* levelPtr;

    /// A pointer to the SFML's window variable.
    sf::RenderWindow* window;

    /// A pointer to the font from the resource manager.
    sf::Font* textFontPtr;

    /// The variable for the text shown, when the game is paused.
    sf::Text pausedText;

    /**
     * Moves the piece and the piece's ghost by one to left on the board, if possible.
     * Returns true, if moved successfully, false if the movement wasn't possible (collision).
     *
     * @param piece A pointer to the piece to be moved left.
     * @param ghostPiece A pointer to the ghost of the piece.
     * @return True if successfully moved, false if the piece collided.
     */
    bool moveLeft(Piece *piece, Piece* ghostPiece);

    /**
     * Moves the piece and the piece's ghost by one to right on the board, if possible.
     * Returns true, if moved successfully, false if the movement wasn't possible (collision).
     *
     * @param piece A pointer to the piece to be moved right.
     * @param ghostPiece A pointer to the ghost of the piece.
     * @return True if successfully moved, false if the piece collided.
     */
    bool moveRight(Piece *piece, Piece* ghostPiece);

    /**
     * Rotates the piece and the piece's ghost left on the board, if possible.
     * Returns true, if rotated successfully, false if the rotation wasn't possible (collision).
     *
     * @param piece A pointer to the piece to be rotated left.
     * @param ghostPiece A pointer to the ghost of the piece.
     * @return True if successfully rotated, false if the piece collided.
     */
    bool rotateLeft(Piece *piece, Piece* ghostPiece);

    /**
     * Rotates the piece and the piece's ghost right on the board, if possible.
     * Returns true, if rotated successfully, false if the rotation wasn't possible (collision).
     *
     * @param piece A pointer to the piece to be rotated right.
     * @param ghostPiece A pointer to the ghost of the piece.
     * @return True if successfully rotated, false if the piece collided.
     */
    bool rotateRight(Piece *piece, Piece* ghostPiece);

    /**
     * Falls the piece down on the board by one.
     * Returns true, if rotated successfully, false if the rotation wasn't possible (collision).
     *
     * @param piece The piece to moved down by one.
     * @param ghostPiece The ghost of the piece.
     * @return True if successfully moved down by one, false if piece collided.
     */
    bool fallDown(Piece* piece);

    /**
     * Sets the position of the piece's ghost, according to the current piece's position.
     *
     * The piece's ghost has the same X position, but the Y position represents the position where the piece
     * is going to land on the board.
     *
     * @param currentPiece A pointer to the current piece.
     * @param ghostPiece A pointer to the current piece's ghost.
     */
    void setGhostPosition(Piece *currentPiece, Piece* ghostPiece);

    /**
     * Increases the game's score field according to the number of cleared rows.
     * The higher the number of cleared rows, the bigger the score increase.
     *
     * @param clearedRows The number of cleared rows.
     */
    void updateScore(int clearedRows);

    /**
     * Updates the level field, depending on the number of total rows cleared.
     */
    void updateLevel();

public:

    /**
     * The main game constructor.
     *
     * Initializes the class fields, the game board and the piece factory.
     *
     * @param window A pointer to SFML window.
     * @param boardWidth The board's width, excluding the side walls.
     * @param boardHeight The board's height, excluding the bottom wall and rows for piece spawning.
     * @param volume The number representing the game's volume, in percents.
     * @param gameStatePtr A pointer to the main game state.
     * @param scorePtr A pointer to the main score variable.
     * @param levelPtr A pointer to the main level variable.
     * @param ghostFlag Flag determining whether to draw piece's ghost on the screen.
     * @param resourceManager A pointer to the main resource manager.
     */
    Game(sf::RenderWindow* window, int boardWidth, int boardHeight, float volume, int* gameStatePtr, int* scorePtr,
         int* levelPtr, bool ghostFlag, ResourceManager* resourceManager);

    /**
     * Game's destructor.
     *
     * Frees memory allocated for the board and piece factory.
     */
    virtual ~Game();

    /**
     * Game's main loop.
     *
     * Takes care of the whole game sequence.
     */
    void run();

};


#endif //TETRIS_CPP_GAME_H

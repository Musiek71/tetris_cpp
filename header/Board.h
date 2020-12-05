//
// Created by musiek on 11/21/20.
//

#ifndef TETRIS_CPP_BOARD_H
#define TETRIS_CPP_BOARD_H


#include <SFML/Graphics.hpp>
#include "../header/PieceEnum.h"
#include "Point.h"
#include "Piece.h"


#define BOARD_WIDTH 12 //do modyfikacji w grze
#define BOARD_HEIGHT 24
#define DEFAULT_Y_OFFSET 3 * 32 //default offset hides 3 invisible rows used for piece spawning
#define Y_OFFSET 3 * 32
#define X_OFFSET 3 * 32

class Board : public sf::Drawable, sf::Transformable {
private:
    int board[BOARD_WIDTH][BOARD_HEIGHT];

    sf::Texture tileSet;
    sf::VertexArray vertices;

    void updateTexture(Point piecePos, Point shapePoint, int currentShapeInt, int tileSize);
    void updateAllTextures(int tileSize);

public:
    Board();

    bool init(std::string tileset, int tileSize);

    bool collidesWith(int x, int y, Point* shape);

    bool add(Piece *piece);

    int updateBoard();

    void pushRowDown(int row);

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //TETRIS_CPP_BOARD_H

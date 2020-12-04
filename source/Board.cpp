//
// Created by musiek on 11/21/20.
//

#include <iostream>
#include "../header/Board.h"

bool Board::init(std::string tileset, int tileSize) {
    if (!tileSet.loadFromFile(tileset))
        return false;

    //set offset
    this->setPosition(X_OFFSET, -DEFAULT_Y_OFFSET + Y_OFFSET);

    //resize the vertex array
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(BOARD_WIDTH * BOARD_HEIGHT * 4);

    //initializing textures
    updateAllTextures(32);

    return true;
}

void Board::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();

    states.texture = &tileSet;

    target.draw(vertices, states);
}

Board::Board() {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            if (i == 0 || i == BOARD_WIDTH - 1 || j == BOARD_HEIGHT - 1) {
                board[i][j] = WALL;
            } else {
                board[i][j] = NONE;
            }
        }
    }
}

bool Board::collidesWith(int x, int y, Point *shape) {
    for (int i = 0; i < 4; i++) {
        if (this->board[x + shape[i].getX()][y + shape[i].getY()] != 0) {
            return true;
        }
    }
    return false;
}

bool Board::add(Piece *piece) {
    for (int i = 0; i < 4; i++) {
        if (piece->getPiecePosition().getY() + piece->getCurrentShape()[i].getY() < 3)
            return true;
        board[piece->getPiecePosition().getX() + piece->getCurrentShape()[i].getX()][piece->getPiecePosition().getY() + piece->getCurrentShape()[i].getY()] = piece->getCurrentShapeInt();
        updateTexture(piece->getPiecePosition(), piece->getCurrentShape()[i], piece->getCurrentShapeInt(), 32);
    }
    return false;
}

void Board::updateTexture(Point piecePos, Point shapePoint, int tileNumber, int tileSize) {
    sf::Vertex* quad = &vertices[(piecePos.getX() + shapePoint.getX() + (piecePos.getY() + shapePoint.getY())* BOARD_WIDTH) * 4];
    quad[0].texCoords = sf::Vector2f(tileNumber * tileSize, 0);
    quad[1].texCoords = sf::Vector2f((tileNumber + 1) * tileSize, 0);
    quad[2].texCoords = sf::Vector2f((tileNumber + 1) * tileSize, tileSize);
    quad[3].texCoords = sf::Vector2f(tileNumber * tileSize, tileSize);
}

int Board::updateBoard() {
    bool foundFullRow = true;
    int lineCounter = 0;

    for (int y = BOARD_HEIGHT - 2; y > 0; y--) {
        foundFullRow = true;
        for (int x = 1; x < BOARD_WIDTH - 1; x++) {
            if (board[x][y] == 0)
                foundFullRow = false;
        }
        if (foundFullRow) {
            pushRowDown(y);
            lineCounter++;
            y++;
        }
    }
    return lineCounter;
}

void Board::pushRowDown(int row) {
    for (int y = row; y > 0; y--) {
        for (int x = 1; x < BOARD_WIDTH - 1; x++) {
            board[x][y] = board[x][y - 1];
            updateAllTextures(32);
        }
    }
}

void Board::updateAllTextures(int tileSize) {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        //editing j here modifies the number of visible walls, default is 3 rows for piece spawning
        for (int j = DEFAULT_Y_OFFSET / 32; j < BOARD_HEIGHT; j++) {
            //get the tileNumber
            int tileNumber = board[i][j];

            //get the pointer to the current quad
            sf::Vertex* quad = &vertices[(i + j * BOARD_WIDTH) * 4];

            //define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize, j * tileSize);
            quad[1].position = sf::Vector2f((i + 1) * tileSize, j * tileSize);
            quad[2].position = sf::Vector2f((i + 1) * tileSize, (j + 1) * tileSize);
            quad[3].position = sf::Vector2f(i * tileSize, (j + 1) * tileSize);

            //define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tileNumber * tileSize, 0);
            quad[1].texCoords = sf::Vector2f((tileNumber + 1) * tileSize, 0);
            quad[2].texCoords = sf::Vector2f((tileNumber + 1) * tileSize, tileSize);
            quad[3].texCoords = sf::Vector2f(tileNumber * tileSize, tileSize);
        }
    }
}

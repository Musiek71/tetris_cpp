//
// Created by musiek on 11/21/20.
//

#include "../header/Board.h"

bool Board::init(std::string tileset, int tileSize) {
    if (!tileSet.loadFromFile(tileset))
        return false;

    //resize the vertex array
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(BOARD_WIDTH * BOARD_HEIGHT * 4);

    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
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

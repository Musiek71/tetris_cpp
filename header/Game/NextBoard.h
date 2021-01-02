//
// Created by musiek on 12/6/20.
//

#ifndef TETRIS_CPP_NEXTBOARD_H
#define TETRIS_CPP_NEXTBOARD_H

#include <SFML/Graphics.hpp>
#include "Piece.h"
#include <iostream>

/**
 * Class representing the Next Board.
 */
class NextBoard : public sf::Drawable, sf::Transformable{
private:

    /// Position of the next board on the screen.
    Point position;

    /// SFML sprite as a background.
    sf::Sprite background;

    /// A pointer to the background texture.
    sf::Texture* texture;

    /// A pointer to the next Piece.
    Piece* piece;

    /// A size of a single tile.
    int tileSize;

public:

    /**
     * Main constructor.
     *
     * Sets class fields, their positions, loads the resources from the resourceManager.
     *
     * @param textfilename The name of the background texture.
     * @param resourceManager A pointer to the main resource manager.
     * @param piece A pointer to the next Piece.
     * @param x The X position of the next board on the screen.
     * @param y The Y position of the next board on the screen.
     * @param tileSize A size of a single tile.
     */
    NextBoard(std::string textfilename, ResourceManager* resourceManager, Piece* piece, int x, int y, int tileSize);

    /**
     * Sets the next board's piece to be drawn as a next one.
     *
     * @param piece A pointer to the piece to be drawn as a next one
     */
    void setPiece(Piece* piece);

protected:
    /// Implementation of the SFML draw interface.
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //TETRIS_CPP_NEXTBOARD_H

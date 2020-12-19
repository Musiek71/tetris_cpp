//
// Created by musiek on 12/6/20.
//

#ifndef TETRIS_CPP_NEXTBOARD_H
#define TETRIS_CPP_NEXTBOARD_H

#include <SFML/Graphics.hpp>
#include "Piece.h"
#include <iostream>

class NextBoard : public sf::Drawable, sf::Transformable{
private:
    sf::Sprite background;
    sf::Texture* texture;
    Piece* piece;
    Point position;
    int tileSize;

public:
    NextBoard(std::string textfilename, ResourceManager* resourceManager, Piece* piece, int x, int y, int tileSize);

    void setPiece(Piece* piece);

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //TETRIS_CPP_NEXTBOARD_H

//
// Created by musiek on 12/6/20.
//

#include "../../header/Game/NextBoard.h"

NextBoard::NextBoard(std::string textfilename, Piece *piece, int x, int y, int tileSize) {
    if (!texture.loadFromFile(textfilename)) {
        std::cout << "Scoreboard texture:"<< textfilename <<  " loading failed." << std::endl;
    }
    background.setTexture(texture);
    background.setPosition(x, y);

    this->tileSize = tileSize;

    this->position.setPos(x, y);

    this->piece = piece;
    this->piece->setPiecePosition(x / tileSize + 1, y / tileSize + 2, false);

}

void NextBoard::setPiece(Piece *piece) {
    this->piece = piece;
    this->piece->setPiecePosition(position.getX()/tileSize + 1, position.getY()/tileSize + 2, false);
}

void NextBoard::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(background);
    target.draw(*piece);
}

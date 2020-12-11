//
// Created by musiek on 11/21/20.
//

#include "../header/PieceFactory.h"

PieceFactory::PieceFactory() {
    fillVector();
}

void PieceFactory::fillVector() {
    this->pieceVector.push_back(IP);
    this->pieceVector.push_back(OP);
    this->pieceVector.push_back(TP);
    this->pieceVector.push_back(JP);
    this->pieceVector.push_back(LP);
    this->pieceVector.push_back(SP);
    this->pieceVector.push_back(ZP);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(this->pieceVector.begin(), this->pieceVector.end(), std::default_random_engine(seed));
}

Piece* PieceFactory::getPiece() {
    if (pieceVector.size() == 0)
        fillVector();
    int random = pieceVector[0];
    pieceVector.erase(pieceVector.begin(), pieceVector.begin()+1);
    Piece* ptr;
    switch(random) {
        case 2:
            ptr = new IPiece("tileset.png", 0);
            break;
        case 3:
            ptr = new JPiece("tileset.png", 0);
            break;
        case 4:
            ptr = new LPiece("tileset.png", 0);
            break;
        case 5:
            ptr = new OPiece("tileset.png", 0);
            break;
        case 6:
            ptr = new SPiece("tileset.png", 0);
            break;
        case 7:
            ptr = new TPiece("tileset.png", 0);
            break;
        case 8:
            ptr = new ZPiece("tileset.png", 0);
            break;
    }

    return ptr;
}

Piece *PieceFactory::getGhostPiece(Piece *currentPiece) {
    return new GhostPiece("tileset.png", currentPiece->getRotation(), currentPiece->getShapes());
}

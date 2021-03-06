//
// Created by musiek on 11/21/20.
//

#include "../../header/Game/PieceFactory.h"

PieceFactory::PieceFactory(int defaultX, ResourceManager* resourceManager) {
    this->defaultX = defaultX;
    this->resourceManager = resourceManager;
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
    if (pieceVector.empty())
        fillVector();
    int random = pieceVector[0];
    pieceVector.erase(pieceVector.begin(), pieceVector.begin()+1);
    Piece* ptr;
    switch(random) {
        case 2:
            ptr = new IPiece("tileset.png", resourceManager, 0, defaultX);
            break;
        case 3:
            ptr = new JPiece("tileset.png", resourceManager, 0, defaultX);
            break;
        case 4:
            ptr = new LPiece("tileset.png", resourceManager, 0, defaultX);
            break;
        case 5:
            ptr = new OPiece("tileset.png", resourceManager, 0, defaultX);
            break;
        case 6:
            ptr = new SPiece("tileset.png", resourceManager, 0, defaultX);
            break;
        case 7:
            ptr = new TPiece("tileset.png", resourceManager, 0, defaultX);
            break;
        case 8:
            ptr = new ZPiece("tileset.png", resourceManager, 0, defaultX);
            break;
    }

    return ptr;
}

Piece *PieceFactory::getGhostPiece(Piece *currentPiece) {
    return new GhostPiece("tileset.png", resourceManager, currentPiece->getRotation(), currentPiece->getShapes());
}

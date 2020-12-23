//
// Created by musiek on 16.11.2020.
//

#include "../../header/Game/Piece.h"
#include "../../header/Game/Board.h"

Piece::Piece(std::string tileset, ResourceManager* resourceManager, int rotation, int currentShapeInt, Point* shapes, int spawnX) : rotation(rotation), currentShapeInt(currentShapeInt) {
    //Main piece initialization

    //copy shapes to the shapes array.
    setShapes(shapes);

    //set starting position
    this->piecePosition.setPos(spawnX, DEFAULT_Y);

    //set the resource manager and get the texture with the tileset
    this->resourceManager = resourceManager;
    tilesetPtr = resourceManager->getTexture(tileset);

    //init of four sprites representing piece
    for (int i = 0; i < 4; i++) {
        //set the texture rectangle for each SFML sprite depending on the current shape enum.
        tileSprite[i].setTextureRect(sf::IntRect(32 * currentShapeInt, 0, 32, 32));
        tileSprite[i].setTexture(*tilesetPtr);
        //set SFML sprite's position on the screen
        tileSprite[i].setPosition((piecePosition.getX() + shape[i].getX()) * 32 + X_OFFSET,
                                  (piecePosition.getY() + shape[i].getY()) * 32 + Y_OFFSET - DEFAULT_Y_OFFSET
        );
    }

}

void Piece::setShapes(Point* newShapes) {
    //copying shapes to the class field
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            this->shapes[i][j] = newShapes[i * 4 + j];
        }
    }
    setCurrentShape();
}

void Piece::setCurrentShape() {
    //setting four sprites to the shape determined by rotation field
    for (int i = 0; i < 4; i++) {
        this->shape[i] = shapes[rotation][i];
    }
}

void Piece::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    //for each of 4 SFML sprites, draw the sprite at certain coordinates.
    for (int i = 0; i < 4; i++) {
        //condition for drawing the piece lower
        //3 * 32 is the default offset used for piece spawning
        if (tileSprite[i].getPosition().y >= Y_OFFSET)
            target.draw(tileSprite[i], states);
    }
}

const Point Piece::getPiecePosition() const {
    return piecePosition;
}

void Piece::setPiecePosition(int x, int y, bool fixedToBoard) {
    //set piece's position
    Piece::piecePosition.setX(x);
    Piece::piecePosition.setY(y);
    //set sprites' positions, depending on the fixedToBoard parameter
    for (int i = 0; i < 4; i++) {
        // if fixedToBoard, use coordinates relative to the game board's beginning
        if (fixedToBoard)
            tileSprite[i].setPosition((piecePosition.getX() + shape[i].getX()) * 32 + X_OFFSET,
                                      (piecePosition.getY() + shape[i].getY()) * 32 + Y_OFFSET - DEFAULT_Y_OFFSET
            );
        else
            tileSprite[i].setPosition((piecePosition.getX() + shape[i].getX()) * 32,
                                      (piecePosition.getY() + shape[i].getY()) * 32
            );
    }
}

void Piece::setPiecePosition(int x, int y) {
    Piece::setPiecePosition(x, y, true);
}

void Piece::setPiecePosition(Point x) {
    Piece::setPiecePosition(x.getX(), x.getY(), true);
    setCurrentShape();
}

void Piece::rotateLeft() {
    //calculate next left rotation
    int nextRotation = this->rotation - 1;
    if (nextRotation < 0) {
        nextRotation = 3;
    }
    setRotation(nextRotation);
    setCurrentShape();
    setPiecePosition(this->getPiecePosition());
}

void Piece::rotateRight() {
    //calculate next right rotation
    int nextRotation = (this->rotation + 1) % 4;
    setRotation(nextRotation);
    setCurrentShape();
    setPiecePosition(this->getPiecePosition());
}

int Piece::getRotation() const {
    return rotation;
}

void Piece::setRotation(int rotation) {
    if (rotation >= 0 && rotation < 4)
        Piece::rotation = rotation;
    else
        Piece::rotation = 0;
}

Point *Piece::getCurrentShape() {
    return this->shape;
}

Point *Piece::getLeftRotationShape() {
    int nextRotation = (this->rotation + 1) % 4;
    return this->shapes[nextRotation];
}

Point *Piece::getRightRotationShape() {
    int nextRotation = this->rotation - 1;
    if (nextRotation < 0) {
        nextRotation = 3;
    }
    return this->shapes[nextRotation];
}

int Piece::getCurrentShapeInt() const {
    return currentShapeInt;
}

Point* const Piece::getShapes() const {
    return (Point*) shapes;
}


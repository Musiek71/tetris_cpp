//
// Created by musiek on 16.11.2020.
//

#include "../header/Piece.h"
#include "../header/Board.h"

Piece::Piece(std::string tileset, int rotation, int currentShapeInt, Point* shapes) : rotation(rotation), currentShapeInt(currentShapeInt) {
    setShapes(shapes);
    this->piecePosition.setPos(DEFAULT_X, DEFAULT_Y);

    int loaded = tileSet.loadFromFile(tileset, sf::IntRect(32 * currentShapeInt, 0, 32, 32));
    //init of four sprites representing piece
    for (int i = 0; i < 4; i++) {
        tileSprite[i].setTexture(tileSet);
        tileSprite[i].setPosition((piecePosition.getX() + shape[i].getX()) * 32 + X_OFFSET,
                                  (piecePosition.getY() + shape[i].getY()) * 32 + Y_OFFSET - DEFAULT_Y_OFFSET
        );
    }

}

void Piece::setShapes(Point* shapes) {
    //copying shapes
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            this->shapes[i][j] = shapes[i * 4 + j];
        }
    }
    setCurrentShape();
}

void Piece::setCurrentShape() {
    //setting four sprites to the desired shape
    for (int i = 0; i < 4; i++) {
        this->shape[i] = shapes[rotation][i];
    }
}

void Piece::draw(sf::RenderTarget &target, sf::RenderStates states) const {

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
    Piece::piecePosition.setX(x);
    Piece::piecePosition.setY(y);
    for (int i = 0; i < 4; i++) {
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

void Piece::setPiecePosition() {
    Piece::setPiecePosition(this->piecePosition.getX(), this->piecePosition.getY());
}

void Piece::rotateLeft() {
    int nextRotation = this->rotation - 1;
    if (nextRotation < 0) {
        nextRotation = 3;
    }
    setRotation(nextRotation);
    setCurrentShape();
    setPiecePosition(this->getPiecePosition());
}

void Piece::rotateRight() {
    int nextRotation = (this->rotation + 1) % 4;
    setRotation(nextRotation);
    setCurrentShape();
    setPiecePosition(this->getPiecePosition());
}

int Piece::getRotation() const {
    return rotation;
}

void Piece::setRotation(int rotation) {
    Piece::rotation = rotation;
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


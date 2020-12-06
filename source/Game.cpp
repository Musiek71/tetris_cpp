//
// Created by musiek on 11/21/20.
//

#include "../header/Game.h"

bool Game::run() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Tetris");
    window.setVerticalSyncEnabled(true);

    if (!gameBoard.init("tileset.png", 32))
        return false;

    sf::Texture backgroundText;
    backgroundText.loadFromFile("background.png");
    sf::Sprite background;
    background.setTexture(backgroundText);
    background.setScale((float)window.getSize().x / backgroundText.getSize().x, (float)window.getSize().y / backgroundText.getSize().y );


    Piece* currentPiece = pieceFactory.getPiece();
    Piece* nextPiece = pieceFactory.getPiece();
    //nextPiece->setPiecePosition(X_OFFSET / 32 + BOARD_WIDTH + 3, 10, false);
    Piece* ghostPiece = pieceFactory.getGhostPiece(currentPiece);
    setGhostPosition(currentPiece, ghostPiece);

    ScoreBoard scoreBoard("score_field.png",
                          "gbfont.ttf",
                          1,
                          0,
                          X_OFFSET + (BOARD_WIDTH + 2) * 32,
                          16 * 32,
                          32);
    scoreBoard.setLevel(this->level);
    scoreBoard.setScore(this->score);

    NextBoard nextBoard("next_field.png",
                        nextPiece,
                        X_OFFSET + (BOARD_WIDTH + 2) * 32,
                        8 * 32,
                        32);


    bool deltaFlag = false;
    float deltaTime = 0;

    bool fastFallFlag = false;

    sf::Clock frameClock;
    sf::Clock keyClock;
    sf::Time frameTime = frameClock.getElapsedTime();
    sf::Time keyTime = keyClock.getElapsedTime();


    while (window.isOpen()) {

        if (gameOver) {
            break;
        }

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Z)
                    rotateLeft(currentPiece, ghostPiece);
                else if (event.key.code == sf::Keyboard::X)
                    rotateRight(currentPiece, ghostPiece);
            }
        }

        keyTime = keyClock.getElapsedTime();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && keyTime.asSeconds() > 0.04) {
            fastFallFlag = true;
            keyClock.restart();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && keyTime.asSeconds() > 0.08) {
            moveLeft(currentPiece, ghostPiece);
            keyClock.restart();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && keyTime.asSeconds() > 0.08) {
            moveRight(currentPiece, ghostPiece);
            keyClock.restart();
        }

        window.clear();
        window.draw(background);
        window.draw(nextBoard);
        window.draw(scoreBoard);
        window.draw(gameBoard);
        window.draw(*currentPiece);
        window.draw(*ghostPiece);
        window.display();


        frameTime = frameClock.getElapsedTime();
        if (fastFallFlag | (frameTime.asSeconds() - deltaTime > 0.5 - (level - 1) * 0.05)) {
            frameClock.restart();

            //if fast falling, increment the score
            if (fastFallFlag)
                this->score += 1;

            if (!fallDown(currentPiece)) {
                gameOver = gameBoard.add(currentPiece);

                delete currentPiece;
                delete ghostPiece;

                //swap pieces
                currentPiece = nextPiece;
                currentPiece->setPiecePosition(DEFAULT_X, DEFAULT_Y);
                //get new piece as the next piece
                nextPiece = pieceFactory.getPiece();
                nextBoard.setPiece(nextPiece);
                //get new ghost piece and update it's position
                ghostPiece = pieceFactory.getGhostPiece(currentPiece);

                //getting number of cleared rows
                int clearedRows = gameBoard.updateBoard();

                //setting ghost position after board updating
                setGhostPosition(currentPiece, ghostPiece);

                //update score fields
                this->totalRows += clearedRows;
                updateScore(clearedRows);
                updateLevel();

            }
            fastFallFlag = false;

            //update scoreboard
            scoreBoard.setScore(this->score);
            scoreBoard.setLevel(this->level);
        }
    }

    return true;
}

Game::Game() {}

bool Game::moveLeft(Piece *piece, Piece* ghostPiece) {
    if (!gameBoard.collidesWith(
            piece->getPiecePosition().getX() - 1,
            piece->getPiecePosition().getY(),
            piece->getCurrentShape())
            ) {
        piece->setPiecePosition(piece->getPiecePosition().getX() - 1, piece->getPiecePosition().getY());
        setGhostPosition(piece, ghostPiece);
        return true;
    }
    return false;
}

bool Game::moveRight(Piece *piece, Piece* ghostPiece) {
    if (!gameBoard.collidesWith(
            piece->getPiecePosition().getX() + 1,
            piece->getPiecePosition().getY(),
            piece->getCurrentShape())
            ) {
        piece->setPiecePosition(piece->getPiecePosition().getX() + 1, piece->getPiecePosition().getY());
        setGhostPosition(piece, ghostPiece);
        return true;
    }
    return false;
}

bool Game::rotateLeft(Piece *piece, Piece* ghostPiece) {
    if (!gameBoard.collidesWith(
            piece->getPiecePosition().getX(),
            piece->getPiecePosition().getY(),
            piece->getLeftRotationShape())
            ) {
        piece->rotateLeft();
        setGhostPosition(piece, ghostPiece);
        return true;
    }
    return false;
}

bool Game::rotateRight(Piece *piece, Piece* ghostPiece) {
    if (!gameBoard.collidesWith(
            piece->getPiecePosition().getX(),
            piece->getPiecePosition().getY(),
            piece->getRightRotationShape())
            ) {
        piece->rotateRight();
        setGhostPosition(piece, ghostPiece);
        return true;
    }
    return false;
}

bool Game::fallDown(Piece *piece) {
    if (!gameBoard.collidesWith(
            piece->getPiecePosition().getX(),
            piece->getPiecePosition().getY() + 1,
            piece->getCurrentShape())
            ) {
        piece->setPiecePosition(piece->getPiecePosition().getX(), piece->getPiecePosition().getY() + 1);
        return true;
    }
    return false;
}

void Game::setGhostPosition(Piece *currentPiece, Piece* ghostPiece) {
    //set current ghost rotation the same as the current piece rotation
    ghostPiece->setRotation(currentPiece->getRotation());
    //set current ghost position the same as the current piece position
    ghostPiece->setPiecePosition(currentPiece->getPiecePosition());

    //find lowest free ghost piece position
    while (!gameBoard.collidesWith(ghostPiece->getPiecePosition().getX(),
                                   ghostPiece->getPiecePosition().getY() + 1,
                                   ghostPiece->getCurrentShape())) {
        ghostPiece->setPiecePosition(ghostPiece->getPiecePosition().getX(),
                                     ghostPiece->getPiecePosition().getY() + 1);
    }
}

void Game::updateScore(int clearedRows) {
    switch (clearedRows) {
        case 1:
            this->score += 40 * this->level;
            break;
        case 2:
            this->score += 100 * this->level;
            break;
        case 3:
            this->score += 300 * this->level;
            break;
        case 4:
            this->score += 1200 * this->level;
            break;
    }
}

void Game::updateLevel() {
    this->level = this->totalRows / 10 + 1;
}





//
// Created by musiek on 11/21/20.
//

#include "../../header/Game/Game.h"

bool Game::run() {

    if (!gameBoard->init("tileset.png", 32)) {
        std::cout << "Tileset loading failed." << std::endl;
        return false;
    }

    window->setSize(sf::Vector2u((boardWidth + 13) * 32, boardHeight * 32));

    sf::View gameView(sf::FloatRect(0, 0, (boardWidth + 13) * 32, boardHeight * 32));
    window->setView(gameView);

    sf::Texture backgroundText;
    backgroundText.loadFromFile("background.png");
    sf::Sprite background;
    background.setTexture(backgroundText);
    background.setScale((float)window->getSize().x / backgroundText.getSize().x, (float)window->getSize().y / backgroundText.getSize().y );


    Piece* currentPiece = pieceFactory->getPiece();
    Piece* nextPiece = pieceFactory->getPiece();
    //nextPiece->setPiecePosition(X_OFFSET / 32 + BOARD_WIDTH + 3, 10, false);
    Piece* ghostPiece = pieceFactory->getGhostPiece(currentPiece);
    setGhostPosition(currentPiece, ghostPiece);

    ScoreBoard scoreBoard("score_field.png",
                          "gbfont.ttf",
                          1,
                          0,
                          X_OFFSET + (this->boardWidth + 2) * 32,
                          9 * 32,
                          32);
    scoreBoard.setLevel(this->level);
    scoreBoard.setScore(this->score);

    NextBoard nextBoard("next_field.png",
                        nextPiece,
                        X_OFFSET + (this->boardWidth + 2) * 32,
                        1* 32,
                        32);


    float deltaTime = 0;

    bool fastFallFlag = false;

    sf::Clock frameClock;
    sf::Clock keyClock;
    sf::Time frameTime = frameClock.getElapsedTime();
    sf::Time keyTime = keyClock.getElapsedTime();

    sf::SoundBuffer fallSoundBuffer;
    sf::Sound fallSound;
    if (!fallSoundBuffer.loadFromFile("fall.wav"))
        return -1;
    fallSound.setBuffer(fallSoundBuffer);
    fallSound.setVolume(this->volume);

    sf::SoundBuffer clearedSoundBuffer;
    sf::Sound clearedSound;
    if (!clearedSoundBuffer.loadFromFile("powerup.wav"))
        return -1;
    clearedSound.setBuffer(clearedSoundBuffer);
    clearedSound.setVolume(this->volume);

    sf::Music music;
    if (!music.openFromFile("tetris.ogg"))
        return -1;
    music.setVolume(this->volume);
    music.setLoop(true);
    music.play();



    while (window->isOpen()) {

        if (gameOver) {
            std::cout << "Game over!\n";
            std::cout << "Score:" << this->score << "\nLevel:" << this->level << std::endl;

            *gameStatePtr = GAMEOVER;

            delete currentPiece;
            delete nextPiece;
            delete ghostPiece;

            break;
        }

        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
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

        window->clear();
        window->draw(background);
        window->draw(nextBoard);
        window->draw(scoreBoard);
        window->draw(*gameBoard);
        window->draw(*currentPiece);
        window->draw(*ghostPiece);
        window->display();


        frameTime = frameClock.getElapsedTime();
        if (fastFallFlag | (frameTime.asSeconds() - deltaTime > 0.5 - (level - 1) * 0.05)) {
            frameClock.restart();

            //if fast falling, increment the score
            if (fastFallFlag)
                this->score += 1;

            if (!fallDown(currentPiece)) {
                fallSound.play();
                gameOver = gameBoard->add(currentPiece);

                delete currentPiece;
                delete ghostPiece;

                //swap pieces
                currentPiece = nextPiece;
                currentPiece->setPiecePosition(this->boardWidth / 2 - 1, DEFAULT_Y);
                //get new piece as the next piece
                nextPiece = pieceFactory->getPiece();
                nextBoard.setPiece(nextPiece);
                //get new ghost piece and update it's position
                ghostPiece = pieceFactory->getGhostPiece(currentPiece);

                //getting number of cleared rows
                int clearedRows = gameBoard->updateBoard();

                if (clearedRows)
                    clearedSound.play();

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

Game::Game(int boardWidth, int boardHeight, sf::RenderWindow* window, float volume, int* gameStatePtr) {
    if (boardWidth >= 5)
        this->boardWidth = boardWidth + 2; //side walls
    else
        this->boardWidth = 5 + 2;
    if (boardHeight >= 10)
        this->boardHeight = boardHeight + 4; //bottom wall + three rows for piece spawning
    else
        this->boardHeight = 10 + 4;

    this->gameBoard = new Board(this->boardWidth, this->boardHeight);
    this->pieceFactory = new PieceFactory(this->boardWidth / 2 - 2);

    this->window = window;

    this->volume = volume;

    this->gameStatePtr = gameStatePtr;
}

bool Game::moveLeft(Piece *piece, Piece* ghostPiece) {
    if (!gameBoard->collidesWith(
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
    if (!gameBoard->collidesWith(
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
    if (!gameBoard->collidesWith(
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
    if (!gameBoard->collidesWith(
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
    if (!gameBoard->collidesWith(
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
    while (!gameBoard->collidesWith(ghostPiece->getPiecePosition().getX(),
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

Game::~Game() {
    delete this->gameBoard;
    delete this->pieceFactory;
}





//
// Created by musiek on 11/21/20.
//

#include "../../header/Game/Game.h"

Game::Game(sf::RenderWindow* window, int boardWidth, int boardHeight, float volume, int* gameStatePtr, int* scorePtr,
           int* levelPtr, bool ghostFlag, ResourceManager* resourceManager) {
    //checking the correctness of the width and height of the board
    if (boardWidth >= 5)
        this->boardWidth = boardWidth + 2; //side walls
    else
        this->boardWidth = 5 + 2;
    if (boardHeight >= 10)
        this->boardHeight = boardHeight + 4; //bottom wall + three rows for piece spawning
    else
        this->boardHeight = 10 + 4;

    //setting the resourceManager pointer field
    this->resourceManager = resourceManager;

    //getting the board and the piece factory
    this->gameBoard = new Board(this->boardWidth, this->boardHeight, resourceManager);
    this->pieceFactory = new PieceFactory(this->boardWidth / 2 - 2, this->resourceManager);

    //setting all the pointers
    this->window = window;
    this->volume = volume;
    this->gameStatePtr = gameStatePtr;
    this->scorePtr = scorePtr;
    this->levelPtr = levelPtr;
    this->ghostFlag = ghostFlag;

    //getting the font from the resource manager
    textFontPtr = resourceManager->getFont("gbfont.ttf");

    //setting the Paused text in the window's center
    this->pausedText.setFont(*textFontPtr);
    this->pausedText.setCharacterSize(48);
    this->pausedText.setString("Paused");
    this->pausedText.setPosition(window->getSize().x / 2 - pausedText.getGlobalBounds().width / 2,
                                 window->getSize().y / 2 - pausedText.getCharacterSize() / 2);
}

void Game::run() {

    //initializing the board
    gameBoard->init("tileset.png", 32);

    //setting the window's size
    window->setSize(sf::Vector2u((boardWidth + 13) * 32, boardHeight * 32));

    //fixing the window's gameview
    sf::View gameView(sf::FloatRect(0, 0, (boardWidth + 13) * 32, boardHeight * 32));
    window->setView(gameView);

    //setting the background
    sf::Sprite background;
    sf::Texture* backgroundText = resourceManager->getTexture("background.png");
    background.setTexture(*backgroundText);
    background.setScale((float)window->getSize().x / backgroundText->getSize().x, (float)window->getSize().y / backgroundText->getSize().y );

    //getting all the pieces using the pieceFactory
    Piece* currentPiece = pieceFactory->getPiece();
    Piece* nextPiece = pieceFactory->getPiece();
    Piece* ghostPiece = pieceFactory->getGhostPiece(currentPiece);
    setGhostPosition(currentPiece, ghostPiece);

    //setting the scoreboard
    ScoreBoard scoreBoard("score_field.png",
                          "gbfont.ttf",
                          resourceManager,
                          1,
                          0,
                          X_OFFSET + (this->boardWidth + 2) * 32,
                          9 * 32,
                          32);
    scoreBoard.setLevel(this->level);
    scoreBoard.setScore(this->score);

    //setting the nextBoard
    NextBoard nextBoard("next_field.png",
                        resourceManager,
                        nextPiece,
                        X_OFFSET + (this->boardWidth + 2) * 32,
                        1* 32,
                        32);

    //setting the fall sound
    sf::SoundBuffer* fallSoundBuffer = resourceManager->getSoundBuffer("fall.wav");
    sf::Sound fallSound;
    fallSound.setBuffer(*fallSoundBuffer);
    fallSound.setVolume(this->volume);

    //setting the clear sound
    sf::SoundBuffer* clearedSoundBuffer = resourceManager->getSoundBuffer("clear.wav");
    sf::Sound clearedSound;
    clearedSound.setBuffer(*clearedSoundBuffer);
    clearedSound.setVolume(this->volume);

    //setting the main music
    sf::Music* music = resourceManager->getMusic("tetris.ogg");
    music->setVolume(this->volume);
    music->setLoop(true);
    music->play();

    //setting game flags
    bool fastFallFlag = false;
    bool pausedFlag = false;

    //setting clocks used for game's time counting
    sf::Clock frameClock;
    sf::Clock keyClock;
    sf::Time frameTime = frameClock.getElapsedTime();
    sf::Time keyTime = keyClock.getElapsedTime();

    //main game loop
    while (window->isOpen()) {

        //entering main menu
        if (*gameStatePtr == MENU) {
            music->stop();
            break;
        }

        //game over
        if (gameOver) {
            *gameStatePtr = GAMEOVER;
            *levelPtr = level;
            *scorePtr = score;

            music->stop();

            delete currentPiece;
            delete nextPiece;
            delete ghostPiece;

            break;
        }

        //event handling
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Z) {
                    if (!pausedFlag)
                        rotateLeft(currentPiece, ghostPiece);
                }
                else if (event.key.code == sf::Keyboard::X) {
                    if (!pausedFlag)
                        rotateRight(currentPiece, ghostPiece);
                }
                else if (event.key.code == sf::Keyboard::Escape)
                    *gameStatePtr = MENU;
                else if (event.key.code == sf::Keyboard::P)
                    pausedFlag = !pausedFlag;
            }
        }

        //event handling for continuuous key entering
        //allows to achieve more smooth game input
        keyTime = keyClock.getElapsedTime();
        if (!pausedFlag) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && keyTime.asSeconds() > 0.04) {
                fastFallFlag = true;
                keyClock.restart();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && keyTime.asSeconds() > 0.09) { //0.08
                moveLeft(currentPiece, ghostPiece);
                keyClock.restart();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && keyTime.asSeconds() > 0.09) {
                moveRight(currentPiece, ghostPiece);
                keyClock.restart();
            }
        }

        //main SFML window drawing sequence
        window->clear();
        window->draw(background);
        window->draw(nextBoard);
        window->draw(scoreBoard);
        window->draw(*gameBoard);
        window->draw(*currentPiece);
        if (ghostFlag)
            window->draw(*ghostPiece);
        if (pausedFlag)
            window->draw(pausedText);
        window->display();

        //main game condition system, falling of the pieces
        frameTime = frameClock.getElapsedTime();
        if (!pausedFlag && (fastFallFlag | (frameTime.asSeconds() > 0.5 - (level - 1) * 0.025))) {
            frameClock.restart();

            //if fast falling, increment the score
            if (fastFallFlag)
                this->score += 1;

            if (!fallDown(currentPiece)) {
                fallSound.play();
                gameOver = !gameBoard->add(currentPiece);

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
}

bool Game::moveLeft(Piece *piece, Piece* ghostPiece) {
    //if piece's not colliding with anything in the position moved by one to left on the board
    if (!gameBoard->collidesWith(
            piece->getPiecePosition().getX() - 1,
            piece->getPiecePosition().getY(),
            piece->getCurrentShape())
            ) {
        //set the new position on the board
        piece->setPiecePosition(piece->getPiecePosition().getX() - 1, piece->getPiecePosition().getY());
        //correct the position of the piece's ghost
        setGhostPosition(piece, ghostPiece);
        return true;
    }
    return false;
}

bool Game::moveRight(Piece *piece, Piece* ghostPiece) {
    //if piece's not colliding with anything in the position moved by one to right on the board
    if (!gameBoard->collidesWith(
            piece->getPiecePosition().getX() + 1,
            piece->getPiecePosition().getY(),
            piece->getCurrentShape())
            ) {
        //set the new position on the board
        piece->setPiecePosition(piece->getPiecePosition().getX() + 1, piece->getPiecePosition().getY());
        //correct the position of the piece's ghost
        setGhostPosition(piece, ghostPiece);
        return true;
    }
    return false;
}

bool Game::rotateLeft(Piece *piece, Piece* ghostPiece) {
    //if piece's not colliding with anything in the position rotated left on the board
    if (!gameBoard->collidesWith(
            piece->getPiecePosition().getX(),
            piece->getPiecePosition().getY(),
            piece->getLeftRotationShape())
            ) {
        //rotate the piece to the left
        piece->rotateLeft();
        //correct the position of the piece's ghost
        setGhostPosition(piece, ghostPiece);
        return true;
    }
    return false;
}

bool Game::rotateRight(Piece *piece, Piece* ghostPiece) {
    //if piece's not colliding with anything in the position rotated right on the board
    if (!gameBoard->collidesWith(
            piece->getPiecePosition().getX(),
            piece->getPiecePosition().getY(),
            piece->getRightRotationShape())
            ) {
        //rotate the piece to the right
        piece->rotateRight();
        //correct the position of the piece's ghost
        setGhostPosition(piece, ghostPiece);
        return true;
    }
    return false;
}

bool Game::fallDown(Piece *piece) {
    //if piece's fallen position doesn't collide with anything on the board
    if (!gameBoard->collidesWith(
            piece->getPiecePosition().getX(),
            piece->getPiecePosition().getY() + 1,
            piece->getCurrentShape())
            ) {
        //lower the piece's position by one
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
    //increase the score depending on the number of cleared rows
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
    this->level = this->totalRows / 5 + 1;
}

Game::~Game() {
    delete this->gameBoard;
    delete this->pieceFactory;
}





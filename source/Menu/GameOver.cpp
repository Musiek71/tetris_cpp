//
// Created by musiek on 12/15/20.
//

#include "../../header/Menu/GameOver.h"

GameOver::GameOver(sf::RenderWindow *window, std::string filename, int *gameStatePtr, int *scorePtr, int* levelPtr, ResourceManager* resourceManager) {
    this->window = window;
    this->gameStatePtr = gameStatePtr;
    this->scorePtr = scorePtr;
    this->lvlPtr = levelPtr;
    this->filename = filename;
    this->resourceManager = resourceManager;

    //initializing window
    window->setSize(sf::Vector2u(800, 800));

    sf::View gameView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(gameView);

    //open the main font
    textFontPtr = resourceManager->getFont("gbfont.ttf");

    //init for top text
    topText.setFont(*textFontPtr);
    topText.setCharacterSize(32);
    topText.setString("Game over! Enter your name:");
    topText.setPosition(window->getSize().x / 2 - topText.getGlobalBounds().width / 2, 0);

    scoreText.setFont(*textFontPtr);
    scoreText.setCharacterSize(32);
    scoreText.setString("Score:" + std::to_string(*scorePtr));
    scoreText.setPosition(window->getSize().x / 2 - scoreText.getGlobalBounds().width / 2, window->getSize().y / 8);

    levelText.setFont(*textFontPtr);
    levelText.setCharacterSize(32);
    levelText.setString("Level:" + std::to_string(*levelPtr));
    levelText.setPosition(window->getSize().x / 2 - levelText.getGlobalBounds().width / 2, window->getSize().y * 2 / 8);

    nickText.setFont(*textFontPtr);
    nickText.setCharacterSize(48);
    nickText.setString("Nick:" + nick);
    nickText.setPosition(window->getSize().x / 2 - nickText.getGlobalBounds().width / 2, window->getSize().y / 8 * 3);

    menuButton = new Button(sf::Vector2f(window->getSize().x / 2 - 100, window->getSize().y - 100),
                            sf::Vector2f(200, 100),
                            "Menu",
                            resourceManager);

    gameButton = new Button(sf::Vector2f(0, window->getSize().y - 100),
                            sf::Vector2f(200, 100),
                            "Restart!",
                            resourceManager);

    leaderboardButton = new Button(sf::Vector2f(window->getSize().x - 200, window->getSize().y - 100),
                            sf::Vector2f(200, 100),
                            "Scores",
                            resourceManager);

}

GameOver::~GameOver() {
    delete menuButton;
    delete gameButton;
    delete leaderboardButton;
}

void GameOver::run() {

    sf::Sprite background;
    sf::Texture* backgroundText = resourceManager->getTexture("background.png");
    background.setTexture(*backgroundText);
    background.setScale((float)window->getSize().x / backgroundText->getSize().x, (float)window->getSize().y / backgroundText->getSize().y );

    while (window->isOpen()) {

        if (*gameStatePtr != GAMEOVER) {
            addScore();
            break;
        }

        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b') {
                    if (nick.length() > 0)
                        nick.erase(nick.length() - 1, 1);
                }
                else if (event.text.unicode != ' ' && event.text.unicode >= 'A' && event.text.unicode <= 'z') {
                    if (nick.length() < 9)
                        nick += event.text.unicode;
                }
                nickText.setString("Nick:" + nick);
                nickText.setPosition(window->getSize().x / 2 - nickText.getGlobalBounds().width / 2, window->getSize().y / 8 * 3);
            }
        }

        sf::Vector2f mouseViewPos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));

        if (menuButton->updateButton(mouseViewPos)) {
            *gameStatePtr = MENU;
        }

        if (gameButton->updateButton(mouseViewPos)) {
            *gameStatePtr = GAME;
        }

        if (leaderboardButton->updateButton(mouseViewPos)) {
            *gameStatePtr = LEADERBOARD;
        }

        window->clear();
        window->draw(background);

        window->draw(topText);
        window->draw(scoreText);
        window->draw(levelText);
        window->draw(nickText);

        window->draw(*menuButton);
        window->draw(*gameButton);
        window->draw(*leaderboardButton);

        window->display();
    }
}

void GameOver::addScore() {;
    //open scores file
    std::ofstream outputStream;
    outputStream.open(filename, std::fstream::out | std::fstream::app);

    if (nick == "")
        nick = "----";

    outputStream << nick << " " << std::to_string(*scorePtr) << "\n";

    outputStream.close();
}


//
// Created by musiek on 12/15/20.
//

#include "../../header/Menu/GameOver.h"

GameOver::GameOver(sf::RenderWindow *window, std::string filename, int *gameStatePtr, int *scorePtr) {
    this->window = window;
    this->gameStatePtr = gameStatePtr;
    this->scorePtr = scorePtr;
    this->filename = filename;

    //initializing window
    window->setSize(sf::Vector2u(800, 800));

    sf::View gameView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(gameView);

    //open the main font
    if (!textFont.loadFromFile("gbfont.ttf")) {
        std::cout << "Failed to load font:" << "gbfont.ttf" << std::endl;
    }

    //init for top text
    topText.setFont(textFont);
    topText.setCharacterSize(32);
    topText.setString("Game over! Enter your name:");
    topText.setPosition(window->getSize().x / 2 - topText.getGlobalBounds().width / 2, 0);

    scoreText.setFont(textFont);
    scoreText.setCharacterSize(32);
    scoreText.setString("Score:" + std::to_string(*scorePtr));
    scoreText.setPosition(window->getSize().x / 2 - scoreText.getGlobalBounds().width / 2, window->getSize().y / 8);

    nickText.setFont(textFont);
    nickText.setCharacterSize(48);
    nickText.setString("Nick:" + nick);
    nickText.setPosition(window->getSize().x / 2 - nickText.getGlobalBounds().width / 2, window->getSize().y / 4);

    menuButton = new Button(sf::Vector2f(window->getSize().x / 2 - 100, window->getSize().y - 100),
                            sf::Vector2f(200, 100),
                            sf::Color::Blue,
                            "Menu",
                            &textFont);

    gameButton = new Button(sf::Vector2f(0, window->getSize().y - 100),
                            sf::Vector2f(200, 100),
                            sf::Color::Blue,
                            "Restart!",
                            &textFont);

    leaderboardButton = new Button(sf::Vector2f(window->getSize().x - 200, window->getSize().y - 100),
                            sf::Vector2f(200, 100),
                            sf::Color::Blue,
                            "Scores",
                            &textFont);

}

GameOver::~GameOver() {
    delete menuButton;
    delete gameButton;
    delete leaderboardButton;
}

void GameOver::run() {

    sf::Texture backgroundText;
    backgroundText.loadFromFile("background.png");
    sf::Sprite background;
    background.setTexture(backgroundText);
    background.setScale((float)window->getSize().x / backgroundText.getSize().x, (float)window->getSize().y / backgroundText.getSize().y );

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
                else {
                    if (nick.length() < 9)
                        nick += event.text.unicode;
                }
                nickText.setString("Nick:" + nick);
                nickText.setPosition(window->getSize().x / 2 - nickText.getGlobalBounds().width / 2, window->getSize().y / 4);
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


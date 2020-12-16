//
// Created by musiek on 12/12/20.
//

#include <iostream>
#include "../../header/Menu/Menu.h"

Menu::Menu(sf::RenderWindow *window, int *widthPtr, int *heightPtr, int *volumePtr, int* gameStatePtr, bool* ghostFlagPtr) {
    this-> window = window;
    this->widthPtr = widthPtr;
    this->heightPtr = heightPtr;
    this->volumePtr = volumePtr;
    this->gameStatePtr = gameStatePtr;
    this->ghostFlagPtr = ghostFlagPtr;

    window->setSize(sf::Vector2u(800, 800));

    sf::View gameView(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
    window->setView(gameView);

    if (!textFont.loadFromFile("gbfont.ttf")) {
        std::cout << "Failed to load font:" << "gbfont.ttf" << std::endl;
    }
    widthText.setFont(textFont);
    heightText.setFont(textFont);
    volumeText.setFont(textFont);
    ghostText.setFont(textFont);

    widthText.setString("Width:" + std::to_string(*widthPtr));
    widthText.setCharacterSize(24);
    widthText.setPosition(window->getSize().x / 4.f * 3 - widthText.getGlobalBounds().width / 2,
                          window->getSize().y / 10.f * 2);

    heightText.setString("Height:" + std::to_string(*heightPtr));
    heightText.setCharacterSize(24);
    heightText.setPosition(window->getSize().x / 4.f * 3 - widthText.getGlobalBounds().width / 2,
                           window->getSize().y / 10.f * 4);

    volumeText.setString("Volume:" + std::to_string(*volumePtr));
    volumeText.setCharacterSize(24);
    volumeText.setPosition(window->getSize().x / 4.f * 3 - widthText.getGlobalBounds().width / 2,
                           window->getSize().y / 10.f * 6);

    ghostText.setString("Ghost:");
    ghostText.setCharacterSize(24);
    ghostText.setPosition(window->getSize().x / 4.f * 3 - widthText.getGlobalBounds().width / 2,
                          window->getSize().y / 10.f * 8);

    startButton = new Button(sf::Vector2f(window->getSize().x / 4.f - widthText.getGlobalBounds().width / 2,
                                            window->getSize().y / 4.f * 1),
                             sf::Vector2f(200, 100),
                             sf::Color::Blue,
                             "Start",
                             &textFont);

    leaderboardButton = new Button(sf::Vector2f(window->getSize().x / 4.f - widthText.getGlobalBounds().width / 2,
                                                window->getSize().y / 4.f * 2),
                                   sf::Vector2f(200, 100),
                                   sf::Color::Blue,
                                   "Scores",
                                   &textFont);


    exitButton = new Button(sf::Vector2f(window->getSize().x / 4.f - widthText.getGlobalBounds().width / 2,
                                            window->getSize().y / 4.f * 3),
                            sf::Vector2f(200, 100),
                            sf::Color::Blue,
                            "Exit",
                            &textFont);

    increaseWidthButton = new Button(sf::Vector2f(window->getSize().x / 4.f * 3 - widthText.getGlobalBounds().width / 2,
                                                        window->getSize().y / 10.f * 3  - 50),
                                     sf::Vector2f(50, 50),
                                     sf::Color::Blue,
                                     "Inc",
                                     &textFont);

    decreaseWidthButton = new Button(sf::Vector2f(window->getSize().x / 4.f * 3 - widthText.getGlobalBounds().width / 2 + 100,
                                                        window->getSize().y / 10.f * 3 - 50),
                                     sf::Vector2f(50, 50),
                                     sf::Color::Blue,
                                     "Dec",
                                     &textFont);

    increaseHeightButton = new Button(sf::Vector2f(window->getSize().x / 4.f * 3 - widthText.getGlobalBounds().width / 2,
                                                        window->getSize().y / 10.f * 5  - 50),
                                      sf::Vector2f(50, 50),
                                      sf::Color::Blue,
                                      "Inc",
                                      &textFont);

    decreaseHeightButton = new Button(sf::Vector2f(window->getSize().x / 4.f * 3 - widthText.getGlobalBounds().width / 2 + 100,
                                                        window->getSize().y / 10.f * 5 - 50),
                                      sf::Vector2f(50, 50),
                                      sf::Color::Blue,
                                      "Dec",
                                      &textFont);

    increaseVolumeButton = new Button(sf::Vector2f(window->getSize().x / 4.f * 3 - widthText.getGlobalBounds().width / 2,
                                                        window->getSize().y / 10.f * 7  - 50),
                                      sf::Vector2f(50, 50),
                                      sf::Color::Blue,
                                      "Inc",
                                      &textFont);

    decreaseVolumeButton = new Button(sf::Vector2f(window->getSize().x / 4.f * 3 - widthText.getGlobalBounds().width / 2 + 100,
                                                        window->getSize().y / 10.f * 7 - 50),
                                      sf::Vector2f(50, 50),
                                      sf::Color::Blue,
                                      "Dec",
                                      &textFont);

    ghostButton = new Button(sf::Vector2f(window->getSize().x / 4.f * 3 - widthText.getGlobalBounds().width / 2,
                                          window->getSize().y / 10.f * 9 - 50),
                             sf::Vector2f(50, 50),
                             sf::Color::Blue,
                             *this->ghostFlagPtr ? "On" : "Off",
                             &textFont);


}


Menu::~Menu() {
    delete startButton;
    delete exitButton;
    delete leaderboardButton;
    delete increaseWidthButton;
    delete decreaseWidthButton;
    delete increaseHeightButton;
    delete decreaseHeightButton;
    delete increaseVolumeButton;
    delete decreaseVolumeButton;
    delete ghostButton;
}

void Menu::run() {

    sf::Texture backgroundText;
    backgroundText.loadFromFile("background.png");
    sf::Sprite background;
    background.setTexture(backgroundText);
    background.setScale((float)window->getSize().x / backgroundText.getSize().x, (float)window->getSize().y / backgroundText.getSize().y );


    while (window->isOpen()) {

        if (*gameStatePtr != MENU)
            break;

        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        sf::Vector2f mouseViewPos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));

        if (startButton->updateButton(mouseViewPos)) {
            *gameStatePtr = GAME;
        }

        if (exitButton->updateButton(mouseViewPos)) {
            *gameStatePtr = EXIT;
        }

        if (leaderboardButton->updateButton(mouseViewPos)) {
            *gameStatePtr = LEADERBOARD;
        }

        if (increaseWidthButton->updateButton(mouseViewPos)) {
            if (*widthPtr < 50) {
                *widthPtr += 5;
                updateWidthText();
            }
        }

        if (decreaseWidthButton->updateButton(mouseViewPos)) {
            if (*widthPtr > 5) {
                *widthPtr -= 5;
                updateWidthText();
            }
        }

        if (increaseHeightButton->updateButton(mouseViewPos)) {
            if (*heightPtr < 50) {
                *heightPtr += 5;
                updateHeightText();
            }
        }

        if (decreaseHeightButton->updateButton(mouseViewPos)) {
            if (*heightPtr > 10) {
                *heightPtr -= 5;
                updateHeightText();
            }
        }

        if (increaseVolumeButton->updateButton(mouseViewPos)) {
            if (*volumePtr < 100) {
                *volumePtr += 5;
                updateVolumeText();
            }
        }

        if (decreaseVolumeButton->updateButton(mouseViewPos)) {
            if (*volumePtr > 0) {
                *volumePtr -= 5;
                updateVolumeText();
            }
        }

        if (ghostButton->updateButton(mouseViewPos)) {
            *ghostFlagPtr = !*ghostFlagPtr;
            ghostButton->setText(*ghostFlagPtr ? "On" : "Off");
        }

        window->clear();
        window->draw(background);
        window->draw(*startButton);
        window->draw(*exitButton);
        window->draw(*leaderboardButton);

        window->draw(*increaseWidthButton);
        window->draw(*decreaseWidthButton);
        window->draw(widthText);

        window->draw(*increaseHeightButton);
        window->draw(*decreaseHeightButton);
        window->draw(heightText);

        window->draw(*increaseVolumeButton);
        window->draw(*decreaseVolumeButton);
        window->draw(volumeText);

        window->draw(*ghostButton);
        window->draw(ghostText);

        window->display();
    }

}

void Menu::updateVolumeText() {
    volumeText.setString("Volume:" + std::to_string(*volumePtr));
}

void Menu::updateWidthText() {
    widthText.setString("Width:" + std::to_string(*widthPtr));
}

void Menu::updateHeightText() {
    heightText.setString("Height:" + std::to_string(*heightPtr));
}

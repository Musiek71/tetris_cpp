//
// Created by musiek on 12/12/20.
//

#include <iostream>
#include "../../header/Menu/Menu.h"

Menu::Menu(sf::RenderWindow *window, int *widthPtr, int *heightPtr, int *volumePtr, int* gameStatePtr) {
   this-> window = window;
   this->widthPtr = widthPtr;
   this->heightPtr = heightPtr;
   this->volumePtr = volumePtr;
   this->gameStatePtr = gameStatePtr;

    startButton = new Button(sf::Vector2f(window->getSize().x/ 2 - 100, 0),
                             sf::Vector2f(200, 100),
                             sf::Color::Red,
                             "Start",
                             "gbfont.ttf");

}


Menu::~Menu() {
    delete startButton;
}

int Menu::run() {

    window->setSize(sf::Vector2u(800, 800));

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


        window->clear();
        window->draw(*startButton);
        window->display();
    }

    return 0;
}

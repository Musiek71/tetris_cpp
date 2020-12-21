//
// Created by musiek on 12/15/20.
//

#ifndef TETRIS_CPP_GAMEOVER_H
#define TETRIS_CPP_GAMEOVER_H


#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include "Button.h"
#include <iostream>
#include <fstream>
#include "../../header/StatesEnum.h"

class GameOver {
private:
    sf::RenderWindow* window;
    sf::Font* textFontPtr;
    sf::Text topText;
    sf::Text scoreText;
    sf::Text levelText;
    sf::Text nickText;

    ResourceManager* resourceManager;

    Button* menuButton;
    Button* gameButton;
    Button* leaderboardButton;

    int* gameStatePtr;
    int* scorePtr;
    int* lvlPtr;

    int volume;

    std::string filename;
    std::string nick;

public:
    GameOver(sf::RenderWindow* window, std::string filename, float volume, int* gameStatePtr, int* scorePtr, int* levelPtr, ResourceManager* resourceManager);

    virtual ~GameOver();

    void run();

    void addScore();
};


#endif //TETRIS_CPP_GAMEOVER_H

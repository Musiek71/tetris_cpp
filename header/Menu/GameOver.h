//
// Created by musiek on 12/15/20.
//

#ifndef TETRIS_CPP_GAMEOVER_H
#define TETRIS_CPP_GAMEOVER_H


#include <SFML/Graphics.hpp>
#include "Button.h"
#include <iostream>
#include <fstream>
#include "../../header/StatesEnum.h"

class GameOver {
private:
    sf::RenderWindow* window;
    sf::Font textFont;
    sf::Text topText;
    sf::Text scoreText;
    sf::Text nickText;

    Button* menuButton;
    Button* gameButton;
    Button* leaderboardButton;

    int* gameStatePtr;
    int* scorePtr;

    std::string filename;
    std::string nick;

public:
    GameOver(sf::RenderWindow* window, std::string filename, int* gameStatePtr, int* scorePtr);

    virtual ~GameOver();

    void run();

    void addScore();
};


#endif //TETRIS_CPP_GAMEOVER_H

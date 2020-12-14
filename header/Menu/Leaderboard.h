//
// Created by musiek on 12/14/20.
//

#ifndef TETRIS_CPP_LEADERBOARD_H
#define TETRIS_CPP_LEADERBOARD_H


#include <vector>
#include <SFML/Graphics.hpp>
#include "Score.h"
#include "../../header/StatesEnum.h"
#include "Button.h"

class Leaderboard {
private:
    sf::RenderWindow* window;
    sf::Font textFont;
    sf::Text leaderboardText;

    Button* menuButton;

    std::vector<Score*> scores;
    std::string filename;

    int* gameStatePtr;

public:
    Leaderboard(sf::RenderWindow* window, std::string filename, int* gameStatePtr);

    virtual ~Leaderboard();

    void sortScores();

    void run();
};


#endif //TETRIS_CPP_LEADERBOARD_H

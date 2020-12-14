//
// Created by musiek on 12/14/20.
//

#ifndef TETRIS_CPP_LEADERBOARD_H
#define TETRIS_CPP_LEADERBOARD_H


#include <vector>
#include <SFML/Graphics.hpp>
#include "Score.h"

class Leaderboard {
private:
    sf::RenderWindow* window;

    std::vector<Score*> scores;
    std::string filename;

    int* gameStatePtr;

public:
    Leaderboard(sf::RenderWindow* window, std::string filename, int* gameStatePtr);

    virtual ~Leaderboard();

    void sortScores();
};


#endif //TETRIS_CPP_LEADERBOARD_H

//
// Created by musiek on 12/4/20.
//

#include "../header/ScoreBoard.h"
#include <iostream>


ScoreBoard::ScoreBoard(std::string textfilename, std::string fontname, int level, int score, int x, int y, int tileSize) {
    //scoreboard initialization
    if (!texture.loadFromFile(textfilename)) {
        std::cout << "Scoreboard texture:"<< textfilename <<  " loading failed." << std::endl;
    }
    background.setTexture(texture);
    background.setPosition(x, y);

    this->level = level;
    this->score = score;

    if (!font.loadFromFile(fontname)) {
        std::cout << "Scoreboard font:"<< fontname <<  " loading failed." << std::endl;
    }

    levelText.setFont(font);
    scoreText.setFont(font);
    levelText.setPosition(x + tileSize, y + 3 * tileSize);
    scoreText.setPosition(x + tileSize, y + 1 * tileSize);
    levelText.setCharacterSize(24);
    scoreText.setCharacterSize(24);

    levelText.setString(std::to_string(level));
    scoreText.setString(std::to_string(score));

}


void ScoreBoard::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(background);
    target.draw(levelText);
    target.draw(scoreText);
}

void ScoreBoard::setLevel(int level) {
    this->level = level;
    levelText.setString(std::to_string(level));
}

void ScoreBoard::setScore(int score) {
    this->score = score;
    scoreText.setString(std::to_string(score));
}

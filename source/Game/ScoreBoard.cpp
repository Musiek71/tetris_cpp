//
// Created by musiek on 12/4/20.
//

#include "../../header/Game/ScoreBoard.h"


ScoreBoard::ScoreBoard(std::string textfilename, std::string fontname, ResourceManager* resourceManager,
                       int level, int score, int x, int y, int tileSize) {
    //scoreboard initialization
    backgroundTextPtr = resourceManager->getTexture(textfilename);

    background.setTexture(*backgroundTextPtr);
    background.setPosition(x, y);

    this->position.setPos(x, y);

    this->level = level;
    this->score = score;

    font = resourceManager->getFont(fontname);

    levelText.setFont(*font);
    scoreText.setFont(*font);
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

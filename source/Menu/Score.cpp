//
// Created by musiek on 12/14/20.
//

#include "../../header/Menu/Score.h"


Score::Score(const std::string &nick, int score, sf::Font* font) {
    this->nick = nick;
    this->score = score;
    scoreText.setFont(*font);
}

const std::string &Score::getNick() const {
    return nick;
}

void Score::setNick(const std::string &nick) {
    Score::nick = nick;
}

int Score::getScore() const {
    return score;
}

void Score::setScore(int score) {
    Score::score = score;
}

void Score::update(int x, int y, int position) {
    scoreText.setPosition(x, y);
    scoreText.setString(std::to_string(position) + nick + ":" + std::to_string(score));
    scoreText.setCharacterSize(32);
}

void Score::update(int x, int y, int position, std::string nick, int score) {
    this->nick = nick;
    this->score = score;
    this->update(x, y, position);
}

void Score::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(scoreText);
}
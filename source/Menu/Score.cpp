//
// Created by musiek on 12/14/20.
//

#include "../../header/Menu/Score.h"


Score::Score(const std::string &nick, int score, sf::Font* font) {
    this->nick = nick;
    this->score = score;
    nickText.setFont(*font);
    scoreText.setFont(*font);
}

const std::string &Score::getNick() const {
    return nick;
}

void Score::setNick(const std::string &nick) {
    Score::nick = nick;
}

long Score::getScore() const {
    return score;
}

void Score::setScore(long score) {
    Score::score = score;
}

void Score::update(int screenWidth, int y, int position) {
    nickText.setString(nick);
    nickText.setCharacterSize(32);
    nickText.setPosition(screenWidth / 5.f - nickText.getGlobalBounds().width / 2, y);

    scoreText.setString(std::to_string(score));
    scoreText.setCharacterSize(32);
    scoreText.setPosition(screenWidth / 5.f * 4 - scoreText.getGlobalBounds().width / 2, y);
}

void Score::update(int screenWidth, int y, int position, std::string nick, long score) {
    this->nick = nick;
    this->score = score;
    this->update(screenWidth, y, position);
}

void Score::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(nickText);
    target.draw(scoreText);
}
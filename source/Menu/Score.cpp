//
// Created by musiek on 12/14/20.
//

#include "../../header/Menu/Score.h"

Score::Score(const std::string &nick, int score) {
    this->nick = nick;
    this->score = score;
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

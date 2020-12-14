//
// Created by musiek on 12/14/20.
//

#ifndef TETRIS_CPP_SCORE_H
#define TETRIS_CPP_SCORE_H


#include <string>

class Score {
private:
    std::string nick;
    int score = 0;
public:
    Score(const std::string &nick, int score);

    const std::string &getNick() const;

    void setNick(const std::string &nick);

    int getScore() const;

    void setScore(int score);
};


#endif //TETRIS_CPP_SCORE_H

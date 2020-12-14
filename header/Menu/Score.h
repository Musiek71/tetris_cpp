//
// Created by musiek on 12/14/20.
//

#ifndef TETRIS_CPP_SCORE_H
#define TETRIS_CPP_SCORE_H


#include <string>
#include <SFML/Graphics.hpp>

class Score : public sf::Drawable {
private:
    sf::Text scoreText;
    sf::Font* font;

    std::string nick;
    int score = 0;
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    Score(const std::string &nick, int score, sf::Font* font);

    const std::string &getNick() const;

    void setNick(const std::string &nick);

    int getScore() const;

    void setScore(int score);

    void update(int x, int y, int position);

    void update(int x, int y, int position, std::string nick, int score);
};


#endif //TETRIS_CPP_SCORE_H

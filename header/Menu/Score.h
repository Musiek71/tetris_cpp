//
// Created by musiek on 12/14/20.
//

#ifndef TETRIS_CPP_SCORE_H
#define TETRIS_CPP_SCORE_H


#include <string>
#include <SFML/Graphics.hpp>

class Score : public sf::Drawable {
private:
    sf::Font* font;
    sf::Text nickText;
    sf::Text scoreText;

    std::string nick;
    long score = 0;
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    Score(const std::string &nick, long score, sf::Font* font);

    const std::string &getNick() const;

    void setNick(const std::string &nick);

    long getScore() const;

    void setScore(long score);

    void update(int screenWidth, int y, int position);

    void update(int screenWidth, int y, int position, std::string nick, long score);
};


#endif //TETRIS_CPP_SCORE_H

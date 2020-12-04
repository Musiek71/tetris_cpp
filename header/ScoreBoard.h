//
// Created by musiek on 12/4/20.
//

#ifndef TETRIS_CPP_SCOREBOARD_H
#define TETRIS_CPP_SCOREBOARD_H


#include <SFML/Graphics.hpp>

class ScoreBoard : public sf::Drawable, sf::Transformable {
private:
    sf::Font font;
    sf::Sprite background;
    sf::Texture texture;
    sf::Text scoreText;
    sf::Text levelText;

    int level = 1;
    int score = 0;

public:
    ScoreBoard(std::string textfilename, std::string fontname, int level, int score, int x, int y, int tileSize);

    void setLevel(int level);
    void setScore(int score);

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //TETRIS_CPP_SCOREBOARD_H

//
// Created by musiek on 12/4/20.
//

#ifndef TETRIS_CPP_SCOREBOARD_H
#define TETRIS_CPP_SCOREBOARD_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include "Point.h"
#include "../ResourceManager.h"

/**
 * Class representing the scoreboard.
 */
class ScoreBoard : public sf::Drawable, sf::Transformable {
private:
    /// Position of the scoreboard on the screen.
    Point position;

    /// A pointer to the font.
    sf::Font* font;

    /// A pointer to the background texture.
    sf::Texture* backgroundTextPtr;

    /// SFML sprite as a background.
    sf::Sprite background;

    /// SFML score Text field.
    sf::Text scoreText;

    /// SFML level Text field.
    sf::Text levelText;

    /// Current game level.
    int level = 1;

    /// Current game score.
    int score = 0;

public:

    /**
     * Main scoreboard constructor.
     *
     * Sets class fields, their positions, loads the resources from the resourceManager.
     *
     * @param textfilename The name of the background texture.
     * @param fontname The name of the font.
     * @param resourceManager A pointer to the main resource manager.
     * @param level Current game level.
     * @param score Current game score.
     * @param x The X position of the scoreboard on the screen.
     * @param y The Y position of the scoreboard on the screen.
     * @param tileSize A size of a single tile.
     */
    ScoreBoard(std::string textfilename, std::string fontname, ResourceManager* resourceManager,
               int level, int score, int x, int y, int tileSize);

    /**
     * Sets the level field of the scoreboard, then updates the SFML level Text field.
     * @param level Game level to set on the scoreboard.
     */
    void setLevel(int level);

    /**
     * Sets the score field of the scoreboard, then updates the SFML score Text field.
     * @param score Game score to set on the scoreboard.
     */
    void setScore(int score);

protected:
    /// Implementation of the SFML draw interface.
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //TETRIS_CPP_SCOREBOARD_H

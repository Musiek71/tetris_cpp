//
// Created by musiek on 12/14/20.
//

#ifndef TETRIS_CPP_SCORE_H
#define TETRIS_CPP_SCORE_H


#include <string>
#include <SFML/Graphics.hpp>

/**
 * Class representing a single score on the leaderboards.
 */
class Score : public sf::Drawable {
private:
    /// A pointer to the font.
    sf::Font* font;

    /// SFML nickname text field.
    sf::Text nickText;

    /// SFML score text field.
    sf::Text scoreText;

    /// Nickname.
    std::string nick;

    /// Score.
    int score = 0;

protected:
    /// Implementation of the SFML drawable interface.
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    /**
     * Main constructor.
     *
     * Sets the class fields.
     *
     * @param nick Nickname.
     * @param score Score value.
     * @param font Font pointer.
     */
    Score(const std::string &nick, int score, sf::Font* font);

    /// Returns the nickname of the score.
    const std::string &getNick() const;

    /// Sets the nickname of the score.
    void setNick(const std::string &nick);

    /// Returns the value of the score.
    long getScore() const;

    /// Sets the value of the score.
    void setScore(long score);

    /**
     * Set the position of the score on the screen.
     *
     * @param screenWidth Width of the screen.
     * @param y The Y position on the screen.
     * @param position Number of the score from top, beginning from 1.
     */
    void update(int screenWidth, int y, int position);

    /**
     * Set the position of the score on the screen.
     *
     * @param screenWidth Width of the screen.
     * @param y The Y position on the screen.
     * @param position Number of the score from top, beginning from 1.
     * @param nick Nickname of the score to be set.
     * @param score Value of the score to be set.
     */
    void update(int screenWidth, int y, int position, std::string nick, long score);
};


#endif //TETRIS_CPP_SCORE_H

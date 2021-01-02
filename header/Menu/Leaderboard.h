//
// Created by musiek on 12/14/20.
//

#ifndef TETRIS_CPP_LEADERBOARD_H
#define TETRIS_CPP_LEADERBOARD_H


#include <vector>
#include <SFML/Graphics.hpp>
#include "Score.h"
#include "../../header/StatesEnum.h"
#include "Button.h"

/**
 * Leaderboards screen, a single state of the game.
 */
class Leaderboard {
private:
    /// A pointer to the SFML window.
    sf::RenderWindow* window;

    /// A pointer to the font.
    sf::Font* textFontPtr;

    /// SFML leaderboard text field.
    sf::Text leaderboardText;

    /// A pointer to the main resource manager.
    ResourceManager* resourceManager;

    /// A pointer to the menu button.
    Button* menuButton;

    /**
     * A vector of score pointers.
     *
     * Holds all the loaded scores.
     */
    std::vector<Score*> scores;

    /// Filename of the scores file.
    std::string filename;

    /// A pointer to the main game state.
    int* gameStatePtr;

    /// A pointer to the main score variable.
    int* scorePtr;

public:

    /**
     * The main Leaderboard constructor.
     *
     * Sets the class fields and initializes the buttons and text fields.
     * Adds scores from the scores file to the scores vector.
     *
     * @param window A pointer to the SFML window.
     * @param filename Name of the scores file.
     * @param gameStatePtr A pointer to the main game state.
     * @param scorePtr A pointer to the main score variable.
     * @param resourceManager A pointer to the main resource manager.
     */
    Leaderboard(sf::RenderWindow* window, std::string filename, int* gameStatePtr, int* scorePtr, ResourceManager* resourceManager);

    /**
     * Main destructor.
     *
     * Frees the memory allocated for the scores in the scores vector.
     */
    virtual ~Leaderboard();

    /**
     * Sorts the scores vector using the score values.
     */
    void sortScores();

    /**
     * Main Leaderboard state loop.
     *
     * Shows 10 scores in a list.
     */
    void run();

};


#endif //TETRIS_CPP_LEADERBOARD_H

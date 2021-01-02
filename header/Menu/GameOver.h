//
// Created by musiek on 12/15/20.
//

#ifndef TETRIS_CPP_GAMEOVER_H
#define TETRIS_CPP_GAMEOVER_H


#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include "Button.h"
#include <iostream>
#include <fstream>
#include "../../header/StatesEnum.h"

/**
 * Game over screen, a single state of the game.
 */
class GameOver {
private:
    /// A pointer to the SFML window.
    sf::RenderWindow* window;

    /// A pointer to the font.
    sf::Font* textFontPtr;

    /// SFML Top text field.
    sf::Text topText;

    /// SFML Score text field.
    sf::Text scoreText;

    /// SFML Level text field.
    sf::Text levelText;

    /// SFML nick text field.
    sf::Text nickText;

    /// A pointer to the main resource manager.
    ResourceManager* resourceManager;

    /// A pointer to the menu button.
    Button* menuButton;

    /// A pointer to the game restart button.
    Button* gameButton;

    /// A pointer to the leaderboards button.
    Button* leaderboardButton;

    /// A pointer to the main game state.
    int* gameStatePtr;

    /// A pointer to the main score variable.
    int* scorePtr;

    /// A pointer to the main level variable.
    int* lvlPtr;

    /// Volume of the sound effects.
    int volume;

    /// Filename of the scores file.
    std::string filename;

    /// Nickname string.
    std::string nick;

public:
    /**
     * Main Game Over screen constructor.
     *
     * Sets all the class fields and initializes them.
     * Creates the buttons and text fields.
     *
     * @param window A pointer to SFML window.
     * @param filename Name of the scores file.
     * @param volume The game's sound volume.
     * @param gameStatePtr A pointer to the main game state.
     * @param scorePtr A pointer to the main score variable.
     * @param levelPtr A pointer to the main level variable.
     * @param resourceManager A pointer to the main resource manager.
     */
    GameOver(sf::RenderWindow* window, std::string filename, float volume, int* gameStatePtr, int* scorePtr, int* levelPtr, ResourceManager* resourceManager);

    /**
     * Main destructor.
     *
     * Frees the memory allocated for the buttons.
     */
    virtual ~GameOver();

    /**
     * Main Game over state loop.
     *
     * Accepts the nickname input, to save the score with the input.
     * On exit, saves the score in the score file using the addScore() method.
     */
    void run();

    /**
     * Adds the score to the scores file, using the nickname entered in the run() method.
     */
    void addScore();
};


#endif //TETRIS_CPP_GAMEOVER_H

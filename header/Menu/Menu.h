//
// Created by musiek on 12/12/20.
//

#ifndef TETRIS_CPP_MENU_H
#define TETRIS_CPP_MENU_H


#include "Button.h"
#include "../../header/StatesEnum.h"

/**
 * Main menu screen, a single state of the game.
 */
class Menu {
private:
    /// A pointer to the main SFML window.
    sf::RenderWindow* window;

    /// A pointer to the font.
    sf::Font* textFont;

    /// SFML width text field.
    sf::Text widthText;

    /// SFML height text field.
    sf::Text heightText;

    /// SFML volume text field.
    sf::Text volumeText;

    ///SFML ghost text field.
    sf::Text ghostText;

    /// A pointer to the main resource manager.
    ResourceManager* resourceManager;


    /// A pointer to the start button.
    Button* startButton;

    /// A pointer to the exit button.
    Button* exitButton;

    ///A pointer to the leaderboard button.
    Button* leaderboardButton;


    /// A pointer to the width increasing button.
    Button* increaseWidthButton;

    /// A pointer to the width decreasing button.
    Button* decreaseWidthButton;


    /// A pointer to the height increasing button.
    Button* increaseHeightButton;

    /// A pointer to the height decreasing button.
    Button* decreaseHeightButton;


    /// A pointer to the volume increasing button.
    Button* increaseVolumeButton;

    /// A pointer to the volume decreasing button.
    Button* decreaseVolumeButton;


    /// A pointer to the ghost flag button.
    Button* ghostButton;

    /// A pointer to the main width variable.
    int* widthPtr;

    /// A pointer to the main height variable.
    int* heightPtr;

    ///A pointer to the main volume variable.
    int* volumePtr;

    /// A pointer to the main game state variable.
    int* gameStatePtr;

    /// A pointer to the main ghost flag variable.
    bool* ghostFlagPtr;


public:
    /**
     * Main menu constructor.
     *
     * Initializes all the class fields.
     * Sets all the button and text fields.
     *
     * @param window A pointer to the SFML window.
     * @param widthPtr A pointer to the main width variable.
     * @param heightPtr A pointer to the main height variable.
     * @param volumePtr A pointer to the main volume variable.
     * @param gameStatePtr A pointer to the main game state variable.
     * @param ghostFlagPtr A pointer to the main ghost flag variable.
     * @param resourceManager A pointer to the main resource manager.
     */
    Menu(sf::RenderWindow *window, int *widthPtr, int *heightPtr, int *volumePtr, int* gameStatePtr, bool* ghostFlagPtr,
         ResourceManager* resourceManager);

    /**
     * Main destructor.
     *
     * Frees the memory allocated for the buttons.
     */
    virtual ~Menu();

    /**
     * Main menu loop.
     *
     * Allows to modify the parameters the game starts with.
     */
    void run();

    /// Update the volume text field.
    void updateVolumeText();

    // Update the width text field.
    void updateWidthText();

    /// Update the height text field.
    void updateHeightText();

};


#endif //TETRIS_CPP_MENU_H

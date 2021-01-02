//
// Created by musiek on 12/12/20.
//

#ifndef TETRIS_CPP_BUTTON_H
#define TETRIS_CPP_BUTTON_H


#include <SFML/Graphics.hpp>
#include "../ResourceManager.h"

/**
 * Class representing a single clickable button in the SFML window.
 */
class Button : public sf::Drawable {
private:
    /// The texture pointer of the released button.
    sf::Texture* releasedTexturePtr;

    /// The texture pointer of the pressed button.
    sf::Texture* pressedTexturePtr;

    /// The font pointer.
    sf::Font* buttonFontPtr;

    /// SFML RectangleShape representing the button rectangle.
    sf::RectangleShape buttonShape;

    /// SFML Text placed in the centre of the button.
    sf::Text buttonText;

    /// Flag representing the state of the button.
    bool isPressed = false;

    /// Flag representing the state of the button.
    bool isReleased = true;

protected:
    /// Implementation of the SFML draw interface.
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:

    /**
     * Main Button constructor.
     *
     * Creates a button ready to be placed in a SFML window.
     *
     * @param position SFML Vector2f representing the position of the button.
     * @param size SFML Vector2f representing the size of the button.
     * @param text Text to be placed in the centre of the button.
     * @param resourceManager A pointer to the main resource manager.
     */
    Button(sf::Vector2f position, sf::Vector2f size, std::string text, ResourceManager* resourceManager);

    /**
     * Sets the button text.
     * @param text Text to be set on the button.
     */
    void setText(std::string text);

    /**
     * Updates the button's state depending on the mouse position and the mouse events.
     *
     * @param mousePos SFML Vector2f representing the position of the mouse in the window.
     * @return True, if button is pressed and the mouse is over the button, else false.
     */
    bool updateButton(sf::Vector2f mousePos);

    /**
     * Checks, whether the mouse is set over the button.
     * @param mousePos SFML Vector2f representing the position of the mouse in the window.
     * @return True, if mouse is set (hovers) over the button.
     */
    bool mouseOnButton(sf::Vector2f mousePos);
};


#endif //TETRIS_CPP_BUTTON_H

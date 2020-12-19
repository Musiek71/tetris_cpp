//
// Created by musiek on 12/12/20.
//

#ifndef TETRIS_CPP_BUTTON_H
#define TETRIS_CPP_BUTTON_H


#include <SFML/Graphics.hpp>
#include "../ResourceManager.h"

class Button : public sf::Drawable {
private:
    sf::Texture* releasedTexturePtr;
    sf::Texture* pressedTexturePtr;
    sf::Font* buttonFontPtr;
    sf::RectangleShape buttonShape;
    sf::Text buttonText;
    bool isPressed = false;
    bool isReleased = true;
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:
    Button(sf::Vector2f position, sf::Vector2f size, std::string text, ResourceManager* resourceManager);

    void setText(std::string text);

    bool updateButton(sf::Vector2f mousePos);
    bool mouseOnButton(sf::Vector2f mousePos);
};


#endif //TETRIS_CPP_BUTTON_H

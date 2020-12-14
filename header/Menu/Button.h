//
// Created by musiek on 12/12/20.
//

#ifndef TETRIS_CPP_BUTTON_H
#define TETRIS_CPP_BUTTON_H


#include <SFML/Graphics.hpp>

class Button : public sf::Drawable {
private:
    sf::Color buttonColor;
    sf::RectangleShape buttonShape;
    sf::Font* buttonFont;
    sf::Text buttonText;
    bool isPressed = false;
    bool isReleased = true;
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
public:
    Button(sf::Vector2f position, sf::Vector2f size, sf::Color buttonColor, std::string text, sf::Font* font);

    bool updateButton(sf::Vector2f mousePos);
    bool mouseOnButton(sf::Vector2f mousePos);
};


#endif //TETRIS_CPP_BUTTON_H

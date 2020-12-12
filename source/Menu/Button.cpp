//
// Created by musiek on 12/12/20.
//

#include "../../header/Menu/Button.h"

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(buttonShape);
    target.draw(buttonText);
}

bool Button::mouseOnButton(sf::Vector2f mousePos) {
    return buttonShape.getGlobalBounds().contains(mousePos);
}

bool Button::updateButton(sf::Vector2f mousePos) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && isPressed)
        return false;
    else
        isPressed = false;

    if (buttonShape.getGlobalBounds().contains(mousePos)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            isPressed = true;
            return true;
        }
    }
    return false;
}

Button::Button(sf::Vector2f position, sf::Vector2f size, sf::Color buttonColor, std::string text, std::string fontName) {
    this->buttonColor = buttonColor;

    buttonShape.setPosition(position);
    buttonShape.setSize(size);
    buttonShape.setFillColor(buttonColor);

    buttonFont.loadFromFile(fontName);

    buttonText.setFont(buttonFont);
    buttonText.setCharacterSize(buttonShape.getGlobalBounds().height / 4);
    buttonText.setString(text);
    buttonText.setPosition(buttonShape.getPosition().x,
                           buttonShape.getPosition().y);
}


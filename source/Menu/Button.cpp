//
// Created by musiek on 12/12/20.
//

#include <iostream>
#include "../../header/Menu/Button.h"

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(buttonShape);
    target.draw(buttonText);
}

bool Button::mouseOnButton(sf::Vector2f mousePos) {
    return buttonShape.getGlobalBounds().contains(mousePos);
}

bool Button::updateButton(sf::Vector2f mousePos) {

    if (buttonShape.getGlobalBounds().contains(mousePos)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            isPressed = true;
            isReleased = false;
            buttonShape.setTexture(pressedTexturePtr);
        } else if (isPressed) {
            isPressed = false;
            isReleased = true;
            buttonShape.setTexture(releasedTexturePtr);
            return true;
        }
    } else if (isPressed) {
        isPressed = false;
        isReleased = true;
        buttonShape.setTexture(releasedTexturePtr);
    }
    return false;
}

Button::Button(sf::Vector2f position, sf::Vector2f size, std::string text, ResourceManager* resourceManager) {

    releasedTexturePtr = resourceManager->getTexture("button_released.png");
    pressedTexturePtr = resourceManager->getTexture("button_pressed.png");

    buttonShape.setPosition(position);
    buttonShape.setSize(size);
    buttonShape.setTexture(releasedTexturePtr);

    buttonFontPtr = resourceManager->getFont("gbfont.ttf");

    buttonText.setFont(*buttonFontPtr);
    buttonText.setCharacterSize(buttonShape.getGlobalBounds().height / 4);
    buttonText.setString(text);
    buttonText.setPosition(buttonShape.getPosition().x + buttonShape.getGlobalBounds().width / 2 - buttonText.getGlobalBounds().width / 2,
                           buttonShape.getPosition().y + buttonShape.getGlobalBounds().height / 2 - buttonText.getGlobalBounds().height / 2 - buttonText.getCharacterSize() / 2);
}

void Button::setText(std::string text) {
    this->buttonText.setString(text);
    buttonText.setPosition(buttonShape.getPosition().x + buttonShape.getGlobalBounds().width / 2 - buttonText.getGlobalBounds().width / 2,
                           buttonShape.getPosition().y + buttonShape.getGlobalBounds().height / 2 - buttonText.getGlobalBounds().height / 2 - buttonText.getCharacterSize() / 2);
}


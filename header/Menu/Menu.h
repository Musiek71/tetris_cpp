//
// Created by musiek on 12/12/20.
//

#ifndef TETRIS_CPP_MENU_H
#define TETRIS_CPP_MENU_H


#include "Button.h"
#include "../../header/StatesEnum.h"

class Menu {
private:
    sf::RenderWindow* window;

    Button* startButton;
    Button* exitButton;
    Button* leaderboardButton;

    Button* increaseWidthButton;
    Button* decreaseWidthButton;

    Button* increaseVolumeButton;
    Button* decreaseVolumeButton;

    sf::Text widthText;
    sf::Text heightText;
    sf::Text volumeText;

    int* widthPtr;
    int* heightPtr;
    int* volumePtr;
    int* gameStatePtr;


public:
    Menu(sf::RenderWindow *window, int *widthPtr, int *heightPtr, int *volumePtr, int* gameStatePtr);
    virtual ~Menu();

    int run();


};


#endif //TETRIS_CPP_MENU_H

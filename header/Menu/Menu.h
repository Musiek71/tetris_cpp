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
    sf::Font* textFont;
    sf::Text widthText;
    sf::Text heightText;
    sf::Text volumeText;
    sf::Text ghostText;

    ResourceManager* resourceManager;

    Button* startButton;
    Button* exitButton;
    Button* leaderboardButton;

    Button* increaseWidthButton;
    Button* decreaseWidthButton;

    Button* increaseHeightButton;
    Button* decreaseHeightButton;

    Button* increaseVolumeButton;
    Button* decreaseVolumeButton;

    Button* ghostButton;

    int* widthPtr;
    int* heightPtr;
    int* volumePtr;
    int* gameStatePtr;
    bool* ghostFlagPtr;


public:
    Menu(sf::RenderWindow *window, int *widthPtr, int *heightPtr, int *volumePtr, int* gameStatePtr, bool* ghostFlagPtr,
         ResourceManager* resourceManager);
    virtual ~Menu();

    void run();

    void updateVolumeText();
    void updateWidthText();
    void updateHeightText();


};


#endif //TETRIS_CPP_MENU_H

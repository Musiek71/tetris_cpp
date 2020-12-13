#include <iostream>
#include "../header/Game/Game.h"
#include "../header/Menu/Button.h"
#include "../header/StatesEnum.h"
#include "../header/Menu/Menu.h"


int main() {
    //TODO state machine for HOLD and clearing animations to implement in the future??
    //TODO state machine for main menu
    //TODO sounds
    //TODO basic layout with background placeholder
    //TODO HOLD function
    //TODO errors while loading things
    //TODO make rotation with keypressed/keyreleased flag
    //TODO game over
    //TODO leaderboards

    int volume = 10;
    int score = 0;
    int level = 1;
    int boardWidth = 10;
    int boardHeight = 20;
    int gameState = MENU;

    sf::RenderWindow window(sf::VideoMode(800, 800), "Tetris");
    window.setVerticalSyncEnabled(true);


    while (window.isOpen()) {
        switch (gameState) {
            case MENU: {
                Menu menu(&window, &boardWidth, &boardHeight, &volume, &gameState);
                menu.run();
                break;
            }

            case GAME: {
                Game game(boardWidth, boardHeight, &window, volume, &gameState);
                game.run();
                break;
            }

            case GAMEOVER: {
                gameState = MENU; // temporary
            }
        }
    }

//    Game game( 10, 20, &window, 0);
//    game.run();

    return 0;
}

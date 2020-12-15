#include <iostream>
#include "../header/Game/Game.h"
#include "../header/Menu/Button.h"
#include "../header/StatesEnum.h"
#include "../header/Menu/Menu.h"
#include "../header/Menu/Leaderboard.h"
#include "../header/Menu/GameOver.h"


int main() {
    //TODO basic layout with background placeholder
    //TODO HOLD function
    //TODO errors while loading things
    //TODO make rotation with keypressed/keyreleased flag
    //TODO game over
    //TODO leaderboards
    //TODO fix view at main menu after game over
    //TODO fix scores file opening when file doesn't exist

    int volume = 0;
    int score = 0;
    int level = 1;
    int boardWidth = 5;
    int boardHeight = 10;
    int gameState = MENU;

    sf::RenderWindow window(sf::VideoMode(800, 800), "Tetris");
    window.setVerticalSyncEnabled(true);

    while (window.isOpen()) {
        if (gameState == EXIT)
            break;

        switch (gameState) {
            case MENU: {
                Menu menu(&window, &boardWidth, &boardHeight, &volume, &gameState);
                menu.run();
                break;
            }

            case GAME: {
                Game game(&window, boardWidth, boardHeight, volume, &gameState, &score, &level);
                game.run();
                break;
            }

            case GAMEOVER: {
                GameOver gameOver(&window, "scores.txt", &gameState, &score);
                gameOver.run();
                break;
            }

            case LEADERBOARD: {
                Leaderboard leaderboard(&window, "scores.txt", &gameState, &score);
                leaderboard.run();
                break;
            }
        }
    }

//    Game game( 10, 20, &window, 0);
//    game.run();

    return 0;
}

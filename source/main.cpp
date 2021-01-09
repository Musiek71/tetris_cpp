#include "../header/Game/Game.h"
#include "../header/Menu/Button.h"
#include "../header/Menu/Menu.h"
#include "../header/Menu/Leaderboard.h"
#include "../header/Menu/GameOver.h"


int main() {

    int volume = 10;
    int score = 0;
    int level = 1;
    int boardWidth = 10;
    int boardHeight = 20;
    int gameState = MENU;
    bool ghostFlag = true;

    sf::RenderWindow window(sf::VideoMode(800, 800), "Tetris");
    window.setVerticalSyncEnabled(true);

    ResourceManager resourceManager;




    while (window.isOpen()) {
        if (gameState == EXIT)
            break;

        switch (gameState) {
            case MENU: {
                Menu menu(&window, &boardWidth, &boardHeight, &volume, &gameState, &ghostFlag, &resourceManager);
                menu.run();
                break;
               }

            case GAME: {
                Game game(&window, boardWidth, boardHeight, (float)volume, &gameState, &score, &level, ghostFlag, &resourceManager);
                game.run();
                break;
            }

            case GAMEOVER: {
                GameOver gameOver(&window, "scores.txt", volume, &gameState, &score, &level, &resourceManager);
                gameOver.run();
                break;
            }

            case LEADERBOARD: {
                Leaderboard leaderboard(&window, "scores.txt", &gameState, &score, &resourceManager);
                leaderboard.run();
                break;
            }

            default:
                gameState = EXIT;
                break;
        }
    }

    return 0;
}

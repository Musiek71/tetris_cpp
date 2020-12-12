#include <iostream>
#include "../header/Game/Game.h"


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

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Tetris");
    window.setVerticalSyncEnabled(true);

    Game game( 10, 20, &window, 20);
    game.run();

    return 0;
}

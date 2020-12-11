#include <iostream>
#include "../header/Game.h"


int main() {
    //TODO state machine for HOLD and clearing animations to implement in the future??
    //TODO state machine for main menu
    //TODO sounds
    //TODO basic layout with background placeholder
    //TODO HOLD function
    //TODO ability to configure board's size
    //TODO errors while loading things
    //TODO make rotation with keypressed/keyreleased flag
    //TODO game over

    Game game(10, 20);
    game.run();

    return 0;
}

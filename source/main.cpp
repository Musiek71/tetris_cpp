#include <iostream>
#include "../header/Game.h"


int main() {
    //TODO state machine for HOLD and clearing animations to implement in the future??
    //TODO sounds
    //TODO basic layout with background placeholder
    //TODO HOLD function
    //TODO ability to configure board's size
    //TODO errors while loading things
    //TODO make rotation with keypressed/keyreleased flag
    //TODO separate class for next piece with background texture and piece for drawing, methods for updating the current piece
    //as it will make the code clearer
    //TODO game over

    Game game;
    game.run();

    return 0;
}

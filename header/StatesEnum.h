//
// Created by musiek on 12/13/20.
//

#ifndef TETRIS_CPP_STATESENUM_H
#define TETRIS_CPP_STATESENUM_H

/**
 * Enum for game states
 */
enum GameState {
    /// Main menu state.
    MENU,
    /// Main game playing state.
    GAME,
    /// Game over state - showing score and nick input.
    GAMEOVER,
    /// Leaderboard state.
    LEADERBOARD,
    /// Exit state (flag)
    EXIT
};

#endif //TETRIS_CPP_STATESENUM_H

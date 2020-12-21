//
// Created by musiek on 17.11.2020.
//

#ifndef TETRIS_CPP_PIECEENUM_H
#define TETRIS_CPP_PIECEENUM_H

/**
 * Enum for piece distinguishing
 */
enum PieceEnum {
    /// Empty block.
    NONE = 0,
    /// Wall block.
    WALL,
    /// I piece.
    IP,
    /// J piece.
    JP,
    /// L piece.
    LP,
    /// O piece.
    OP,
    /// S piece.
    SP,
    /// T piece.
    TP,
    /// Z piece.
    ZP,
    /// Ghost block of the falling tetromino.
    GHOST
};


#endif //TETRIS_CPP_PIECEENUM_H

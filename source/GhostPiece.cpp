//
// Created by musiek on 12/4/20.
//

#include "../header/GhostPiece.h"
#include "../header/PieceEnum.h"

GhostPiece::GhostPiece(std::string tileset, int rotation, Point shapes[4][4]) : Piece(tileset, rotation, GHOST, shapes) {}

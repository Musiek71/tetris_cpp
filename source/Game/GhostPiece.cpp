//
// Created by musiek on 12/4/20.
//

#include "../../header/Game/GhostPiece.h"
#include "../../header/Game/PieceEnum.h"

GhostPiece::GhostPiece(std::string tileset, int rotation, Point* shapes) : Piece(tileset, rotation, GHOST, shapes) {}

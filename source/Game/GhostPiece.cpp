//
// Created by musiek on 12/4/20.
//

#include "../../header/Game/GhostPiece.h"
#include "../../header/PieceEnum.h"

GhostPiece::GhostPiece(std::string tileset, ResourceManager* resourceManager, int rotation, Point* shapes) : Piece(tileset, resourceManager, rotation, GHOST, shapes) {}

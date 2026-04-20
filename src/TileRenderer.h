#pragma once

#include <vector>

#include "Color.h"

class TileSet;

namespace TileRenderer {

struct RenderTile {
    Color color;
    int value;
    bool fromHand = false;
};

void printTileSet(const TileSet& tiles, bool handStyle = false);
void printTiles(const std::vector<RenderTile>& tiles);

}

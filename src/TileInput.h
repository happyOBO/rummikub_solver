#pragma once

class TileSet;

namespace TileInput {

void readHand(TileSet& hand);
void readTablePlacement(TileSet& table, TileSet* hand);

}

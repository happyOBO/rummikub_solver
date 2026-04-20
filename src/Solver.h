#pragma once

class TileSet;

namespace Solver {

// Hand-only: all valid groups/runs in the user's hand.
void printSameValueGroups(const TileSet& hand);
void printRuns(const TileSet& hand);

// Hand + table pool: combinations that must use at least one hand tile.
void printSameValueGroups(const TileSet& hand, const TileSet& table);
void printRuns(const TileSet& hand, const TileSet& table);

}

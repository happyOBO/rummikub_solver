#include "Solver.h"

#include <vector>

#include "Color.h"
#include "TileRenderer.h"
#include "TileSet.h"

namespace Solver {

namespace {

using TileRenderer::RenderTile;

// Enumerate all same-value groups (3+ colors, same number). When `table` is
// non-null, table tiles fill in slots where hand lacks the color, and at least
// one hand tile must participate.
void emitGroups(const TileSet& hand, const TileSet* table) {
    const bool requireHandTile = table != nullptr;
    for (int value = 1; value <= MAX_TILE_VALUE; ++value) {
        std::vector<RenderTile> group;
        bool hasHand = false;
        for (Color color : ALL_COLORS) {
            if (hand.count(color, value) > 0) {
                group.push_back({color, value, true});
                hasHand = true;
            } else if (table && table->count(color, value) > 0) {
                group.push_back({color, value, false});
            }
        }
        if (group.size() >= 3 && (!requireHandTile || hasHand)) {
            TileRenderer::printTiles(group);
        }
    }
}

// Enumerate all runs (3+ consecutive, same color). When `table` is non-null,
// table tiles fill in gaps where hand lacks the value, and at least one hand
// tile must participate in the run.
void emitRuns(const TileSet& hand, const TileSet* table) {
    const bool requireHandTile = table != nullptr;
    for (Color color : ALL_COLORS) {
        std::vector<RenderTile> run;
        bool hasHand = false;
        for (int value = 1; value <= MAX_TILE_VALUE + 1; ++value) {
            const bool handHas  = value <= MAX_TILE_VALUE && hand.count(color, value) > 0;
            const bool tableHas = value <= MAX_TILE_VALUE && table && table->count(color, value) > 0;
            const bool present  = handHas || tableHas;

            if (!present) {
                if (run.size() >= 3 && (!requireHandTile || hasHand)) {
                    TileRenderer::printTiles(run);
                }
                run.clear();
                hasHand = false;
            } else {
                run.push_back({color, value, handHas});
                if (handHas) hasHand = true;
            }
        }
    }
}

}  // namespace

void printSameValueGroups(const TileSet& hand) {
    emitGroups(hand, nullptr);
}

void printSameValueGroups(const TileSet& hand, const TileSet& table) {
    emitGroups(hand, &table);
}

void printRuns(const TileSet& hand) {
    emitRuns(hand, nullptr);
}

void printRuns(const TileSet& hand, const TileSet& table) {
    emitRuns(hand, &table);
}

}

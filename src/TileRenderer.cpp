#include "TileRenderer.h"

#include <cstdio>
#include <iostream>

#include "TileSet.h"

namespace TileRenderer {

namespace {

constexpr int HAND_BORDER_ANSI = 34;  // blue

void printBorderSegment(const char* text, bool highlight) {
    if (highlight) std::printf("\033[%dm%s\033[0m  ", HAND_BORDER_ANSI, text);
    else           std::printf("%s  ", text);
}

void printTilesOfColor(const TileSet& tiles, Color color) {
    for (int value = 1; value <= MAX_TILE_VALUE; ++value) {
        int n = tiles.count(color, value);
        for (int j = 0; j < n; ++j) {
            std::printf("|");
            std::printf("\033[%dm%2d\033[0m", static_cast<int>(color), value);
            std::printf("|  ");
        }
    }
}

}  // namespace

void printTileSet(const TileSet& tiles, bool handStyle) {
    const int total = tiles.total();
    for (int i = 0; i < total; ++i) printBorderSegment(".___", handStyle);
    std::cout << std::endl;

    for (Color c : ALL_COLORS) printTilesOfColor(tiles, c);

    std::cout << std::endl;
    for (int i = 0; i < total; ++i) printBorderSegment("|__|", handStyle);
    std::cout << std::endl;
}

void printTiles(const std::vector<RenderTile>& tiles) {
    std::cout << std::endl;
    for (const auto& t : tiles) printBorderSegment(".___", t.fromHand);
    std::cout << std::endl;
    for (const auto& t : tiles) {
        std::printf("|");
        std::printf("\033[%dm%2d\033[0m", static_cast<int>(t.color), t.value);
        std::printf("|  ");
    }
    std::cout << std::endl;
    for (const auto& t : tiles) printBorderSegment("|__|", t.fromHand);
    std::cout << std::endl;
}

}

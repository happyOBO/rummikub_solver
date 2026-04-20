#include "TileInput.h"

#include <iostream>

#include "Banner.h"
#include "Color.h"
#include "TileSet.h"

namespace TileInput {

namespace {

struct ColorPrompt {
    Color color;
    const char* label;
};

constexpr ColorPrompt COLOR_PROMPTS[] = {
    {Color::Red,    "Red"},
    {Color::Blue,   "Blue"},
    {Color::Yellow, "Yellow"},
    {Color::Black,  "Black"},
};

bool readOneColor(TileSet& target, TileSet* source, Color color,
                  const char* label, const char* kind) {
    int count = 0;
    std::cout << "# of " << kind << " " << label << " Tiles (ex: 5): ";
    std::cin >> count;
    std::cout << kind << " " << label << " Tiles (ex: 1 3 5): ";
    for (int i = 0; i < count; ++i) {
        int value = 0;
        std::cin >> value;
        if (value < 1 || value > MAX_TILE_VALUE) {
            Banner::showError();
            return false;
        }
        if (source && !source->tryRemove(color, value)) {
            Banner::showError();
            return false;
        }
        target.add(color, value);
    }
    return true;
}

}  // namespace

void readHand(TileSet& hand) {
    std::cout << "Write down the tiles you have.\n" << std::endl;
    for (const auto& p : COLOR_PROMPTS) {
        if (!readOneColor(hand, nullptr, p.color, p.label, "Received")) return;
    }
}

void readTablePlacement(TileSet& table, TileSet* hand) {
    std::cout << "Write down the new tiles on the table.\n" << std::endl;
    for (const auto& p : COLOR_PROMPTS) {
        if (!readOneColor(table, hand, p.color, p.label, "new")) return;
    }
}

}

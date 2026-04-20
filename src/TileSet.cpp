#include "TileSet.h"

TileSet::TileSet() : total_(0) {
    clear();
}

void TileSet::clear() {
    red_.clear();
    blue_.clear();
    yellow_.clear();
    black_.clear();
    for (int i = 1; i <= MAX_TILE_VALUE; ++i) {
        red_[i]    = 0;
        blue_[i]   = 0;
        yellow_[i] = 0;
        black_[i]  = 0;
    }
    total_ = 0;
}

std::map<int, int>& TileSet::mapOf(Color color) {
    switch (color) {
        case Color::Red:    return red_;
        case Color::Blue:   return blue_;
        case Color::Yellow: return yellow_;
        case Color::Black:  return black_;
    }
    return red_;
}

const std::map<int, int>& TileSet::tilesOf(Color color) const {
    switch (color) {
        case Color::Red:    return red_;
        case Color::Blue:   return blue_;
        case Color::Yellow: return yellow_;
        case Color::Black:  return black_;
    }
    return red_;
}

void TileSet::add(Color color, int value) {
    mapOf(color)[value]++;
    total_++;
}

bool TileSet::tryRemove(Color color, int value) {
    auto& m = mapOf(color);
    auto it = m.find(value);
    if (it == m.end() || it->second <= 0) return false;
    it->second--;
    total_--;
    return true;
}

int TileSet::count(Color color, int value) const {
    const auto& m = tilesOf(color);
    auto it = m.find(value);
    return it == m.end() ? 0 : it->second;
}

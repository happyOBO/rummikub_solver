#pragma once

enum class Color : int {
    Black  = 0,
    Red    = 31,
    Yellow = 33,
    Blue   = 36
};

inline constexpr int MAX_TILE_VALUE = 13;

inline constexpr Color ALL_COLORS[] = {
    Color::Red, Color::Blue, Color::Yellow, Color::Black
};

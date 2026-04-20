#pragma once

#include <map>
#include "Color.h"

class TileSet {
public:
    TileSet();

    void clear();
    void add(Color color, int value);
    bool tryRemove(Color color, int value);
    int  count(Color color, int value) const;
    int  total() const { return total_; }

    const std::map<int, int>& tilesOf(Color color) const;

private:
    std::map<int, int>& mapOf(Color color);

    std::map<int, int> red_;
    std::map<int, int> blue_;
    std::map<int, int> yellow_;
    std::map<int, int> black_;
    int total_;
};

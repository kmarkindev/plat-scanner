#pragma once

#include <utility>

namespace ps
{
    struct RelicFinderParams
    {
        int partsCount;
        std::pair<int, int> resolution;
        std::pair<int, int> aspectRatio;
    };
}
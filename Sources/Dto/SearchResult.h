#pragma once

#include <string>
#include <array>

namespace ps
{
    struct SearchResult
    {
        std::string name;
        bool isTradeable;
        int avgPriceInStore;
        std::array<int, 5> onlinePrices;
        std::array<int, 5> offlinePrices;
    };
}
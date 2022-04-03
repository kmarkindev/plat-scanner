#pragma once

#include <vector>

namespace ps
{
    struct OrderBestPrices
    {
        std::vector<int> ingamePrices;
        std::vector<int> onlinePrices;
        std::vector<int> offlinePrices;
    };
}
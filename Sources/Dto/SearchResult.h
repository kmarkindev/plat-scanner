#pragma once

#include <string>
#include <array>
#include <Models/RelicItem.h>
#include "OrderBestPrices.h"

namespace ps
{
    struct SearchResult
    {
        bool wasFound;
        RelicItem item;
        OrderBestPrices bestPrices;
    };
}
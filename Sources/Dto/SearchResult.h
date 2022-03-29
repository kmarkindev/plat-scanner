#pragma once

#include <string>
#include <array>
#include <Models/RelicItem.h>
#include "OrderBestPrices.h"

namespace ps
{
    struct SearchResult
    {
        RelicItem item;
        OrderBestPrices bestPrices;
    };
}
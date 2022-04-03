#pragma once

#include <Dto/OrderBestPrices.h>
#include <vector>
#include <Models/ItemOrder.h>
#include <iterator>
#include <cmath>
#include <algorithm>

namespace ps
{
    class BestPricesFinder
    {
    public:
        OrderBestPrices SearchBestPrices(const std::vector<ItemOrder>& orders);
    };
}



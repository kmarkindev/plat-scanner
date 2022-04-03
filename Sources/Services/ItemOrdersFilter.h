#pragma once

#include <vector>
#include <Models/ItemOrder.h>

namespace ps
{
    class ItemOrdersFilter
    {
    public:
        void FilterOrders(std::vector<ItemOrder>& orders);
    };
}



#include "ItemOrdersFilter.h"

void ps::ItemOrdersFilter::FilterOrders(std::vector<ItemOrder>& orders)
{
    auto newEnd = std::remove_if(orders.begin(), orders.end(), [](const ItemOrder& order)
    {
        return !order.IsVisible()
            || order.GetType() != ItemOrder::Type::Sell
            || order.GetRegion() != "en";
    });

    orders.erase(newEnd, orders.end());
}

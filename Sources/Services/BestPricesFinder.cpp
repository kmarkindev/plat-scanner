#include "BestPricesFinder.h"

ps::OrderBestPrices ps::BestPricesFinder::SearchBestPrices(const std::vector<ItemOrder>& orders)
{
    auto inGameStatus = [](const ItemOrder& o){ return o.GetStatus() == ItemOrder::Status::InGame; };
    auto onlineStatus = [](const ItemOrder& o){ return o.GetStatus() == ItemOrder::Status::Online; };
    auto offlineStatus = [](const ItemOrder& o){ return o.GetStatus() == ItemOrder::Status::Offline; };

    std::vector<ItemOrder> inGameOrders;
    std::vector<ItemOrder> onlineOrders;
    std::vector<ItemOrder> offlineOrders;

    // To avoid lots of reallocations
    inGameOrders.reserve(ceil(orders.size() / 4));
    onlineOrders.reserve(ceil(orders.size() / 4));
    offlineOrders.reserve(ceil(orders.size() / 2));

    // Filter orders
    std::copy_if(orders.begin(), orders.end(), std::back_inserter(inGameOrders), inGameStatus);
    std::copy_if(orders.begin(), orders.end(), std::back_inserter(onlineOrders), onlineStatus);
    std::copy_if(orders.begin(), orders.end(), std::back_inserter(offlineOrders), offlineStatus);

    // Check if there are 5 orders
    size_t inGameOrdersCount = inGameOrders.size() >= 5 ? 5 : inGameOrders.size();
    size_t onlineOrdersCount = onlineOrders.size() >= 5 ? 5 : onlineOrders.size();
    size_t offlineOrdersCount = offlineOrders.size() >= 5 ? 5 : offlineOrders.size();

    auto comparator = [](const ItemOrder& a, const ItemOrder& b){ return a.GetCost() < b.GetCost(); };

    // Sort 5 best prices
    std::partial_sort(inGameOrders.begin(), inGameOrders.begin() + inGameOrdersCount, inGameOrders.end(), comparator);
    std::partial_sort(onlineOrders.begin(), onlineOrders.begin() + onlineOrdersCount, onlineOrders.end(), comparator);
    std::partial_sort(offlineOrders.begin(), offlineOrders.begin() + offlineOrdersCount, offlineOrders.end(), comparator);

    OrderBestPrices result;

    auto transformer = [](const ItemOrder& o){ return o.GetCost(); };

    // Move best prices in result
    std::transform(inGameOrders.begin(), inGameOrders.begin() + inGameOrdersCount, std::back_inserter(result.ingamePrices), transformer);
    std::transform(onlineOrders.begin(), onlineOrders.begin() + onlineOrdersCount, std::back_inserter(result.onlinePrices), transformer);
    std::transform(offlineOrders.begin(), offlineOrders.begin() + offlineOrdersCount, std::back_inserter(result.offlinePrices), transformer);

    return result;
}

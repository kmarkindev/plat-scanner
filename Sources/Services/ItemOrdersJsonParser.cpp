#include "ItemOrdersJsonParser.h"

std::vector<ps::ItemOrder> ps::ItemOrdersJsonParser::ParseFromString(std::string_view jsonString)
{
    auto json = nlohmann::json::parse(jsonString)["payload"]["orders"];

    size_t itemsCount = json.size();

    std::vector<ItemOrder> orders;
    orders.reserve(itemsCount);

    for(size_t i = 0; i < itemsCount; ++i)
    {
        auto orderJson = json[i];

        ItemOrder::Status status = ItemOrder::StatusFromString(orderJson["user"]["status"]);
        ItemOrder::Type type = ItemOrder::TypeFromString(orderJson["order_type"]);

        orders.emplace_back(orderJson["platinum"], status, type, orderJson["region"], orderJson["visible"]);
    }

    return orders;
}

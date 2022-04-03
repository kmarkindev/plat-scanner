#pragma once

#include <nlohmann/json.hpp>
#include <Models/ItemOrder.h>
#include <vector>

namespace ps
{
    class ItemOrdersJsonParser
    {
    public:
        [[nodiscard]] std::vector<ItemOrder> ParseFromString(std::string_view jsonString);
    };
}


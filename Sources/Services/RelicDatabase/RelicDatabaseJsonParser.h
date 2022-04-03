#pragma once

#include <string>
#include <vector>
#include <Models/RelicItemsDatabase.h>
#include <nlohmann/json.hpp>

namespace ps
{
    class RelicDatabaseJsonParser
    {
    public:
        [[nodiscard]] RelicItemsDatabase ParseFromString(std::string_view jsonString);
    };
}



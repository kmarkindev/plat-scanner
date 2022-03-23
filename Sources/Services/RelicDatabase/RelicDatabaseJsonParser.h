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
        RelicItemsDatabase ParseFromString(std::string jsonString);
    };
}



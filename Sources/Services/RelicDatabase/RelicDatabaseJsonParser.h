#pragma once

#include <string>
#include <Dto/RelicItemsDatabase.h>
#include <nlohmann/json.hpp>

namespace ps
{
    class RelicDatabaseJsonParser
    {
    public:
        RelicItemsDatabase ParseFromString(std::string jsonString);
    };
}



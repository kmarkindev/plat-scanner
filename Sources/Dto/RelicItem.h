#pragma once

#include <string>

namespace ps
{
    struct RelicItem
    {
        std::string id;
        std::string name;
        bool tradeable = true;
        int suggestedPrice = -1;
    };
}
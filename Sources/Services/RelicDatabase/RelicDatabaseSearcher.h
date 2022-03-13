#pragma once

#include <Dto/RelicItemsDatabase.h>
#include <string>
#include <fuzzywuzzy.hpp>

namespace ps
{
    class RelicDatabaseSearcher
    {
    public:
        explicit RelicDatabaseSearcher(const RelicItemsDatabase& db);
        RelicItem SearchForBestMatch(std::string itemName);
    private:
        RelicItemsDatabase _db;
    };
}



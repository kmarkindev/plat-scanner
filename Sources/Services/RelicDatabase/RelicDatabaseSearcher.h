#pragma once

#include <Dto/RelicItemsDatabase.h>
#include <string>
#include "RelicItemNameCleaner.h"

namespace ps
{
    class RelicDatabaseSearcher
    {
    public:
        explicit RelicDatabaseSearcher(const RelicItemsDatabase& db);
        std::pair<bool, ps::RelicItem> SearchForBestMatch(std::string itemName);
    private:
        RelicItemsDatabase _db;
        RelicItemNameCleaner _nameCleaner;
    };
}



#pragma once

#include <Models/RelicItemsDatabase.h>
#include <string>
#include <rapidfuzz/fuzz.hpp>
#include <locale>
#include <codecvt>

namespace ps
{
    class RelicDatabaseSearcher
    {
    public:
        explicit RelicDatabaseSearcher(RelicItemsDatabase  db);
        std::pair<bool, ps::RelicItem> SearchForBestMatch(const std::string& itemName);
    private:
        RelicItemsDatabase _db;

        std::u32string toUtf32(const std::string &s);
    };
}



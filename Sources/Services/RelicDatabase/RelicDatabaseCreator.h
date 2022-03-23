#pragma once

#include <string>
#include <Models/RelicItemsDatabase.h>
#include "RelicDatabaseJsonParser.h"
#include <Services/WarframeMarketApi.h>
#include <Services/RelicDatabase/RelicItemNameCleaner.h>
#include "RelicDatabasePrimeItemsFilter.h"

namespace ps
{
    class RelicDatabaseCreator
    {
    public:
        RelicDatabaseCreator(const std::string& lang, const std::string& platform);
        RelicItemsDatabase CreateItemsDatabaseUsingWfApi();
    private:
        WarframeMarketApi _api;
        RelicDatabaseJsonParser _parser;
        RelicDatabasePrimeItemsFilter _filter;
        RelicItemNameCleaner _cleaner;
    };
}



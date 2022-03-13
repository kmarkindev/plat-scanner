#include "RelicDatabasePrimeItemsFilter.h"

void ps::RelicDatabasePrimeItemsFilter::FilterDatabase(ps::RelicItemsDatabase& db)
{
    auto newEnd = std::remove_if(db.items.begin(), db.items.end(), [](const RelicItem& item) -> bool
    {
        return item.url_name.find("prime") == std::string::npos
            || item.url_name.find("primed") != std::string::npos;
    });

    db.items.erase(newEnd, db.items.end());
}

#include "RelicDatabasePrimeItemsFilter.h"

void ps::RelicDatabasePrimeItemsFilter::FilterDatabase(ps::RelicItemsDatabase& db)
{
    auto newEnd = std::remove_if(db.GetItems().begin(), db.GetItems().end(), [](const RelicItem& item) -> bool
    {
        auto urlName = item.GetUrlName();
        return urlName.find("prime") == std::string::npos
            || urlName.find("primed") != std::string::npos;
    });

    db.GetItems().erase(newEnd, db.GetItems().end());
}

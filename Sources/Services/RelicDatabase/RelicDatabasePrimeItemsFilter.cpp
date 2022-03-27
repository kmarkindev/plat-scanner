#include "RelicDatabasePrimeItemsFilter.h"

void ps::RelicDatabasePrimeItemsFilter::FilterDatabase(ps::RelicItemsDatabase& db)
{
    auto newEnd = std::remove_if(db.GetItems().begin(), db.GetItems().end(), [](const RelicItem& item) -> bool
    {
        auto urlName = item.GetUrlName();

        // get rid of all not primed items
        if(urlName.find("prime") == std::string::npos)
            return true;

        // get rid of prime sets
        if(urlName.find("prime_set") != std::string::npos)
            return true;

        // get rid of primed mods
        if(urlName.find("primed") != std::string::npos)
            return true;

        return false;
    });

    db.GetItems().erase(newEnd, db.GetItems().end());
}

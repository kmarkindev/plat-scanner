#include "RelicDatabaseSearcher.h"

ps::RelicDatabaseSearcher::RelicDatabaseSearcher(const ps::RelicItemsDatabase& db)
    : _db(db)
{

}

ps::RelicItem ps::RelicDatabaseSearcher::SearchForBestMatch(std::string itemName)
{
    const RelicItem* bestResult = nullptr;
    unsigned bestRatio = -1;

    for(const auto& item : _db.items)
    {
        auto ratio = fuzz::partial_ratio(itemName, item.name);

        if(ratio > bestRatio)
        {
            bestRatio = ratio;
            bestResult = &item;

            if(ratio > 99)
                break;
        }
    }

    return *bestResult;
}

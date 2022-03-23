#include "RelicDatabaseSearcher.h"

ps::RelicDatabaseSearcher::RelicDatabaseSearcher(const ps::RelicItemsDatabase& db)
    : _db(db)
{

}

std::pair<bool, ps::RelicItem> ps::RelicDatabaseSearcher::SearchForBestMatch(std::string itemName)
{
    std::vector<const RelicItem*> possibleResults;

    //itemName = _nameCleaner.ClearItemName(itemName);

    for(const auto& item : _db.GetItems())
    {
        auto ratio = 0.0; //rapidfuzz::fuzz::partial_ratio(itemName, item.cleanName);

        if(ratio > 70.0)
            possibleResults.push_back(&item);
    }

    if(possibleResults.empty())
        return {false, {}};

    double bestRatio = -1.0;
    const RelicItem* bestResult = nullptr;
    for(const auto& item : possibleResults)
    {
        auto ratio = 0.0; //rapidfuzz::fuzz::token_sort_ratio(itemName, item->cleanName);

        if(ratio > bestRatio)
        {
            bestRatio = ratio;
            bestResult = item;

            if(ratio > 99.0)
                break;
        }
    }

    return {true, *bestResult};
}

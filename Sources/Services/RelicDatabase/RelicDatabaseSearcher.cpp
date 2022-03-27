#include "RelicDatabaseSearcher.h"

#include <utility>
#include <regex>

ps::RelicDatabaseSearcher::RelicDatabaseSearcher(ps::RelicItemsDatabase  db)
    : _db(std::move(db))
{

}

std::pair<bool, ps::RelicItem> ps::RelicDatabaseSearcher::SearchForBestMatch(const std::string& itemName)
{
    auto u32name = toUtf32(itemName);

    double bestRatio = -1.0;
    const RelicItem* bestItem = nullptr;

    for(const auto& item : _db.GetItems())
    {
        auto u32dbName = toUtf32(item.GetName());
        auto prefix = U"";

        if(item.GetUrlName().find("_chassis") != std::string::npos)
            prefix = U"Чертёж: ";
        if(item.GetUrlName().find("_systems") != std::string::npos)
            prefix = U"Чертёж: ";
        if(item.GetUrlName().find("_neuroptics") != std::string::npos)
            prefix = U"Чертёж: ";

        auto ratio = rapidfuzz::fuzz::partial_ratio(prefix + u32dbName, u32name);

        if(ratio > 60.0 && ratio > bestRatio)
        {
            bestItem = &item;
            bestRatio = ratio;
        }
    }

    if(bestRatio < 0)
        return {false, {}};

    return {true, *bestItem};
}

std::u32string ps::RelicDatabaseSearcher::toUtf32(const std::string& s)
{
    //TODO: replace with smth that is not deprecated in cpp 20
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv;
    return conv.from_bytes(s);
}

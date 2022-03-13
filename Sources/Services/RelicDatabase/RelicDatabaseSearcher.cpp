#include "RelicDatabaseSearcher.h"

ps::RelicDatabaseSearcher::RelicDatabaseSearcher(const ps::RelicItemsDatabase& db)
    : _db(db)
{

}

ps::RelicItem ps::RelicDatabaseSearcher::SearchForBestMatch(std::string itemName)
{
    return {};
}

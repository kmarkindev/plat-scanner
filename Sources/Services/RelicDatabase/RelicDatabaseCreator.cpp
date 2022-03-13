#include "RelicDatabaseCreator.h"

ps::RelicDatabaseCreator::RelicDatabaseCreator(const std::string& lang, const std::string& platform)
    : _api(lang, platform)
{

}

ps::RelicItemsDatabase ps::RelicDatabaseCreator::CreateItemsDatabaseUsingWfApi()
{
    std::string apiResponse = _api.FetchAllTradeableItems();
    auto db = _parser.ParseFromString(apiResponse);
    _filter.FilterDatabase(db);
    return db;
}

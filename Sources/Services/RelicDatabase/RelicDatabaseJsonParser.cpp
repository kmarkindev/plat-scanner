#include "RelicDatabaseJsonParser.h"

ps::RelicItemsDatabase ps::RelicDatabaseJsonParser::ParseFromString(std::string jsonString)
{
    auto json = nlohmann::json::parse(jsonString)["payload"]["items"];

    std::vector<RelicItem> items(json.size());

    for(size_t i = 0; i < items.size(); ++i)
    {
        auto itemJson = json[i];
        items[i] = RelicItem(itemJson["item_name"], itemJson["url_name"]);
    }

    return RelicItemsDatabase(std::move(items));
}

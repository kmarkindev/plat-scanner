#include "RelicDatabaseJsonParser.h"

ps::RelicItemsDatabase ps::RelicDatabaseJsonParser::ParseFromString(std::string jsonString)
{
    auto json = nlohmann::json::parse(jsonString)["payload"]["items"];

    RelicItemsDatabase db = {
        std::vector<RelicItem>(json.size())
    };

    for(size_t i = 0; i < db.items.size(); ++i)
    {
        auto itemJson = json[i];
        db.items[i] = {
            itemJson["url_name"],
            itemJson["item_name"]
        };
    }

    return db;
}

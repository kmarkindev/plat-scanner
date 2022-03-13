#include "WarframeMarketApi.h"

ps::WarframeMarketApi::WarframeMarketApi(std::string_view lang, std::string_view platform)
    : _lang(lang), _platform(platform)
{

}

std::string ps::WarframeMarketApi::FetchAllTradeableItems()
{
    //TODO: replace it to http fetch

    std::ifstream fs("Tmp/db.json");

    fs.seekg(0, std::ios::end);
    size_t size = fs.tellg();
    std::string buffer(size, ' ');
    fs.seekg(0);
    fs.read(buffer.data(), size);

    return buffer;
}

std::string ps::WarframeMarketApi::FetchItemOrders(std::string itemUrl)
{
    //TODO:
    return {};
}

#include "WarframeMarketApi.h"

ps::WarframeMarketApi::WarframeMarketApi(std::string_view lang, std::string_view platform)
    : _lang(lang), _platform(platform), _httpRequest("GET", "api.warframe.market", "/")
{

}

std::string ps::WarframeMarketApi::FetchAllTradeableItems()
{
    HttpHeadersCollection headers;
    headers.SetHeader(HttpHeader("Language", _lang));
    headers.SetHeader(HttpHeader("accept", "application/json"));

    auto request = _httpRequest;
    request.SetHeaders(headers);
    request.SetPath("/v1/items");

    auto response = _httpClient.Send(request);

    if(response.GetCode() != 200)
        throw std::runtime_error("Cannot fetch items from v1/items WFM API. Returned code: "
            + std::to_string(response.GetCode()));

    return response.GetBody();
}

std::string ps::WarframeMarketApi::FetchItemOrders(std::string itemUrl)
{
    HttpHeadersCollection headers;
    headers.SetHeader(HttpHeader("Language", _lang));
    headers.SetHeader(HttpHeader("Platform", _platform));
    headers.SetHeader(HttpHeader("accept", "application/json"));

    auto request = _httpRequest;
    request.SetHeaders(headers);
    request.SetPath("/v1/items/" + itemUrl + "/orders");

    auto response = _httpClient.Send(request);

    if(response.GetCode() != 200)
        throw std::runtime_error("Cannot fetch item orders from v1/items"
            + itemUrl + " WFM API. Returned code: "
            + std::to_string(response.GetCode()));

    return response.GetBody();
}

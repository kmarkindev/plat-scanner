#pragma once

#include <string>
#include <Services/HttpClient.h>

namespace ps
{
    class WarframeMarketApi
    {
    public:
        WarframeMarketApi(std::string_view lang, std::string_view platform);
        std::string FetchAllTradeableItems();
        std::string FetchItemOrders(std::string itemUrl);
    private:
        std::string _lang;
        std::string _platform;
        HttpClient _httpClient;
        HttpRequest _httpRequest;
    };
}



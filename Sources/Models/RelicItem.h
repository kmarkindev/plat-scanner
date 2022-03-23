#pragma once

#include <string>
#include <stdexcept>

namespace ps
{
    class RelicItem
    {
    public:
        RelicItem();
        RelicItem(std::string name, std::string urlName);
        void SetItem(std::string name, std::string urlName);
        [[nodiscard]] std::string GetName() const;
        [[nodiscard]] std::string GetUrlName() const;
    private:
        std::string _urlName;
        std::string _name;

        void constexpr CheckName(std::string_view name);
    };
}
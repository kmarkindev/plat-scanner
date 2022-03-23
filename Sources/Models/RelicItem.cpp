#include "RelicItem.h"

ps::RelicItem::RelicItem(std::string name, std::string urlName)
{
    SetItem(std::move(name), std::move(urlName));
}

void ps::RelicItem::SetItem(std::string name, std::string urlName)
{
    CheckName(name);
    CheckName(urlName);

    _name = std::move(name);
    _urlName = std::move(urlName);
}

std::string ps::RelicItem::GetName() const
{
    return _name;
}

std::string ps::RelicItem::GetUrlName() const
{
    return _urlName;
}

constexpr void ps::RelicItem::CheckName(std::string_view name)
{
    if(name.empty())
        throw std::invalid_argument("Relic name or url_name can't be empty");
}

ps::RelicItem::RelicItem()
    : _name("No name"), _urlName("no_url_name")
{

}

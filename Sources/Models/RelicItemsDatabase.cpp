#include "RelicItemsDatabase.h"

ps::RelicItemsDatabase::RelicItemsDatabase()
{

}

ps::RelicItemsDatabase::RelicItemsDatabase(std::vector<RelicItem> items)
    : _items(std::move(items))
{

}

std::vector<ps::RelicItem>& ps::RelicItemsDatabase::GetItems()
{
    return _items;
}

const std::vector<ps::RelicItem>& ps::RelicItemsDatabase::GetItems() const
{
    return _items;
}

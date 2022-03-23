#pragma once

#include "RelicItem.h"
#include <vector>

namespace ps
{
    class RelicItemsDatabase
    {
    public:
        RelicItemsDatabase();
        explicit RelicItemsDatabase(std::vector<RelicItem> items);
        std::vector<RelicItem>& GetItems();
        const std::vector<RelicItem>& GetItems() const;

    private:
        std::vector<RelicItem> _items;
    };
}
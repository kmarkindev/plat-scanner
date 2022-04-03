#include "ItemOrder.h"

int ps::ItemOrder::GetCost() const
{
    return _cost;
}

void ps::ItemOrder::SetCost(int cost)
{
    if(cost <= 0)
        throw std::invalid_argument("Cost can't be less than or equal to 0");

    _cost = cost;
}

ps::ItemOrder::Status ps::ItemOrder::GetStatus() const
{
    return _status;
}

void ps::ItemOrder::SetStatus(ps::ItemOrder::Status status)
{
    _status = status;
}

ps::ItemOrder::ItemOrder(int cost,
    ps::ItemOrder::Status status,
    ps::ItemOrder::Type type,
    std::string region,
    bool visible)
{
    SetCost(cost);
    SetStatus(status);
    SetRegion(std::move(region));
    SetVisible(visible);
    SetType(type);
}

ps::ItemOrder::Type ps::ItemOrder::GetType() const
{
    return _type;
}

void ps::ItemOrder::SetType(ps::ItemOrder::Type type)
{
    _type = type;
}

const std::string& ps::ItemOrder::GetRegion() const
{
    return _region;
}

void ps::ItemOrder::SetRegion(std::string region)
{
    _region = std::move(region);
}

bool ps::ItemOrder::IsVisible() const
{
    return _visible;
}

void ps::ItemOrder::SetVisible(bool visible)
{
    _visible = visible;
}

ps::ItemOrder::Type ps::ItemOrder::TypeFromString(std::string_view type)
{
    if(type == "sell")
        return ps::ItemOrder::Type::Sell;
    else if(type == "buy")
        return ps::ItemOrder::Type::Buy;
    else
        throw std::invalid_argument("Can't convert given str");
}

ps::ItemOrder::Status ps::ItemOrder::StatusFromString(std::string_view status)
{
    if(status == "offline")
        return ps::ItemOrder::Status::Offline;
    else if(status == "ingame")
        return ps::ItemOrder::Status::InGame;
    else if(status == "online")
        return ps::ItemOrder::Status::Online;
    else
        throw std::invalid_argument("Can't convert given str");
}

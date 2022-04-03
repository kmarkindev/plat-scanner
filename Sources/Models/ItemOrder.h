#pragma once

#include <stdexcept>

namespace ps
{
    class ItemOrder
    {
    public:

        enum class Status
        {
            Offline = 0,
            Online,
            InGame
        };

        enum class Type
        {
            Sell = 0,
            Buy
        };

        static Type TypeFromString(std::string_view type);
        static Status StatusFromString(std::string_view status);

        ItemOrder(int cost, Status status, Type type, std::string region, bool visible);

        [[nodiscard]] int GetCost() const;
        void SetCost(int cost);
        [[nodiscard]] Status GetStatus() const;
        void SetStatus(Status status);
        [[nodiscard]] Type GetType() const;
        void SetType(Type type);
        [[nodiscard]] const std::string& GetRegion() const;
        void SetRegion(std::string region);
        [[nodiscard]] bool IsVisible() const;
        void SetVisible(bool visible);

    private:
        int _cost;
        Status _status;
        Type _type;
        std::string _region;
        bool _visible;
    };
}
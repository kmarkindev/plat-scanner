#pragma once

#include <string>
#include <wx/wx.h>
#include <array>

namespace ps
{
    class RelicItemNameCleaner
    {
    public:
        std::string ClearItemName(std::string str);
    private:
        void RemovePunct(std::string& str);
        void ToLower(std::string& str);
    };
}



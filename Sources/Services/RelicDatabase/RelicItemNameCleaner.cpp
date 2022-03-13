#include "RelicItemNameCleaner.h"

std::string ps::RelicItemNameCleaner::ClearItemName(std::string str)
{
    RemovePunct(str);
    ToLower(str);
    return str;
}

void ps::RelicItemNameCleaner::RemovePunct(std::string& str)
{
    wxString toRemove = wxString::FromUTF8(":.'!()-+=_!@#$%^&*`~?<>/\\");
    wxString wxStr = wxString::FromUTF8(str);

    for(auto ch : toRemove)
        wxStr.Replace(ch, "");

    str = wxStr.utf8_string();
}

void ps::RelicItemNameCleaner::ToLower(std::string& str)
{
    wxString wxStr = wxString::FromUTF8(str);
    str = wxStr.MakeLower().utf8_string();
}

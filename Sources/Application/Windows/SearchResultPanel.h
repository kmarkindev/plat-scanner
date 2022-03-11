#pragma once

#include <wx/wx.h>
#include <Dto/SearchResult.h>

namespace ps
{
    class SearchResultPanel : public wxPanel
    {
    public:
        explicit SearchResultPanel(wxWindow* parent);
        void SetResult(SearchResult result);
    };
}



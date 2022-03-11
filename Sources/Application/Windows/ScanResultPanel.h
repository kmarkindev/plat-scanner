#pragma once

#include <wx/wx.h>
#include <Dto/Image.h>

namespace ps
{
    class ScanResultPanel : public wxPanel
    {
    public:
        explicit ScanResultPanel(wxWindow* parent);
        void SetResult(Image image, wxString text);
    };
}




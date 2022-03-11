#pragma once

#include <wx/wx.h>

namespace ps
{
    class HotkeyStatusPanel : public wxPanel
    {
    public:
        explicit HotkeyStatusPanel(wxWindow* parent);
        void SetStatus(bool isActive);
    };
}




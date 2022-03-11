#pragma once

#include <wx/wx.h>

namespace ps
{
    class OptionsPanel : public wxPanel
    {
    public:
        explicit OptionsPanel(wxWindow* parent);
        bool IsDebugDataSavingEnabled();
        bool IsMoveOnTopEnabled();
    };
}



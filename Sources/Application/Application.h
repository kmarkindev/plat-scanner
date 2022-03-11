#pragma once

#include <wx/wx.h>
#include <Application/Windows/MainWindow.h>

namespace ps
{
    class Application : public wxApp
    {
    protected:
        bool OnInit() override;
    };
}
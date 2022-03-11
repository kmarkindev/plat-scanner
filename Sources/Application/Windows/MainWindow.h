#pragma once

#include <wx/wx.h>
#include <Application/Windows/ScanResultPanel.h>
#include <Application/Windows/SearchResultPanel.h>
#include <Application/Windows/HotkeyStatusPanel.h>
#include <Application/Windows/OptionsPanel.h>
#include <Services/RelicScanner.h>
#include <Services/ImageWriter.h>
#include <array>
#include <cstdlib>
#include <sstream>

namespace ps
{
    class MainWindow : public wxFrame
    {
    public:
        explicit MainWindow();
    private:
        HotkeyStatusPanel* _hotkeyStatusPanel;
        std::array<ScanResultPanel*, 4> _scanResultPanels;
        std::array<SearchResultPanel*, 4> _searchResultPanels;
        OptionsPanel* _optionsPanel;

        RelicScanner _relicScanner;

        void SetupLayout();
        void RegisterHotkeys();

        void HotkeyHandler(wxKeyEvent& event);
    };
}



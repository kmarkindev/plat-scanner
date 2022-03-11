#pragma once

#include <wx/wx.h>
#include <Application/Windows/ScanResultPanel.h>
#include <Application/Windows/SearchResultPanel.h>
#include <Application/Windows/HotkeyStatusPanel.h>
#include <Application/Windows/OptionsPanel.h>
#include <Services/ScreenshotTaker.h>
#include <Services/ImageScanner.h>
#include <Services/RelicPartPositionsFinder.h>
#include <Services/ImageWriter.h>
#include <Services/ImageProcessors/GrayscaleProcessor.h>
#include <Services/ImageProcessors/SharpenProcessor.h>
#include <Services/ImageProcessors/UpscaleProcessor.h>
#include <array>

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

        void SetupLayout();
        void RegisterHotkeys();

        void HotkeyHandler(wxKeyEvent& event);
    };
}



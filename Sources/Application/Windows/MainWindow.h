#pragma once

#include <wx/wx.h>
#include <Application/Windows/ScanResultPanel.h>
#include <Application/Windows/SearchResultPanel.h>
#include <Application/Windows/HotkeyStatusPanel.h>
#include <Services/RelicDatabase/RelicDatabaseSearcher.h>
#include <Services/WarframeMarketApi.h>
#include <Application/Windows/OptionsPanel.h>
#include <Services/RelicScanner.h>
#include <Dto/SearchResult.h>
#include <Services/ImageWriter.h>
#include <Services/ItemOrdersJsonParser.h>
#include <Services/ItemOrdersFilter.h>
#include <Services/BestPricesFinder.h>
#include <array>
#include <cstdlib>
#include <sstream>

namespace ps
{
    class MainWindow : public wxFrame
    {
    public:
        explicit MainWindow(const RelicItemsDatabase& db);
    private:
        HotkeyStatusPanel* _hotkeyStatusPanel;
        std::array<ScanResultPanel*, 4> _scanResultPanels;
        std::array<SearchResultPanel*, 4> _searchResultPanels;
        OptionsPanel* _optionsPanel;

        RelicScanner _relicScanner;
        RelicDatabaseSearcher _relicSearcher;
        WarframeMarketApi _wmApi;
        ItemOrdersJsonParser _ordersJsonParser;
        ItemOrdersFilter _ordersFilter;
        BestPricesFinder _bestPricesFinder;

        void SetupLayout();
        void RegisterHotkeys();

        void HotkeyHandler(wxKeyEvent& event);
        void MoveOnTop();
    };
}



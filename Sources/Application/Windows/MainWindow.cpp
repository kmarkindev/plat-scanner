#include "MainWindow.h"

ps::MainWindow::MainWindow(const RelicItemsDatabase& db)
    : wxFrame(nullptr, wxID_ANY, "Platimun Scanner | powered by kmarkindev", wxDefaultPosition, wxDefaultSize,
    wxSYSTEM_MENU | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxRESIZE_BORDER | wxCLOSE_BOX | wxCAPTION | wxCLIP_CHILDREN),
    _relicScanner("ru"), _wmApi("ru", "pc"), _relicSearcher(db)
{
    SetupLayout();
    RegisterHotkeys();
}

void ps::MainWindow::SetupLayout()
{
    auto topSizer = new wxBoxSizer(wxVERTICAL);
    auto resultsSizer = new wxBoxSizer(wxHORIZONTAL);

    _hotkeyStatusPanel = new HotkeyStatusPanel(this);
    _optionsPanel = new OptionsPanel(this);

    for(int i = 0; i < 4; ++i)
    {
        auto panel = new wxPanel(this, wxID_ANY);
        panel->SetBackgroundColour(wxColour(200, 200, 200));
        panel->SetSize(wxSize(350, 600));
        resultsSizer->Add(panel, 1, wxSHAPED | wxALIGN_CENTRE | wxLEFT | wxRIGHT, 5);

        _scanResultPanels[i] = new ScanResultPanel(panel);
        _searchResultPanels[i] = new SearchResultPanel(panel);

        auto sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(_scanResultPanels[i], 3, wxEXPAND);
        sizer->Add(_searchResultPanels[i], 5, wxEXPAND);
        panel->SetSizerAndFit(sizer);
    }

    topSizer->Add(_hotkeyStatusPanel, 1, wxEXPAND | wxFIXED_MINSIZE);
    topSizer->Add(resultsSizer, 10, wxEXPAND | wxTOP | wxBOTTOM, 5);
    topSizer->Add(_optionsPanel, 1, wxEXPAND | wxFIXED_MINSIZE);

    topSizer->SetMinSize(wxSize(900, 480));
    SetSizerAndFit(topSizer);
}

void ps::MainWindow::RegisterHotkeys()
{
    //TODO: allow to change hotkeys
    // Make sure that we have registered all needed hotkeys
    if(!RegisterHotKey(4, wxMOD_CONTROL, static_cast<unsigned>('0')))
    {
        _hotkeyStatusPanel->SetStatus(false);
        return;
    }
    if(!RegisterHotKey(3, wxMOD_CONTROL, static_cast<unsigned>('9')))
    {
        _hotkeyStatusPanel->SetStatus(false);
        UnregisterHotKey(4);
        return;
    }
    if(!RegisterHotKey(2, wxMOD_CONTROL, static_cast<unsigned>('8')))
    {
        _hotkeyStatusPanel->SetStatus(false);
        UnregisterHotKey(4);
        UnregisterHotKey(3);
        return;
    }

    Bind(wxEVT_HOTKEY, &MainWindow::HotkeyHandler, this, 4);
    Bind(wxEVT_HOTKEY, &MainWindow::HotkeyHandler, this, 3);
    Bind(wxEVT_HOTKEY, &MainWindow::HotkeyHandler, this, 2);

    _hotkeyStatusPanel->SetStatus(true);
}

void ps::MainWindow::HotkeyHandler(wxKeyEvent& event)
{
    auto itemsCount = event.GetId();

    // Reset previous results
    for(auto panel : _scanResultPanels)
        panel->ResetResult();

    // Scan dropped items from screen
    // TODO: grab resolution and aspect ratio from settings
    auto scanResult = _relicScanner.ScanRelics(itemsCount, {1920, 1080}, {16, 9});

    // Set scanned image and name in UI
    for(int i = 0; i < scanResult.items.size(); ++i)
        _scanResultPanels[i]->SetResult(scanResult.items[i].scannedImage,
            wxString::FromUTF8(scanResult.items[i].scannedText));

    // Search for best matches in database
    std::vector<std::pair<bool, SearchResult>> searchResults(itemsCount);
    for(size_t i = 0; i < scanResult.items.size(); ++i)
    {
        auto result = _relicSearcher.SearchForBestMatch(scanResult.items[i].scannedText);
        searchResults[i].first = result.first;
        searchResults[i].second.item = result.second;
    }

    // Fetch prices from warframe.market
    for(auto& result : searchResults)
    {
        if(!result.first)
            continue;

        auto ordersJson = _wmApi.FetchItemOrders(result.second.item.GetUrlName());
        auto itemOrders = _ordersJsonParser.ParseFromString(ordersJson);
        _ordersFilter.FilterOrders(itemOrders);
        result.second.bestPrices = _bestPricesFinder.SearchBestPrices(itemOrders);
    }

    //Show results in UI

    // Move window on top if required
    if(_optionsPanel->IsMoveOnTopEnabled())
    {
        Iconize(false);
        SetFocus();
        Raise();
        Show(true);
    }

    // Save debug information if required
    if(_optionsPanel->IsDebugDataSavingEnabled())
    {
        ps::ImageWriter imgWriter;

        int i = 0;

        wxFileName path(wxStandardPaths::Get().GetExecutablePath());
        path.AppendDir("tmp");
        path.AppendDir("debug");

        for(auto [scannedImage, processedImage, scannedText] : scanResult.items)
        {
            // need to minus i because time(nullptr) returns same values from time to time
            auto id = std::to_string(time(nullptr) - i++);

            auto currentPath = path;
            currentPath.AppendDir(id);
            currentPath.Mkdir(wxS_DIR_DEFAULT, wxPATH_MKDIR_FULL);

            currentPath.SetFullName("scanned_image.png");
            auto p = currentPath.GetFullPath().ToStdString();
            imgWriter.WriteToDisk(currentPath.GetFullPath().ToStdString(), scannedImage);
            currentPath.SetFullName("processed_image.png");
            imgWriter.WriteToDisk(currentPath.GetFullPath().ToStdString(), processedImage);
        }
    }
}

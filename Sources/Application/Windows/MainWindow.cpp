#include "MainWindow.h"

ps::MainWindow::MainWindow()
    : wxFrame(nullptr, wxID_ANY, "Platimun Scanner | powered by kmarkindev", wxDefaultPosition, wxDefaultSize,
    wxSYSTEM_MENU | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxRESIZE_BORDER | wxCLOSE_BOX | wxCAPTION | wxCLIP_CHILDREN),
    _relicScanner("rus")
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

    //TODO: grab resolution and aspect ratio from settings
    auto result = _relicScanner.ScanRelics(itemsCount, {1920, 1080}, {16, 9});

    if(_optionsPanel->IsMoveOnTopEnabled())
    {
        Iconize(false);
        SetFocus();
        Raise();
        Show(true);
    }

    for(auto panel : _scanResultPanels)
        panel->ResetResult();

    for(int i = 0; i < result.items.size(); ++i)
        _scanResultPanels[i]->SetResult(result.items[i].scannedImage, wxString::FromUTF8(result.items[i].scannedText));

    //TODO: find items ids, fetch prices, show them in ui.

    if(_optionsPanel->IsDebugDataSavingEnabled())
    {
        //TODO:

        ps::ImageWriter imgWriter;

        int i = 0;

        wxFileName path(wxStandardPaths::Get().GetExecutablePath());
        path.AppendDir("Tmp");
        path.AppendDir("Debug");

        for(auto [scannedImage, processedImage, scannedText] : result.items)
        {
            // need to minus i because time(nullptr) returns same values from time to time
            auto id = std::to_string(time(nullptr) - i++);

            auto currentPath = path;
            currentPath.AppendDir(id);
            currentPath.Mkdir(wxS_DIR_DEFAULT, wxPATH_MKDIR_FULL);

            currentPath.SetFullName("scannedImage.png");
            auto p = currentPath.GetFullPath().ToStdString();
            imgWriter.WriteToDisk(currentPath.GetFullPath().ToStdString(), scannedImage);
            currentPath.SetFullName("processedImage.png");
            imgWriter.WriteToDisk(currentPath.GetFullPath().ToStdString(), processedImage);
        }
    }
}

#include "MainWindow.h"

ps::MainWindow::MainWindow()
    : wxFrame(nullptr, wxID_ANY, "Platimun Scanner | powered by kmarkindev", wxDefaultPosition, wxSize(848, 480),
    wxSYSTEM_MENU | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxRESIZE_BORDER | wxCLOSE_BOX | wxCAPTION | wxCLIP_CHILDREN)
{
    SetupLayout();
    RegisterHotkeys();
}

void ps::MainWindow::SetupLayout()
{
    auto topSizer = new wxBoxSizer(wxVERTICAL);
    auto resultsSizer = new wxBoxSizer(wxHORIZONTAL);

    _hotkeyStatusPanel = new HotkeyStatusPanel(this);
    _hotkeyStatusPanel->SetBackgroundColour(wxColour(52, 124, 251));
    _optionsPanel = new OptionsPanel(this);

    for(int i = 0; i < 4; ++i)
    {
        auto panel = new wxPanel(this, wxID_ANY);
        panel->SetBackgroundColour(wxColour(35 * i, 72, 132));
        panel->SetSize(wxSize(350, 600));
        resultsSizer->Add(panel, 1, wxSHAPED | wxALIGN_CENTRE | wxFIXED_MINSIZE);

        _scanResultPanels[i] = new ScanResultPanel(panel);
        _scanResultPanels[i]->SetBackgroundColour(wxColour(35 * i, 10 * i, 132));
        _searchResultPanels[i] = new SearchResultPanel(panel);
        _searchResultPanels[i]->SetBackgroundColour(wxColour(87, 35 * i, 20 * i));

        auto sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(_scanResultPanels[i], 3, wxEXPAND);
        sizer->Add(_searchResultPanels[i], 5, wxEXPAND);
        panel->SetSizerAndFit(sizer);
    }

    topSizer->Add(_hotkeyStatusPanel, 1, wxEXPAND | wxFIXED_MINSIZE);
    topSizer->Add(resultsSizer, 10, wxEXPAND);
    topSizer->Add(_optionsPanel, 1, wxEXPAND | wxFIXED_MINSIZE);

    SetSizerAndFit(topSizer);
}

void ps::MainWindow::RegisterHotkeys()
{
    // Make sure that we have registered all needed hotkeys
    if(!RegisterHotKey(4, wxMOD_CONTROL, 0x38))
    {
        _hotkeyStatusPanel->SetStatus(false);
        return;
    }
    if(!RegisterHotKey(3, wxMOD_CONTROL, 0x39))
    {
        _hotkeyStatusPanel->SetStatus(false);
        UnregisterHotKey(4);
        return;
    }
    if(!RegisterHotKey(2, wxMOD_CONTROL, 0x30))
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

    ps::ImageScanner api("rus");

    ps::RelicPartPositionsFinder positionsFinder;
    auto rect = positionsFinder.GetPartPosition(0, {
        itemsCount,
        {1920, 1080},
        {16, 9}
    });

    ps::ScreenshotTaker screenshotTaker;
    ps::Image img = screenshotTaker.TakeScreenRect(rect);

    ps::GrayscaleProcessor grayscaleProcessor;
    grayscaleProcessor.Process(img);

    ps::UpscaleProcessor upscaleProcessor(2.0);
    upscaleProcessor.Process(img);

    ps::SharpenProcessor sharpenProcessor(1.25);
    sharpenProcessor.Process(img);

    if(_optionsPanel->IsMoveOnTopEnabled())
    {
        Iconize(false);
        SetFocus();
        Raise();
        Show(true);
    }

    auto result = api.Scan(img);
    //wxMessageBox(wxString::FromUTF8(result));

    if(_optionsPanel->IsDebugDataSavingEnabled())
    {
        ps::ImageWriter imgWriter;
        imgWriter.WriteToDisk("output.png", img);
    }
}

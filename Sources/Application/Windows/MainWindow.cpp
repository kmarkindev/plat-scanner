#include "MainWindow.h"

ps::MainWindow::MainWindow()
    : wxFrame(nullptr, wxID_ANY, "Platimun Scanner | powered by kmarkindev", wxDefaultPosition, wxSize(848, 480),
    wxSYSTEM_MENU | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxRESIZE_BORDER | wxCLOSE_BOX | wxCAPTION | wxCLIP_CHILDREN)
{
    SetupLayout();
}

void ps::MainWindow::SetupLayout()
{
    auto topSizer = new wxBoxSizer(wxVERTICAL);
    auto resultsSizer = new wxBoxSizer(wxHORIZONTAL);

    _hotkeyStatusPanel = new HotkeyStatusPanel(this);
    _hotkeyStatusPanel->SetBackgroundColour(wxColour(52, 124, 251));
    _optionsPanel = new OptionsPanel(this);
    _optionsPanel->SetBackgroundColour(wxColour(65, 125, 24));

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

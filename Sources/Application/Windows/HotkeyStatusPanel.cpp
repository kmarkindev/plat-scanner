#include "HotkeyStatusPanel.h"

void ps::HotkeyStatusPanel::SetStatus(bool isActive)
{
    if(isActive)
        _staticText->SetLabel(wxT("Press CTRL + 0 to scan 4 items, CTRL + 9 to scan 3 items "
            "and CTRL + 8 to scan 2 items."));
    else
        _staticText->SetLabel(
            wxT("There is an application on your PC, that has already used needed hotkeys. "
                "This application will not work."));
}

ps::HotkeyStatusPanel::HotkeyStatusPanel(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    SetSize(wxSize(500, 25));

    _staticText = new wxStaticText(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);

    auto font = _staticText->GetFont();
    font.SetPointSize(10);
    font.SetWeight(wxFONTWEIGHT_BOLD);
    _staticText->SetFont(font);

    auto sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(_staticText, 1, wxEXPAND);
    SetSizerAndFit(sizer);
}

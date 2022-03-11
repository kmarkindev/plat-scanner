#include "ScanResultPanel.h"

void ps::ScanResultPanel::SetResult(ps::Image image, wxString text)
{
    //TODO: show result in ui
    wxMessageBox(wxString::FromUTF8(text));
}

ps::ScanResultPanel::ScanResultPanel(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    SetSize(wxSize(250, 150));
}

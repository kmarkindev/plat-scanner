#include "ScanResultPanel.h"

void ps::ScanResultPanel::SetResult(ps::Image image, wxString text)
{

}

ps::ScanResultPanel::ScanResultPanel(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    SetSize(wxSize(250, 150));
}

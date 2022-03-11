#include "HotkeyStatusPanel.h"

void ps::HotkeyStatusPanel::SetStatus(bool isActive)
{

}

ps::HotkeyStatusPanel::HotkeyStatusPanel(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    SetSize(wxSize(500, 25));
}

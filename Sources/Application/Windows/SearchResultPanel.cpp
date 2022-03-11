#include "SearchResultPanel.h"

void ps::SearchResultPanel::SetResult(ps::SearchResult result)
{

}

ps::SearchResultPanel::SearchResultPanel(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    SetSize(wxSize(250, 200));
}

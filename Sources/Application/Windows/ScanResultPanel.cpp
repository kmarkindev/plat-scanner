#include "ScanResultPanel.h"

void ps::ScanResultPanel::SetResult(ps::Image image, wxString text)
{
    if(image.channels != 3)
        throw std::invalid_argument("Cannot show image without RGB channels");

    wxImage wximg(image.width, image.height, image.bitmap.data(), true);

    text.Replace('\n', " ");

    _resultText->SetLabel(text);
    _resultImage->SetBitmap(wxBitmap(wximg));

    Layout();
}

ps::ScanResultPanel::ScanResultPanel(wxWindow* parent)
    : wxPanel(parent, wxID_ANY), _noImageBitmap(new wxBitmap())
{
    SetSize(wxSize(250, 150));

    wxFileName path(wxStandardPaths::Get().GetExecutablePath());
    path.AppendDir("Data");
    path.AppendDir("Media");
    path.SetFullName("noimage.png");

    _noImageBitmap->LoadFile(path.GetFullPath(), wxBITMAP_TYPE_PNG);

    _resultImage = new wxStaticBitmap(this, wxID_ANY, *_noImageBitmap);
    _resultImage->SetBackgroundColour(wxColour(220, 220, 220));
    _resultImage->SetMinSize(wxSize(60, 20));
    _resultText = new wxStaticText(this, wxID_ANY, wxT("No result"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
    auto font = _resultText->GetFont();
    font.SetPointSize(10);
    _resultText->SetFont(font);

    auto sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(_resultImage, 3, wxEXPAND);
    sizer->Add(_resultText, 2, wxEXPAND | wxTOP, 10);
    SetSizerAndFit(sizer);
}

void ps::ScanResultPanel::ResetResult()
{
    _resultImage->SetBitmap(*_noImageBitmap);
    _resultText->SetLabel(wxT("No result"));

    Layout();
}

#include "OptionsPanel.h"

ps::OptionsPanel::OptionsPanel(wxWindow* parent)
    : wxPanel(parent, wxID_ANY)
{
    SetSize(wxSize(500, 25));

    _shouldSaveDebugInfoCheckbox = new wxCheckBox(this, wxID_ANY, wxString::FromUTF8("Save debug information"));
    _shouldMoveOnTopCheckbox = new wxCheckBox(this, wxID_ANY, wxString::FromUTF8("Show on top when results are ready"));

    _shouldSaveDebugInfoCheckbox->SetValue(true);
    _shouldMoveOnTopCheckbox->SetValue(true);

    auto sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(_shouldMoveOnTopCheckbox, 0, wxALIGN_CENTER | wxALL, 10);
    sizer->Add(_shouldSaveDebugInfoCheckbox, 0, wxALIGN_CENTER | wxALL, 10);
    SetSizerAndFit(sizer);
}

bool ps::OptionsPanel::IsDebugDataSavingEnabled()
{
    return _shouldSaveDebugInfoCheckbox->GetValue();
}

bool ps::OptionsPanel::IsMoveOnTopEnabled()
{
    return _shouldMoveOnTopCheckbox->GetValue();
}

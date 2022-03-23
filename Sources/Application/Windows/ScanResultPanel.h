#pragma once

#include <wx/wx.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <Models/Image.h>

namespace ps
{
    class ScanResultPanel : public wxPanel
    {
    public:
        explicit ScanResultPanel(wxWindow* parent);
        void SetResult(Image image, wxString text);
        void ResetResult();
    private:
        wxStaticBitmap* _resultImage;
        wxStaticText* _resultText;
        wxBitmap* _noImageBitmap;
    };
}




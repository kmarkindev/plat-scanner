#pragma once

#include <wx/wx.h>
#include <Dto/Image.h>
#include <vector>

namespace ps
{
    class ScreenshotTaker
    {
    public:
        Image TakeWholeScreen() const;
    };
}



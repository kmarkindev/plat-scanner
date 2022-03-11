#pragma once

#include <wx/wx.h>
#include <Dto/Image.h>
#include <vector>
#include <glm/glm.hpp>
#include <stdexcept>

namespace ps
{
    class ScreenshotTaker
    {
    public:
        Image TakeWholeScreen() const;
        Image TakeScreenRect(glm::ivec4 rect) const;
    };
}



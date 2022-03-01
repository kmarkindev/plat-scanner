#pragma once

#include <Rect.h>

namespace ps
{
    class OptionPositionFinder
    {
    public:
        [[nodiscard]] Rect GetRectangleOf(int index) const;
    };
}




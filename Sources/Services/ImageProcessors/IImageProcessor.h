#pragma once

#include <Models/Image.h>

namespace ps
{
    class IImageProcessor
    {
    public:
        virtual void Process(Image& image) const = 0;
    };
}
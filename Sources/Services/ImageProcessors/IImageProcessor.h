#pragma once

#include <Dto/Image.h>

namespace ps
{
    class IImageProcessor
    {
    public:
        virtual void Process(Image& image) const = 0;
    };
}
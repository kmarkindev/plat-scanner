#pragma once

#include "IImageProcessor.h"
#include <stdexcept>

namespace ps
{
    class GrayscaleProcessor : public IImageProcessor
    {
    public:
        void Process(Image& image) override;
    };
}




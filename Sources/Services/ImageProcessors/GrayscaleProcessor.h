#pragma once

#include "IImageProcessor.h"

namespace ps
{
    class GrayscaleProcessor : public IImageProcessor
    {
    public:
        void Process(Image& image) override;
    };
}




#pragma once

#include "IImageProcessor.h"
#include <stdexcept>
#include <stb_image_resize.h>

namespace ps
{
    class UpscaleProcessor : public IImageProcessor
    {
    public:
        explicit UpscaleProcessor(double upscaleMultiplier);
        void Process(Image& image) const override;
    private:
        double _upscaleMultiplier;
    };
}
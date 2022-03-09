#pragma once

#include "IImageProcessor.h"

namespace ps
{
    class UpscaleProcessor : public IImageProcessor
    {
    public:
        UpscaleProcessor(double upscaleMultiplier);
        void Process(Image& image) override;
    private:
        double _upscaleMultiplier;
    };
}
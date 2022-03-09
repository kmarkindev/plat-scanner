#pragma once

#include "IImageProcessor.h"

namespace ps
{
    class UpscaleProcessor : public IImageProcessor
    {
    public:
        explicit UpscaleProcessor(double upscaleMultiplier);
        void Process(Image& image) override;
    private:
        double _upscaleMultiplier;
    };
}
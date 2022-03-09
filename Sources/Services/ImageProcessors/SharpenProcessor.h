#pragma once

#include "IImageProcessor.h"
#include <stdexcept>

namespace ps
{
    class SharpenProcessor : public IImageProcessor
    {
    public:
        explicit SharpenProcessor(double sharpenMultiplier);
        void Process(Image& image) const override;
    private:
        double _sharpenMultiplier;
    };
}




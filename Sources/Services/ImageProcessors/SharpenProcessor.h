#pragma once

#include "IImageProcessor.h"
#include <stdexcept>
#include <glm/glm.hpp>
#include "KernelProcessor.h"

namespace ps
{
    class SharpenProcessor : public IImageProcessor
    {
    public:
        explicit SharpenProcessor(float sharpenMultiplier);
        void Process(Image& image) const override;
    private:
        float _sharpenMultiplier;
    };
}




#include "SharpenProcessor.h"

ps::SharpenProcessor::SharpenProcessor(float sharpenMultiplier)
    : _sharpenMultiplier(sharpenMultiplier)
{
    if(_sharpenMultiplier < 0.0 || _sharpenMultiplier > 100.0)
        throw std::invalid_argument("Multiplier can't be less than 0.0 and more than 100.0");
}

void ps::SharpenProcessor::Process(ps::Image& image) const
{
    // https://www.taylorpetrick.com/blog/post/convolution-part3#sharpen

    constexpr glm::mat3 first = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    constexpr glm::mat3 second = {
        {0, -1, 0},
        {-1, 4, -1},
        {0, -1, 0}
    };
    glm::mat3 kernel = first + second * _sharpenMultiplier;

    auto processor = ps::KernelProcessor<glm::mat3>(kernel);
    processor.Process(image);
}

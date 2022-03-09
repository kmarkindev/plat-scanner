#include "UpscaleProcessor.h"

ps::UpscaleProcessor::UpscaleProcessor(double upscaleMultiplier)
    : _upscaleMultiplier(upscaleMultiplier)
{
    if(upscaleMultiplier <= 0.0 || upscaleMultiplier > 1000.0)
        throw std::invalid_argument("Multiplier cannot be less than or eq to 0.0 or more than 1000.0");
}

void ps::UpscaleProcessor::Process(ps::Image& image)
{
    int newWidth = image.width * static_cast<int>(_upscaleMultiplier);
    int newHeight = image.height * static_cast<int>(_upscaleMultiplier);
    std::vector<unsigned char> newBitmap(newWidth * newHeight * image.channels);

    stbir_resize_uint8(image.bitmap.data(), image.width, image.height, image.width * image.channels,
        newBitmap.data(), newWidth, newHeight, newWidth * image.channels, image.channels);

    image.bitmap = newBitmap;
    image.width = newWidth;
    image.height = newHeight;
}

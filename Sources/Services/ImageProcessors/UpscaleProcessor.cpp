#include "UpscaleProcessor.h"

ps::UpscaleProcessor::UpscaleProcessor(double upscaleMultiplier)
    : _upscaleMultiplier(upscaleMultiplier)
{
    if(_upscaleMultiplier <= 0.0 || _upscaleMultiplier > 1000.0)
        throw std::invalid_argument("Multiplier can't be less than or equal to 0.0 or more than 1000.0");
}

void ps::UpscaleProcessor::Process(ps::Image& image) const
{
    const int w = image.GetWidth();
    const int h = image.GetHeight();
    const int c = image.GetChannels();

    int newWidth = w * static_cast<int>(_upscaleMultiplier);
    int newHeight = h * static_cast<int>(_upscaleMultiplier);
    std::vector<unsigned char> newBitmap(newWidth * newHeight * c);

    stbir_resize_uint8(image.GetBitmapRef().data(), w, h, w * c,
        newBitmap.data(), newWidth, newHeight, newWidth * c, c);

    image.SetImage(newWidth, newHeight, c, std::move(newBitmap));
}

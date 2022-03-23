#include "GrayscaleProcessor.h"

void ps::GrayscaleProcessor::Process(ps::Image& image) const
{
    if(image.GetChannels() != 3)
        throw std::runtime_error("Cannot grayscale non RGB image");

    const int w = image.GetWidth();
    const int h = image.GetHeight();
    const int c = image.GetChannels();

    std::vector<unsigned char> newBitmap(w * h);

    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            int x = i * w * c;
            int y = j * c;
            int index = x + y;

            double result = image.GetBitmapRef()[index] * 0.2989
                + image.GetBitmapRef()[index + 1] * 0.5870
                + image.GetBitmapRef()[index + 2] * 0.1140;

            //result is always in range from 0 to 255
            newBitmap[(i * w) + j] = static_cast<unsigned char>(result);
        }
    }

    image.SetImage(w, h, 1, std::move(newBitmap));
}

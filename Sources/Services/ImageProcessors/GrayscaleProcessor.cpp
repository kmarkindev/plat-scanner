#include "GrayscaleProcessor.h"

void ps::GrayscaleProcessor::Process(ps::Image& image)
{
    if(image.channels != 3)
        throw std::runtime_error("Cannot grayscale non RGB image");

    std::vector<unsigned char> newBitmap(image.width * image.height);

    for(int i = 0; i < image.height; ++i)
    {
        for(int j = 0; j < image.width; ++j)
        {
            int x = i * image.width * image.channels;
            int y = j * image.channels;
            int index = x + y;

            double result = image.bitmap[index] * 0.2989
                + image.bitmap[index + 1] * 0.5870
                + image.bitmap[index + 2] * 0.1140;

            //result is always in range from 0 to 255
            newBitmap[(i * image.width) + j] = static_cast<unsigned char>(result);
        }
    }

    image.channels = 1;
    image.bitmap = newBitmap;
}

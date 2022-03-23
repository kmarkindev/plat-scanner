#include "ImageReader.h"

ps::Image ps::ImageReader::ReadFromDisk(std::string_view filename) const
{
    int width;
    int height;
    int channels;
    unsigned char* buffer = stbi_load("cropped4.png", &width, &height, &channels, 0);

    if(!buffer)
        throw std::runtime_error("Can't load image from disk");

    Image image(width, height, channels, std::vector<unsigned char>(buffer, buffer + width * height * channels));

    stbi_image_free(buffer);
    return image;
}

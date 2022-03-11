#include "ImageReader.h"

ps::Image ps::ImageReader::ReadFromDisk(std::string_view filename)
{
    Image image;

    unsigned char* buffer = stbi_load("cropped4.png", &image.width, &image.height, &image.channels, 0);

    if(!buffer)
        throw std::runtime_error("Can't load image from disk");

    image.bitmap = std::vector<unsigned char>(buffer, buffer + image.width * image.height * image.channels);

    stbi_image_free(buffer);
    return image;
}

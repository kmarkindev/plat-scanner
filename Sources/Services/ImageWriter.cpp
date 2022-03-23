#include "ImageWriter.h"

void ps::ImageWriter::WriteToDisk(std::string_view filename, const ps::Image& image)
{
    stbi_write_png(filename.data(), image.GetWidth(), image.GetHeight(),
        image.GetChannels(), image.GetRawData(), image.GetWidth() * image.GetChannels());
}

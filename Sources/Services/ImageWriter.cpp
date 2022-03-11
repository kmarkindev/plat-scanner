#include "ImageWriter.h"

void ps::ImageWriter::WriteToDisk(std::string_view filename, const ps::Image& image)
{
    stbi_write_png(filename.data(), image.width, image.height,
        image.channels, image.bitmap.data(), image.width * image.channels);
}

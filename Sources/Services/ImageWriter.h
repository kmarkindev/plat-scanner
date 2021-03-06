#pragma once

#include <Models/Image.h>
#include <string_view>
#include <stb_image_write.h>

namespace ps
{
    class ImageWriter
    {
    public:
        void WriteToDisk(std::string_view filename, const ps::Image& image);
    };
}



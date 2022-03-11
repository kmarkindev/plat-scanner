#pragma once

#include <Dto/Image.h>
#include <string_view>
#include <stb/stb_image_write.h>

namespace ps
{
    class ImageWriter
    {
    public:
        void WriteToDisk(std::string_view filename, const ps::Image& image);
    };
}



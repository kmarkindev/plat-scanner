#pragma once

#include <Dto/Image.h>
#include <string_view>
#include <stb/stb_image.h>
#include <stdexcept>

namespace ps
{
    class ImageReader
    {
    public:
        Image ReadFromDisk(std::string_view filename) const;
    };
}



#pragma once

#include <Models/Image.h>
#include <string_view>
#include <stb_image.h>
#include <stdexcept>

namespace ps
{
    class ImageReader
    {
    public:
        [[nodiscard]] Image ReadFromDisk(std::string_view filename) const;
    };
}



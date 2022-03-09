#pragma once

#include <vector>

namespace ps
{
    struct Image
    {
        int width;
        int height;
        int channels;
        std::vector<unsigned char> bitmap;
    };
}
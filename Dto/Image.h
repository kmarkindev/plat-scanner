#pragma once

#include <vector>

namespace ps
{
    struct Image
    {
        int w;
        int h;
        int n;
        std::vector<unsigned char> buffer;
    };
}
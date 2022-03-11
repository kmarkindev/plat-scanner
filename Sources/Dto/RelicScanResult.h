#pragma once

#include "Image.h"
#include <vector>
#include <string>

namespace ps
{
    struct RelicScanResult
    {
        std::vector<std::pair<std::string, ps::Image>> items;
    };
}
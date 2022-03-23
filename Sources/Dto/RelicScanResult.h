#pragma once

#include <Models/Image.h>
#include <vector>
#include <string>

namespace ps
{
    struct RelicScanResult
    {
        struct ItemScanData
        {
            Image scannedImage;
            Image processedImage;
            std::string scannedText;
        };

        std::vector<ItemScanData> items;
    };
}
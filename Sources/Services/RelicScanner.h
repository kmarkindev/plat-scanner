#pragma once

#include <string>
#include <utility>
#include <vector>
#include <Dto/RelicScanResult.h>
#include <Services/ImageScanner.h>
#include <Services/ScreenshotTaker.h>
#include <Services/ImageProcessors/GrayscaleProcessor.h>
#include <Services/ImageProcessors/SharpenProcessor.h>
#include <Services/ImageProcessors/UpscaleProcessor.h>
#include <Services/RelicPartPositionsFinder.h>

namespace ps
{
    class RelicScanner
    {
    public:
        explicit RelicScanner(std::string lang);
        RelicScanResult ScanRelics(int itemsCount, std::pair<int, int> resolution, std::pair<int, int> aspectRatio) const;
    private:
        ImageScanner _imageScanner;
        ScreenshotTaker _screenshotTaker;
        GrayscaleProcessor _grayscaleProcessor;
        SharpenProcessor _sharpenProcessor;
        UpscaleProcessor _upscaleProcessor;
        RelicPartPositionsFinder _relicPartPositionFinder;
    };
}



#include "RelicScanner.h"

ps::RelicScanResult ps::RelicScanner::ScanRelics(int itemsCount, std::pair<int, int> resolution, std::pair<int, int> aspectRatio) const
{
    RelicScanResult result = {
        std::vector<std::pair<std::string, ps::Image>>(itemsCount)
    };

    for(int i = 0; i < itemsCount; ++i)
    {
        auto rect = _relicPartPositionFinder.GetPartPosition(i, {
            itemsCount,
            resolution,
            aspectRatio
        });

        ps::Image image = _screenshotTaker.TakeScreenRect(rect);

        _grayscaleProcessor.Process(image);
        _upscaleProcessor.Process(image);
        _sharpenProcessor.Process(image);

        auto text = _imageScanner.Scan(image);

        result.items[i] = {text, image};
    }

    return result;
}

ps::RelicScanner::RelicScanner(std::string lang)
    : _sharpenProcessor(1.25), _upscaleProcessor(2.5), _imageScanner(lang)
{

}

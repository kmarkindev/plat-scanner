#include "BitmapScanner.h"

ps::BitmapScanner::BitmapScanner(std::string lang)
{
    _api.Init("TessData", lang.data());
}

ps::BitmapScanner::~BitmapScanner()
{
    _api.End();
}

std::string ps::BitmapScanner::Scan(const ps::Image& image) const
{
    _api.SetImage(image.bitmap.data(), image.width, image.height, image.channels, image.width * image.channels);
    return _api.GetUTF8Text();
}
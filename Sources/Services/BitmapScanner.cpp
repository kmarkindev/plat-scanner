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
    int bytesPerRow = image.width * image.channels; //Each component is 8 bit (1 byte)
    _api.SetImage(image.bitmap.data(), image.width, image.height, image.channels, bytesPerRow);
    return _api.GetUTF8Text();
}
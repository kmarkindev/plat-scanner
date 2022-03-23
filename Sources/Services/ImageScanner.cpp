#include "ImageScanner.h"

ps::ImageScanner::ImageScanner(std::string lang)
{
    _api.Init("data/tess/", lang.data());
}

ps::ImageScanner::~ImageScanner()
{
    _api.End();
}

std::string ps::ImageScanner::Scan(const ps::Image& image) const
{
    int bytesPerRow = image.GetWidth() * image.GetChannels(); //Each component is 8 bit (1 byte)
    _api.SetImage(image.GetRawData(), image.GetWidth(), image.GetHeight(), image.GetChannels(), bytesPerRow);
    return _api.GetUTF8Text();
}
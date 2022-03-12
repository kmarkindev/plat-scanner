#include "ImageScanner.h"

ps::ImageScanner::ImageScanner(std::string lang)
{
    _api.Init("Data/Tess/", lang.data());
}

ps::ImageScanner::~ImageScanner()
{
    _api.End();
}

std::string ps::ImageScanner::Scan(const ps::Image& image) const
{
    int bytesPerRow = image.width * image.channels; //Each component is 8 bit (1 byte)
    _api.SetImage(image.bitmap.data(), image.width, image.height, image.channels, bytesPerRow);
    return _api.GetUTF8Text();
}
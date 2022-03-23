#include "Image.h"

ps::Image::Image(int width, int height, int channels, std::vector<unsigned char> bitmap)
{
    SetImage(width, height, channels, std::move(bitmap));
}

void ps::Image::SetImage(int width, int height, int channels, std::vector<unsigned char> bitmap)
{
    CheckSize(width, height);
    CheckChannels(channels);

    _width = width;
    _height = height;
    _channels = channels;
    _bitmap = std::move(bitmap);
}

int ps::Image::GetWidth() const
{
    return _width;
}

int ps::Image::GetHeight() const
{
    return _height;
}

int ps::Image::GetChannels() const
{
    return _channels;
}

std::vector<unsigned char> ps::Image::GetBitmap() const
{
    return _bitmap;
}

constexpr void ps::Image::CheckSize(int width, int height) const
{
    if(width <= 0 || height <= 0)
        throw std::invalid_argument("Height or Width can't be less or equal to 0");
}

constexpr void ps::Image::CheckChannels(int channels) const
{
    if(channels <= 0 || channels > 4)
        throw std::invalid_argument("Channels count can't be less or equal to 0 or more than 4");
}

const std::vector<unsigned char>& ps::Image::GetBitmapRef() const
{
    return _bitmap;
}

const unsigned char* ps::Image::GetRawData() const
{
    return _bitmap.data();
}

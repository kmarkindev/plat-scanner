#pragma once

#include <vector>
#include <stdexcept>

namespace ps
{
    class Image
    {
    public:
        Image(int width, int height, int channels, std::vector<unsigned char> bitmap);
        void SetImage(int width, int height, int channels, std::vector<unsigned char> bitmap);
        [[nodiscard]] int GetWidth() const;
        [[nodiscard]] int GetHeight() const;
        [[nodiscard]] int GetChannels() const;
        [[nodiscard]] std::vector<unsigned char> GetBitmap() const;
        [[nodiscard]] const std::vector<unsigned char>& GetBitmapRef() const;
        [[nodiscard]] const unsigned char* GetRawData() const;
    private:
        int _width;
        int _height;
        int _channels;
        std::vector<unsigned char> _bitmap;

        void constexpr CheckSize(int width, int height) const;
        void constexpr CheckChannels(int channels) const;
    };
}
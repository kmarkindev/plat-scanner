#pragma once

#include <string>
#include <Models/Image.h>
#include <tesseract/baseapi.h>

namespace ps
{
    class ImageScanner
    {
    public:
        explicit ImageScanner(std::string lang);
        ~ImageScanner();
        [[nodiscard]] std::string Scan(const Image& image) const;
    private:
        mutable tesseract::TessBaseAPI _api;
    };
}



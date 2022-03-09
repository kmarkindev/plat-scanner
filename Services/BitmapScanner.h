#pragma once

#include <string>
#include <Image.h>
#include <ScanOptions.h>
#include <tesseract/baseapi.h>

namespace ps
{
    class BitmapScanner
    {
    public:
        BitmapScanner(std::string lang);
        ~BitmapScanner();
        [[nodiscard]] std::string Scan(const Image& image) const;
    private:
        mutable tesseract::TessBaseAPI _api;
    };
}



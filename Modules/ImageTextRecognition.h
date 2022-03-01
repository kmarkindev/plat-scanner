#pragma once

#include <string>
#include <Image.h>
#include <tesseract/baseapi.h>

namespace ps
{
    class ImageTextRecognition
    {
    public:

        explicit ImageTextRecognition(std::string lang);
        ~ImageTextRecognition();

        [[nodiscard]] std::string RecognizeTextFromImage(const Image& image) const;

    private:

        mutable tesseract::TessBaseAPI _api;

    };
}




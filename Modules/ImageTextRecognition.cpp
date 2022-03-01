#include "ImageTextRecognition.h"

ps::ImageTextRecognition::ImageTextRecognition(std::string lang)
{
    _api.Init("TessData", lang.data());
    //_api.SetVariable("tessedit_char_whitelist", "йцукенгшщзхъэждлорпавыфячсмитьбю:");
}

ps::ImageTextRecognition::~ImageTextRecognition()
{
    _api.End();
}

std::string ps::ImageTextRecognition::RecognizeTextFromImage(const Image& image) const
{
    _api.SetImage(image.buffer.data(), image.w, image.h, image.n, image.w * image.n);
    return _api.GetUTF8Text();
}

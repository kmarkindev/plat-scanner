#include "ScreenshotTaker.h"

ps::Image ps::ScreenshotTaker::TakeWholeScreen() const
{
    wxCoord screenWidth, screenHeight;
    wxScreenDC dcScreen;
    dcScreen.GetSize(&screenWidth, &screenHeight);

    return TakeScreenRect({0, 0, screenWidth, screenHeight});
}

ps::Image ps::ScreenshotTaker::TakeScreenRect(glm::ivec4 rect) const
{
    if(rect.x < 0 || rect.y < 0)
        throw std::invalid_argument("X and Y can't be less than 0");

    if(rect.z <= 0 || rect.w <= 0)
        throw std::invalid_argument("Width and Height can't be less than or equal to 0");

    wxBitmap screenshot(rect.z, rect.w, -1);

    wxScreenDC dcScreen;
    wxMemoryDC memDC;
    memDC.SelectObject(screenshot);
    memDC.Blit(0, 0, rect.z, rect.w, &dcScreen, rect.x, rect.y);
    memDC.SelectObject(wxNullBitmap);

    auto image = screenshot.ConvertToImage();

    // Make sure there is no alpha channel
    if(image.HasAlpha())
        image.ClearAlpha();

    auto width = image.GetWidth();
    auto height = image.GetHeight();
    auto channels = 3; // wxImage always has 3 channels (RBG) at this point

    return {
        width,
        height,
        channels,
        std::vector<unsigned char>(image.GetData(), image.GetData() + width * height * channels)
    };
}

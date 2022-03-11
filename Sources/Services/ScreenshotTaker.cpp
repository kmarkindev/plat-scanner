#include "ScreenshotTaker.h"

ps::Image ps::ScreenshotTaker::TakeWholeScreen() const
{
    wxScreenDC dcScreen;

    wxCoord screenWidth, screenHeight;
    dcScreen.GetSize(&screenWidth, &screenHeight);

    wxBitmap screenshot(screenWidth, screenHeight, -1);

    wxMemoryDC memDC;
    memDC.SelectObject(screenshot);
    memDC.Blit(0, 0, screenWidth, screenHeight, &dcScreen, 0, 0);
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

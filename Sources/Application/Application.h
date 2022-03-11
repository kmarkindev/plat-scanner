#pragma once

//#include <stb/stb_image.h>
//#include <Services/ScreenshotTaker.h>
//#include <Services/ImageWriter.h>
//#include <Services/ImageReader.h>
//#include <Services/ImageScanner.h>
//#include <Services/ImageProcessors/GrayscaleProcessor.h>
//#include <Services/ImageProcessors/UpscaleProcessor.h>
//#include <Services/ImageProcessors/SharpenProcessor.h>
//#include <Services/RelicPartPositionsFinder.h>
//#include <vector>
//#include <iostream>

#include <wx/wx.h>
#include <Application/Windows/MainWindow.h>

namespace ps
{
    class Application : public wxApp
    {
    protected:
        bool OnInit() override;
    };
}
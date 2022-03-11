#pragma once

#include <wx/wx.h>
#include <stb/stb_image.h>
#include <Services/ImageWriter.h>
#include <Services/ImageReader.h>
#include <Services/ImageScanner.h>
#include <Services/ImageProcessors/GrayscaleProcessor.h>
#include <Services/ImageProcessors/UpscaleProcessor.h>
#include <Services/ImageProcessors/SharpenProcessor.h>
#include <vector>
#include <iostream>

namespace ps
{
    class Application : public wxApp
    {
    protected:
        bool OnInit() override;
    };
}
#pragma once

#include <wx/wx.h>
#include <stb/stb_image.h>
#include <stb/stb_image_write.h>
#include <Services/BitmapScanner.h>
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
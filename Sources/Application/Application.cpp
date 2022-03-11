#include "Application.h"

bool ps::Application::OnInit()
{
	std::setlocale(LC_ALL, "en_US.UTF-8");
    ps::ImageScanner api("rus");

    ps::RelicPartPositionsFinder positionsFinder;
    auto rect = positionsFinder.GetPartPosition(0, {
        3,
        {1920, 1080},
        {16, 9}
    });

    ps::ScreenshotTaker screenshotTaker;
    ps::Image img = screenshotTaker.TakeScreenRect(rect);

//    ps::ImageReader imgReader;
//    ps::Image img = imgReader.ReadFromDisk("cropped4.png");

    ps::GrayscaleProcessor grayscaleProcessor;
    grayscaleProcessor.Process(img);

    ps::UpscaleProcessor upscaleProcessor(2.0);
    upscaleProcessor.Process(img);

    ps::SharpenProcessor sharpenProcessor(1.25);
    sharpenProcessor.Process(img);

    auto result = api.Scan(img);
    wxMessageBox(wxString::FromUTF8(result));

    ps::ImageWriter imgWriter;
    imgWriter.WriteToDisk("output.png", img);

	return false;
}
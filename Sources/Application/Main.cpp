#include <stb/stb_image.h>
#include <stb/stb_image_write.h>
#include <Services/BitmapScanner.h>
#include <Services/ImageProcessors/GrayscaleProcessor.h>
#include <Services/ImageProcessors/UpscaleProcessor.h>
#include <Services/ImageProcessors/SharpenProcessor.h>
#include <vector>
#include <iostream>

int main()
{
    std::setlocale(LC_ALL, "en_US.UTF-8");
    ps::BitmapScanner api("rus");

    int x, y, n;
    unsigned char* buffer = stbi_load("cropped4.png", &x, &y, &n, 0);

    if(!buffer)
        throw std::runtime_error("Can't load image");

    int imageLen = x * y * n;

    ps::Image img = {x,y,n,std::vector<unsigned char>(buffer, buffer + imageLen)};

    ps::GrayscaleProcessor grayscaleProcessor;
    grayscaleProcessor.Process(img);

    ps::UpscaleProcessor upscaleProcessor(2.0);
    upscaleProcessor.Process(img);

    ps::SharpenProcessor sharpenProcessor(75.0);
    sharpenProcessor.Process(img);

    auto result = api.Scan(img);
    std::cout << result << std::endl;

    stbi_write_png("output.png", img.width, img.height, img.channels, img.bitmap.data(), img.width * img.channels);

    stbi_image_free(buffer);

    return 0;
}
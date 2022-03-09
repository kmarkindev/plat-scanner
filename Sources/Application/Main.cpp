#include <stb/stb_image.h>
#include <stb/stb_image_write.h>
#include <Services/BitmapScanner.h>
#include <Services/ImageProcessors/GrayscaleProcessor.h>
#include <vector>
#include <iostream>

int main()
{
    std::setlocale(LC_ALL, "en_US.UTF-8");
    ps::BitmapScanner api("rus");

    int x, y, n;
    unsigned char* buffer = stbi_load("cropped.png", &x, &y, &n, 0);
    int imageLen = x * y * n;

    ps::Image img = {x,y,n,std::vector<unsigned char>(buffer, buffer + imageLen)};

    ps::GrayscaleProcessor processor;
    processor.Process(img);

    auto result = api.Scan(img);
    std::cout << result << std::endl;

    //stbi_write_png("output.png", img.width, img.height, img.channels, img.bitmap.data(), img.width * img.channels);

    stbi_image_free(buffer);

    return 0;
}
#include <stb_image/stb_image.h>
#include <BitmapScanner.h>
#include <vector>
#include <iostream>

int main()
{
    std::setlocale(LC_ALL, "en_US.UTF-8");
    ps::BitmapScanner api("rus");

    int x, y, n;
    unsigned char* buffer = stbi_load("cropped_greyscaled.png", &x, &y, &n, 0);
    int imageLen = x * y * n;

    std::vector<unsigned char> image(buffer, buffer + imageLen);

    auto result = api.Scan({x,y,n,image});

    std::cout << result << std::endl;

    stbi_image_free(buffer);

    return 0;
}
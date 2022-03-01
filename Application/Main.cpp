#include <stb_image/stb_image.h>
#include <ImageTextRecognition.h>
#include <vector>
#include <iostream>

int main()
{
    std::setlocale(LC_ALL, "en_US.UTF-8");
    ps::ImageTextRecognition api("rus");

    int x, y, n;
    unsigned char* buffer = stbi_load("im1_4_3.png", &x, &y, &n, 0);
    int imageLen = x * y * n;

    std::vector<unsigned char> image(buffer, buffer + imageLen);

    auto result = api.RecognizeTextFromImage({
        x,
        y,
        n,
        image
    });

    std::cout << result << std::endl;

    stbi_image_free(buffer);

    return 0;
}
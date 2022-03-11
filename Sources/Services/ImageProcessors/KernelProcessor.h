#pragma once

#include "IImageProcessor.h"
#include <type_traits>

namespace ps
{
    //MatrixT should be one of the glm matrices! IDK how to test it using concepts
    //Doesn't support kernels without a center (like 4x4). TODO: implement this support if needed.
    template<typename MatrixT> requires std::is_arithmetic_v<typename MatrixT::value_type>
    class KernelProcessor : public IImageProcessor
    {
    public:
        explicit KernelProcessor(MatrixT kernel)
            : _kernel(kernel)
        {
            static_assert(_colsCount % 2 != 0 || _rowsCount % 2 != 0,
                "KernelProcessor doesn't support matrices without a center (2x2, 4x4, 5x6 etc.)");
        }

        void Process(Image& image) const override
        {
            std::vector<unsigned char> newBitmap(image.width * image.height * image.channels);

            // Iterate through each pixel
            for(size_t yPixel = 0; yPixel < image.height; ++yPixel)
            {
                for(size_t xPixel = 0; xPixel < image.width; ++xPixel)
                {
                    size_t centerPixelIndex = yPixel * image.width + xPixel;

                    size_t topLeftPixelX = xPixel - _matrixCenter.first;
                    size_t topLeftPixelY = yPixel - _matrixCenter.second;

                    // Calculate kernel for each channel of the pixel
                    for(size_t channel = 0; channel < image.channels; ++channel)
                    {
                        float common = 0;
                        for(LenT i = 0; i < _rowsCount; ++i)
                        {
                            for(LenT j = 0; j < _colsCount; ++j)
                            {
                                size_t currentPixelX = topLeftPixelX + i;
                                size_t currentPixelY = topLeftPixelY + j;

                                // All out of bounds pixels are equal to 0
                                if(currentPixelX < 0 || currentPixelX > image.width - 1)
                                    continue;
                                if(currentPixelY < 0 || currentPixelY > image.height - 1)
                                    continue;

                                size_t currentPixelIndex = GetPixelIndex(currentPixelX,
                                    currentPixelY, image.width);
                                size_t currentCharIndex = currentPixelIndex * image.channels + channel;

                                common += static_cast<float>(image.bitmap[currentCharIndex]) * _kernel[j][i];
                            }
                        }

                        size_t centerCharIndex = centerPixelIndex * image.channels + channel;
                        newBitmap[centerCharIndex] = clip(common);
                    }

                }
            }

            image.bitmap = newBitmap;
        }

    private:

        using LenT = typename MatrixT::length_type;

        static constexpr LenT _rowsCount = MatrixT::row_type::length();
        static constexpr LenT _colsCount = MatrixT::col_type::length();

        static constexpr LenT GetArrayMiddle(LenT size)
        {
            return (size / 2) - 1;
        }

        static constexpr std::pair<LenT, LenT> _matrixCenter =
            std::make_pair(GetArrayMiddle(_rowsCount), GetArrayMiddle(_colsCount));

        MatrixT _kernel;

        size_t GetPixelIndex(size_t x, size_t y, size_t width) const
        {
            return y * width + x;
        }

        unsigned char clip(float val) const
        {
            if(val > 255.0f)
                return 255;

            if(val < 0.0f)
                return 0;

            return static_cast<unsigned char>(val);
        }
    };
}



#include "RelicPartPositionsFinder.h"

glm::ivec4 ps::RelicPartPositionsFinder::GetPartPosition(int partNumber, ps::RelicFinderParams params) const
{
    if(partNumber < 0 || partNumber > 3)
        throw std::invalid_argument("partIndex can't be less than 0 or more than 3");

    if(params.partsCount <= 1 || params.partsCount > 4)
        throw std::invalid_argument("Parts count value can't be less than or equal to 1 and more than 4");

    //TODO: need to figure out how to calculate it
    //For now, hardcoded values are fine

    if(params.aspectRatio.first != 16 || params.aspectRatio.second != 9)
        throw std::invalid_argument("Currently, aspect ratio other than 16/9 is not supported");

    if(params.resolution.first != 1920 || params.resolution.second != 1080)
        throw std::invalid_argument("Currently, resolution other than 1920x1080 is not supported");

    glm::ivec4 result = {0, 0, 0, 0};

    constexpr int partW = 230;
    constexpr int partH = 48;
    constexpr int partY = 410;

    switch(params.partsCount)
    {
    case 2: //TODO: correct x values
        switch(partNumber)
        {
        case 0:
            result = {605, partY, partW, partH};
            break;
        case 1:
            result = {605, partY, partW, partH};
            break;
        default:
            throw std::invalid_argument("Wrong part number specified for given parts count");
        }
        break;
    case 3:
        switch(partNumber)
        {
        case 0:
            result = {605, partY, partW, partH};
            break;
        case 1:
            result = {845, partY, partW, partH};
            break;
        case 2:
            result = {1090, partY, partW, partH};
            break;
        default:
            throw std::invalid_argument("Wrong part number specified for given parts count");
        }
        break;
    case 4:
        switch(partNumber)
        {
        case 0:
            result = {480, partY, partW, partH};
            break;
        case 1:
            result = {725, partY, partW, partH};
            break;
        case 2:
            result = {965, partY, partW, partH};
            break;
        case 3:
            result = {1205, partY, partW, partH};
            break;
        default:
            throw std::invalid_argument("Wrong part number specified for given parts count");
        }
        break;
    default:
        throw std::runtime_error("This should not happen. Parts count can be only 2,3,4 at this point");
    }

    return result;
}

std::vector<glm::ivec4> ps::RelicPartPositionsFinder::GetPartsPositions(ps::RelicFinderParams params) const
{
    std::vector<glm::ivec4> result(params.partsCount);

    for(int i = 0; i < params.partsCount; ++i)
    {
        result[0] = GetPartPosition(i, params);
    }

    return result;
}

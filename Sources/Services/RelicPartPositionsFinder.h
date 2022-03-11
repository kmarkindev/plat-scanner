#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <Dto/RelicFinderParams.h>
#include <stdexcept>

namespace ps
{
    class RelicPartPositionsFinder
    {
    public:
        glm::ivec4 GetPartPosition(int partNumber, RelicFinderParams params) const;
        std::vector<glm::ivec4> GetPartsPositions(RelicFinderParams params) const;
    };
}



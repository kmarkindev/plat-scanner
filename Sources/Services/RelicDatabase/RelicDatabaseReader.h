#pragma once

#include <Models/RelicItemsDatabase.h>
#include <string>
#include <fstream>
#include <stdexcept>

namespace ps
{
    class RelicDatabaseReader
    {
    public:
        RelicItemsDatabase ReadDatabaseFromDisk(const std::string& filename);
    private:
        std::string ReadString(std::ifstream& fs);
    };
}



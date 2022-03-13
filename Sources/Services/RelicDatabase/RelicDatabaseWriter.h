#pragma once

#include <Dto/RelicItemsDatabase.h>
#include <fstream>
#include <string>
#include <filesystem>
#include <stdexcept>

namespace ps
{
    class RelicDatabaseWriter
    {
    public:
        void WriteDatabaseToDisk(const RelicItemsDatabase& db, std::string filename);
    };
}



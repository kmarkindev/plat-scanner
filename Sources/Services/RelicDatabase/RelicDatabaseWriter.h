#pragma once

#include <Models/RelicItemsDatabase.h>
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
    private:
        void writeString(const std::string& str, std::ofstream& fs);
    };
}



#include "RelicDatabaseReader.h"

ps::RelicItemsDatabase ps::RelicDatabaseReader::ReadDatabaseFromDisk(const std::string& filename)
{
    std::ifstream fstream(filename);

    if(!fstream.is_open())
        throw std::runtime_error("Cannot open stream using given filename");

    int size = 0;
    fstream.read(reinterpret_cast<char*>(&size), sizeof(size));

    RelicItemsDatabase result = {
        std::vector<RelicItem>(size)
    };

    fstream.read(reinterpret_cast<char*>(result.items.data()), size * sizeof(decltype(result.items)::value_type));

    return result;
}
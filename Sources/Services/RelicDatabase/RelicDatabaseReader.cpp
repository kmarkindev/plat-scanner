#include "RelicDatabaseReader.h"

ps::RelicItemsDatabase ps::RelicDatabaseReader::ReadDatabaseFromDisk(const std::string& filename)
{
    std::ifstream fstream(filename, std::ios::binary | std::ios::in);

    if(!fstream.is_open())
        throw std::runtime_error("Cannot open stream using given filename");

    int size = 0;
    fstream.read(reinterpret_cast<char*>(&size), sizeof(size));

    std::vector<RelicItem> items(size);

    for(auto& item : items)
    {
        auto urlName = ReadString(fstream);
        auto name = ReadString(fstream);
        item.SetItem(name, urlName);
    }

    return RelicItemsDatabase(std::move(items));
}

std::string ps::RelicDatabaseReader::ReadString(std::ifstream& fs)
{
    int strSize = 0;
    fs.read(reinterpret_cast<char*>(&strSize), sizeof(strSize));
    std::string result(strSize, ' ');
    fs.read(reinterpret_cast<char*>(result.data()), result.size());
    return result;
}

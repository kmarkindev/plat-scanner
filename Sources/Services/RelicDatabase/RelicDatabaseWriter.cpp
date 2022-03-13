#include "RelicDatabaseWriter.h"

void ps::RelicDatabaseWriter::WriteDatabaseToDisk(const ps::RelicItemsDatabase& db, std::string filename)
{
    std::filesystem::path path(filename);
    path = path.parent_path();

    if(!std::filesystem::exists(path))
        std::filesystem::create_directories(path);

    std::ofstream fstream(filename, std::ios::binary | std::ios::out);

    if(!fstream.is_open())
        throw std::runtime_error("Cannot open stream using given filename");

    auto size = db.items.size();
    fstream.write(reinterpret_cast<char*>(&size), sizeof(size));

    for(const auto& item : db.items)
    {
        writeString(item.url_name, fstream);
        writeString(item.name, fstream);
        writeString(item.cleanName, fstream);
    }
}

void ps::RelicDatabaseWriter::writeString(const std::string& str, std::ofstream& fs)
{
    int strSize = static_cast<int>(str.size());
    fs.write(reinterpret_cast<char*>(&strSize), sizeof(strSize));
    fs.write(reinterpret_cast<const char*>(str.data()), str.size());
}
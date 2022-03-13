#include "RelicDatabaseWriter.h"

void ps::RelicDatabaseWriter::WriteDatabaseToDisk(const ps::RelicItemsDatabase& db, std::string filename)
{
    std::filesystem::path path(filename);
    path = path.parent_path();

    if(!std::filesystem::exists(path))
        std::filesystem::create_directories(path);

    std::ofstream fstream(filename);

    if(!fstream.is_open())
        throw std::runtime_error("Cannot open stream using given filename");

    auto size = db.items.size();
    fstream.write(reinterpret_cast<char*>(&size), sizeof(size));

    fstream.write(reinterpret_cast<const char*>(db.items.data()),
        db.items.size() * sizeof(decltype(db.items)::value_type));

    fstream.flush();
}
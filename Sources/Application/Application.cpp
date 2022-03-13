#include "Application.h"

bool ps::Application::OnInit()
{
    wxImage::AddHandler(new wxPNGHandler());

    std::filesystem::path pathToDb("Tmp/Db.rdb");

    if(!std::filesystem::exists(pathToDb))
    {
        RelicDatabaseCreator creator("ru", "pc");
        RelicDatabaseWriter writer;
        auto db = creator.CreateItemsDatabaseUsingWfApi();
        writer.WriteDatabaseToDisk(db, "Tmp/Db.rdb");

        auto window = new MainWindow(db);
        window->Show();
    }
    else
    {
        RelicDatabaseReader reader;
        auto db = reader.ReadDatabaseFromDisk("Tmp/Db.rdb");

        auto window = new MainWindow(db);
        window->Show();
    }

	return true;
}
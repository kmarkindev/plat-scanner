#include "Application.h"

bool ps::Application::OnInit()
{
    wxImage::AddHandler(new wxPNGHandler());

    std::filesystem::path pathToDb("Tmp/Db.rdb");

    if(!std::filesystem::exists(pathToDb))
    {
        RelicDatabaseCreator creator("ru", "pc");
        RelicDatabaseWriter writer;
        writer.WriteDatabaseToDisk(creator.CreateItemsDatabaseUsingWfApi(), "Tmp/Db.rdb");
    }

    auto window = new MainWindow();
    window->Show();

	return true;
}
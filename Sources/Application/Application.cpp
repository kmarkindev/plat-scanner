#include "Application.h"

bool ps::Application::OnInit() try
{
    wxImage::AddHandler(new wxPNGHandler());

    std::filesystem::path pathToDb("tmp/db.rdb");

    if(!std::filesystem::exists(pathToDb))
    {
        RelicDatabaseCreator creator("ru", "pc");
        RelicDatabaseWriter writer;
        auto db = creator.CreateItemsDatabaseUsingWfApi();
        writer.WriteDatabaseToDisk(db, "tmp/db.rdb");

        auto window = new MainWindow(db);
        window->Show();
    }
    else
    {
        RelicDatabaseReader reader;
        auto db = reader.ReadDatabaseFromDisk("tmp/db.rdb");

        auto window = new MainWindow(db);
        window->Show();
    }

	return true;
}
catch(std::exception& ex)
{
    wxMessageBox(wxString::FromUTF8(ex.what()), "Init Exception", wxICON_ERROR);
    return false;
}
catch(...)
{
    wxMessageBox(wxString::FromUTF8("Unhandled exception of non std::exception type in Application::OnInit"),
        "Init Exception", wxICON_ERROR);
    return false;
}
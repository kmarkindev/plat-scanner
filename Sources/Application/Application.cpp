#include "Application.h"

bool ps::Application::OnInit()
{
    wxImage::AddHandler(new wxPNGHandler());

    auto window = new MainWindow();
    window->Show();

	return true;
}
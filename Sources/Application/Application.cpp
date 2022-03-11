#include "Application.h"

bool ps::Application::OnInit()
{
    auto window = new MainWindow();
    window->Show();

	return true;
}
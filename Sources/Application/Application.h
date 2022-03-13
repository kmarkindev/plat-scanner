#pragma once

#include <wx/wx.h>
#include <Application/Windows/MainWindow.h>
#include <Services/RelicDatabase/RelicDatabaseCreator.h>
#include <Services/RelicDatabase/RelicDatabaseWriter.h>
#include <Services/RelicDatabase/RelicDatabaseReader.h>
#include <filesystem>

namespace ps
{
    class Application : public wxApp
    {
    protected:
        bool OnInit() override;
    };
}
// MainApp.cpp : Defines the entry point for the application.
//

#include "pch.h"
#include "SettingsWindow.h"

wxIMPLEMENT_APP(AppStart);

AppStart::AppStart()
{
	this->mainWindow = new SettingsWindow("Structured Test setup", wxPoint(50, 50), 
		wxSize(800, 600));
}

AppStart::~AppStart() {}

bool AppStart::OnInit()
{
	mainWindow->Show();
	return true;
}

#pragma once
#include "pch.h"
#include "resource.h"
#include "SettingsWindow.h"


class AppStart : public wxApp
{
public:
	AppStart();
	~AppStart() override;
	bool OnInit() override;
private:
	SettingsWindow* mainWindow;
};

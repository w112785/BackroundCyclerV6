// SettingsWindow.h: This header file contains the SettingsWindow class and AppStart Class
// I include both classes in this header to cut down on the total number of files in the
// source code. Also AppStart is always a short class for me anyway.
#pragma once
#include "pch.h"

enum WindowId
{
	MAINWINDOW = wxID_HIGHEST + 1,
	MW_TOOLBAR,
	MW_LISTBOOK,
};

enum ToolBarId
{
	MW_TB_START = WindowId::MAINWINDOW * 1000, //just useing this to start the ID's for Toolbar Items
	TB_CHANGEBG,
	TB_ABOUT,
	TB_QUIT,
	TB_CLOSE,

};

// I normally call the main "Frame" of a program a window.
class SettingsWindow : public wxFrame
{
public:
	SettingsWindow(const wxString& title, const wxPoint& pos, const wxSize& size);
	~SettingsWindow() override;
private:
	void MenuBarSetup();
protected:
	void OnExit(wxCommandEvent& event);

protected:
	wxToolBarToolBase* TB_ChangeBackground;
	wxToolBarToolBase* TB_CloseWindow;
	wxToolBarToolBase* TB_QuitProgram;
	wxListbook* m_listbook3;
private:
	void OnCloseWindow(wxCloseEvent& event);
	wxToolBar* toolBar;

};

// declaired in MainApp.cpp This can be confusing if you use Intellisense to auto create 
// the definitions. 
class AppStart : public wxApp
{
public:
	AppStart();
	~AppStart() override;
	bool OnInit() override;
private:
	SettingsWindow* mainWindow;
};

// Gives me AppStart& wxGetApp();
wxDECLARE_APP(AppStart);

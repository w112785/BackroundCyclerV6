#include "pch.h"
#include "SettingsWindow.h"

wxBEGIN_EVENT_TABLE(SettingsWindow, wxFrame)
	EVT_MENU(ID_Hello, SettingsWindow::OnHello)
	EVT_MENU(wxID_EXIT, SettingsWindow::OnExit)
	EVT_MENU(wxID_ABOUT, SettingsWindow::OnAbout)
wxEND_EVENT_TABLE()

SettingsWindow::SettingsWindow(const wxString& title, const wxPoint& pos, const wxSize& size)
		: wxFrame(nullptr, wxID_ANY, title, pos, size) 
{
	wxMenu* menuFile = new wxMenu;
	menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
		"Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);
	wxMenu* menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);
	wxMenuBar* menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);
	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");
}

SettingsWindow::~SettingsWindow() {}

void SettingsWindow::OnExit(wxCommandEvent& event)
{
	Close(true);
}

void SettingsWindow::OnAbout(wxCommandEvent& event)
{
	wxMessageBox(wxT("This is a wxWidgets' Hello world sample"),
		wxT("About Hello World"), wxOK | wxICON_INFORMATION);
}

void SettingsWindow::OnHello(wxCommandEvent& event)
{
	wxMessageBox(wxT("Hello World from wxWidgets!"),
		wxT("Backround Cycler V6 C++ edition"), wxOK | wxICON_EXCLAMATION);
}
